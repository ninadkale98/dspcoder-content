# First Missing Positive

### **First Missing Positive**

***Big O:*** O(n) speed, O(1) space
```
Tips: 

Hashmap. 
```
```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> umap;
        int max_v = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                umap[nums[i]] = 1;
                max_v = max(max_v, nums[i]);
            }
        }
        
        for (int i = 1; i < max_v; i++) {
            if (umap.find(i) == umap.end())
                return i;
        }
        
        return max_v+1;
    }
};
```