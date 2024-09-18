# Sort Colors


### **Sort Colors**

***Big O:*** O(n) speed (one pass), O(1) space
```
Tips: 

The idea of solution is to move curr pointer along the array, if nums[curr] = 0 - swap it with nums[p0], if nums[curr] = 2 - swap it with nums[p2].
```
```c++
class Solution {

public: 
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1, i = 0;

        while (i <= hi) {
            if      (nums[i] == 0) swap(nums, lo++, i++);
            else if (nums[i] == 2) swap(nums, i, hi--);
            else if (nums[i] == 1) i++;
        }
    }

    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

};
```