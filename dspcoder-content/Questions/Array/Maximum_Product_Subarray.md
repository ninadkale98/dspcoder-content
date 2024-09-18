# Maximum Product Subarray


### **Maximum Product Subarray**

***Big O:*** O(n) speed, O(1) space
```
Tips: 

Dynamic Programming. While going through numbers in nums, we will have to keep track of the maximum product up to that number (we will call max_so_far) and minimum product up to that number (we will call min_so_far). The reason behind keeping track of max_so_far is to keep track of the accumulated product of positive numbers. The reason behind keeping track of min_so_far is to properly handle negative numbers.
```
```c++
class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
         if (nums.size() == 0) return 0;

        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];
            int temp_max = max(curr, max(max_so_far * curr, min_so_far * curr));
            min_so_far = min(curr, min(max_so_far * curr, min_so_far * curr));

            max_so_far = temp_max;

            result = max(max_so_far, result);
        }

        return result;
    }
};
```