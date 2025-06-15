//provlem statement :

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
 
// Constraints:

// 1 <= prices.length <= 105
// 0 <= prices[i] <= 104

//code solution : 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell =prices.size()-1;
        int profit = 0;

        for(int i=0 ; i<prices.size() ; i++){
            if(prices[i] < buy){
                buy = prices[i];
            }else{
                profit = max(profit , prices[i] - buy);
            }
        }

        return profit;
    }
};

//what this solution uses is called the two pointer approach , where the first pointer is the one wich store the price to buy the stock and second one iterates through 
//the entire array in order to calculate the profit by calculating difference in buy price and sell price , and while constantly checking if the buy price can be any smaller ?
//if such price exists we update our buy to that current price value which we get from our prices array.
