
### **Running Sum of 1d Array**

***Big O:*** O(n) speed, O(1) space
```
Tips: 

Use the sum of previous item.
```
```c++
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> running_sum(nums.size(), 0);
        running_sum[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            running_sum[i] = nums[i] + running_sum[i-1];
        }
        
        return running_sum;
    }
};