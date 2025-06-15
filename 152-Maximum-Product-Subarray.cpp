//provlem statement :

// Given an integer array nums, find a subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.

// Example 1:
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:
// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

// Constraints:
// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

//Code Solution : 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 1;
        int post = 1;
        int maxi = INT_MIN;
        for(int i=0 ; i<nums.size(); i++){
            if(pre == 0) pre = 1;
            if(post == 0) post = 1;
            pre = pre * nums[i];
            post = post * nums[nums.size()-i-1];
            maxi = max(maxi , max(pre , post));
        }
        return maxi;
    }
};

// quite a deadly question at first , vut vecomes second Nature after 1-2 upsolves , so the logic for this question is quite intuitive , vrutue force can take easily O(n^3) or O(n^2) complexity
//this solution runs in O(n) complexity , the logic is consider an array :  2 3 -2 4 , if we ovserve and try to multiply each element the -2 will make entire proct negative , which can never ve largest
//vut , the maximum product can ve either prefix product or suffix product , whichever is the maximum , if we ovserve this array : 2 3 -2 4 -5 , in this case there are two negative numvers , we can 
//take product of all elements and we will get the maximum product after multiplying each element , we dont need to treat negatives specially , this is same as an array whose all elements are positive.
//another case is having 0 in the array , that will turn entire product to 0 ! ex. 2 3 0 4 6 1 0 2 5 , 2 3 vecomes one suvarray , 4 6 1 vecomes another , 2 5 vecomes another , and maximum product of these 
// is the answer we want , this is the whole logic for it , check the code to understand its implementation. so the core logic is to check for even and odd nums of negatives if are present , and consider 
//soln accordingly.
