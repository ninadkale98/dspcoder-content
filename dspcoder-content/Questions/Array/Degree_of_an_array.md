# Degree of an array


### **Degree of an array**

***Big O:*** O(n) speed, O(n) space
```
Tips: 

Hash map to record the number frequency and another map to record the postions of each number. when encounter a number with the same degree, calculate the length and take the minium value of them.
```
```c++
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
    map<int, int> freq;
    map<int, vector<int>> pos;
    int mx = INT_MIN;
    
    /*
    get frequency of each number in array
    get highest degree
    note the positions of frequencies
    */    
    for(int i = 0; i < nums.size(); i++)
    {
        mx = max(mx, ++freq[nums[i]]);        
        pos[nums[i]].push_back(i);
    }
       
    //get shortest distance
    int dist = INT_MAX;
    for(auto num : nums)
    {
        if(freq[num] == mx)            
            dist = min(dist, pos[num].back() - pos[num].front());         
    }
    
    return dist + 1;
        
    }
};
```