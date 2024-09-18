
### **Find All Anagrams in a String**

***Big O:*** O(Ns + Np), O(1) space (no more than 26 characters)
```
Tips: 

Sliding Window with HashMap or Sliding Window with Array with 26 entries
```
```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> p_umap, s_umap;
        vector<int> ret;
        
        if (s.size() < p.size())
            return ret;
        
        for (auto c : p)
            p_umap[c] ++;
        
        int st = 0, end = 0;
        
        while (end < s.size()) {
            //cout << st << end << endl;
            if (end-st+1 < p.size()) {
                if (p_umap.find(s[end]) != p_umap.end()) {
                    s_umap[s[end]] ++;
                    end ++;
                } else {
                    s_umap.clear();
                    end ++;
                    st = end;
                }
            } else if ((end-st+1 > p.size())) {
                if (s_umap[s[st]] == 1)
                    s_umap.erase(s[st]);
                else
                    s_umap[s[st]] --;
                st ++;
            } else {
                s_umap[s[end]] ++;
                if (s_umap == p_umap)
                    ret.push_back(st);
                end ++;
            }
        }
        
        return ret;
    }
};
```