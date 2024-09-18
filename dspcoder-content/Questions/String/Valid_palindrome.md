
## Implementation

### **Valid Palindrome**

***Big O:*** O(n), O(1) space
```
Tips: 

Two pointers.
```
```c++
class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        int end = s.size()-1;
        
        while (st < end) {
            if (!isalnum(s[st]) || !isalnum(s[end])) {
                while(st < end && !isalnum(s[st])) {
                    st ++;
                }
                while(st < end && !isalnum(s[end])) {
                    end --;
                }
            } else {
                if ((isalpha(s[st]) && isalpha(s[end]) && tolower(s[st]) == tolower(s[end])) || (s[st] - '0' == s[end] - '0')) {
                    st ++;
                    end --;
                }  else 
                    return false;
            } 
        }
        
        return true;
    }
};
```
### **Valid Palindrome II  **

***Big O:*** O(n), O(1) space
```
Tips: 

Implement is_palindrome first. return the answer of two is_palin or together.
```
```c++
class Solution {

public:
    // Checks if string is a palindrome
    bool isPalin(string &s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end])
                return false;
            ++start, --end;
        }
        return true;
    }
    
    // TC: O(N)
    // SC: O(1)
    bool validPalindrome(string s) {
        for(int i = 0, j = s.size()-1; i < j;  ++i, --j) {
            // mismatch found, only if it is the first time delete
            // a char and move on, else not possible
            if(s[i] != s[j]) {
                // s[0:i-1] and s[j+1, n-1] matched,
                // now we check if atleast s[i:j-1] or s[i+1:j] is a palindrome
                return (isPalin(s, i, j-1) || isPalin(s, i+1, j));
            }
        }
        return true;
    }
};
```