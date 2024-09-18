# Best Time to sell stocks II

### **Best Time to sell stocks II**

***Big O:*** O(n) speed, O(1) space
```
Tips: 

Greedy. Buy low, Sell high.
```
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev = prices[0], res = 0;
        for (int curr: prices) {
            if (prev < curr) res += curr - prev;
            prev = curr;
        }
        return res;
    }
};
```


### **Best time to buy and sell stock with transcation fee**

***Big O:*** O(n) speed, O(1) space
```
Tips: 

```
```c++
class Solution {
public:
    /**
     * @param prices: a list of integers
     * @param fee: a integer
     * @return: return a integer
     */
    int maxProfit(vector<int> &prices, int fee) {
        // write your code here
        int cash = 0, hold = -prices[0];

        for (int i = 0; i < prices.size(); i++) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash-prices[i]);
        }
        
        return cash;
    }
};
```