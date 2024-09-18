# Random Pick with Weight



### **Random Pick with Weight**

***Big O:*** O(log(n)) speed, O(n) space
```
Tips: 

Prefix Sums with Binary Search.
```
```c++
class Solution {
    vector<int> sums;
    
public:
    Solution(vector<int>& w) {
        sums = vector<int>(w.size(), 0);
        sums[0] = w[0];
        
        for (int i = 1; i < sums.size(); i++) {
            sums[i] = w[i] + sums[i-1];
        }
    }
    
    int pickIndex() {
        int w_index = rand()%(sums.back());
        
        int st = 0;
        int end = sums.size() - 1;
        int ret;
        
        while (st < end) {
            int mid = st + (end-st)/2;
            
            if (sums[mid] <= w_index) {
                st = mid + 1;
            } else{
                end = mid;
            }
        }
        
        return st;
    }
};

```