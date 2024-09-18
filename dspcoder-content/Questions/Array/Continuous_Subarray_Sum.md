# Continuous Subarray Sum


### **Continuous Subarray Sum**

***Big O:*** O(n) speed, O(n) space
```
Tips: 

a%k = x
b%k = x
(a - b) %k = x -x = 0
here a - b = the sum between i and j.
```
```c++
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2)
            return false;
    
        unordered_map<int, int> mp;
    
        // <0,-1> can allow it to return true when the runningSum%k=0,
        mp[0]=-1;
        
        int runningSum=0;
        for(int i=0;i<nums.size();i++) {
            runningSum+=nums[i];
            
            if(k!=0) 
                runningSum = runningSum%k;
            
            //check if the runningsum already exists in the hashmap
            if(mp.find(runningSum)!=mp.end()) {
                //if it exists, then the current location minus the previous location must be greater than1
                if(i-mp[runningSum]>1)
                    return true;
            }
            else
                mp[runningSum]=i; 
        }
        return false;
    }
};
```



### **Continuous Subarray Sum**

***Big O:*** O(n) speed, O(1) space
```
Tips: 

Iterate and check.
```
```c++
class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &A) {
        // write your code here
        int start = 0;
        int end = start;
        int sum = 0;
        int ans = INT_MIN;
        vector<int> ret(2, 0);

        if (A.size() < 2)
            return {0, 0};
        
        for (int i = 0; i < A.size(); i++) {
            if (sum < 0) {
                sum = A[i];
                start = end = i;
            } else {
                sum += A[i];
                end = i;
            }

            if (sum > ans) {
                ret[0] = start;
                ret[1] = end;
                ans = sum;
            }
        }

        return ret;
    }
};
```