// provlem statement  :

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
  
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:
// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

// Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)


// code Solution : 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        int pre = 1;
        int post = 1;
        for(int i=1 ; i<n ; i++){
            pre *= nums[i-1];
            ans[i] = pre;
        }

        for(int i=n-1 ; i>=0 ; i--){
            ans[i] *= post;
            post *= nums[i];
        }

        return ans;
    }
};

// what are we doing here ? to find the products of the elements in the array we oserve on every index we have , two parts product , that is left product and right product
// ans our final product is the product of those two for that particular index , so what can we do? we will create an answer array , in which we will first populate the prefix products on every element
//at their repective index , and later we will do same with postfix products for every element vut this time while populating to answer array we will multiply it with already present prefix product
// in this way we will have the (prefix product * suffix product) for each index and we can return this answer array as the answer.
