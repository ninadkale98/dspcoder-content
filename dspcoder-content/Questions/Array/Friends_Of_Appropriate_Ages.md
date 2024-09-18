# Friends Of Appropriate Ages


### **Friends Of Appropriate Ages**

***Big O:*** O(nlog(n)) speed, O(n) space
```
Tips: 
Approache 1:

Calculate the target value and then do a binary search. For ages we already went through, simply add the number of requests for that age.

Approach 2:

Instead of processing all 20000 people, we can process pairs of (age, count) representing how many people are that age. Since there are only 120 possible ages, this is a much faster loop.
```
```c++
// Approach 2
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int count[121] = {};
        for (int age: ages) count[age]++;

        int ans = 0;
        for (int ageA = 0; ageA <= 120; ageA++) {
            int countA = count[ageA];
            for (int ageB = 0; ageB <= 120; ageB++) {
                int countB = count[ageB];
                if (ageA/2 + 7 >= ageB) continue;
                if (ageA < ageB) continue;
                if (ageA < 100 && 100 < ageB) continue;
                ans += (countA * countB);
                if (ageA == ageB) ans -= countA;
            }
        }

        return ans;
    }
};

// Approach 1
class Solution {
public:
    unordered_map <int,int> map; // key: age, val: FriendRequestCount. 
    
    int findRequests (vector<int> & ages, int index) {
        
        if (map.find(ages[index]) != map.end()) {
            return map[ages[index]];
        }
        
        int left = 0;
        int right = index-1;
        double target = (double) (0.5*ages[index]) + 7; // find ages >= target.
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (ages[mid] <= target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        map[ages[index]] = index-left;
        return index-left; // len between index-1 and left. 
    }
    
    int numFriendRequests(vector<int>& ages) {
        
        sort (ages.begin(), ages.end());
        
        int count = 0;
        
        for (int i = ages.size()-1; i >= 0 ; i--) {
            count += findRequests (ages, i);
        }
        return count;
    }
};
```