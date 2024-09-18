
### **Decode String**

***Big O:*** 

Time Complexity: O(maxK⋅n), where maxK is the maximum value of kk and nn is the length of a given string ss. We traverse a string of size nn and iterate kk times to decode each pattern of form k[string]. This gives us worst case time complexity as O(maxK⋅n).

Space Complexity: O(m+n), where mm is the number of letters(a-z) and nn is the number of digits(0-9) in string ss. In worst case, the maximum size of stringStack and countStack could be mm and nn respectively.
```
Tips: 

Use stack to store pair<int, int>(frequency, string). (Equivalent of using two stacks).
```
```c++
class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> decode_stk;
        string ret = "";
        
        int number = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                string encode_str = "";
                decode_stk.push(make_pair(number, encode_str));
                number = 0;
            } else if (s[i] == ']') {
                pair<int, string> tmp = decode_stk.top(); 
                decode_stk.pop();
                
                string copy = tmp.second;
                while(--tmp.first) {
                    copy += tmp.second;
                }
                
                if (decode_stk.empty()) {
                    ret += copy;
                } else {
                    tmp = decode_stk.top();
                    decode_stk.pop();
                    tmp.second += copy;
                    decode_stk.push(tmp);
                }
            } else if (isalpha(s[i])) {
                if (decode_stk.empty()) {
                    ret += s[i];
                } else {
                    pair<int, string> tmp = decode_stk.top(); 
                    decode_stk.pop();
                    tmp.second += s[i];
                    decode_stk.push(tmp);
                }
            } else if (isdigit(s[i])) {
                number = number*10 + s[i] - '0';
            }
        }
        
        return ret;
    }
};
```