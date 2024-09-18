# Maximum Swap


### **Maximum Swap**

***Big O:*** O(n) speed, O(1) space
```
Tips: 

Greedy. 
```
```c++
class Solution {
public:
    int maximumSwap(int num) {
        string num_str = to_string(num);
        int n = num_str.size();
        int max_val = -1, max_i = -1;
        int left = -1, right = -1;
        
        for (int i = n - 1; i >= 0; i--) {
            if (num_str[i] > max_val) {
                max_val = num_str[i];
                max_i = i;
            } else if (num_str[i] < max_val) {
                left = i;
                right = max_i;
            }
        }
       
        if (left == -1) return num;
        char c = num_str[left];
        num_str[left] = num_str[right];
        num_str[right] = c;
        return stoi(num_str);
    }
};
```