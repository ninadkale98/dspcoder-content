# Meeting Room II



### **Meeting Rooms II**

***Big O:*** O(nlog(n)) speed, O(n) space
```
Tips: 

Sort + priority queue. Kick people out if their meeting is already finished.
```
```c++
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (auto v : intervals) {
            // check if the last meetings need to be completed
            // before this meeting starts.
            if (!pq.empty() && pq.top() <= v[0]) {
                pq.pop();
            }
            
            // start this meeting and enter the end time.
            pq.push(v[1]);
        }
        
        return pq.size();
    }
};
```