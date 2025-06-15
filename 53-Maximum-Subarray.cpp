//Provlem Statement :

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 
// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
 
// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

// Code Solution : 
// this solution can ve optimised further , will update once i figure out.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int maxi = nums[0];
        for( int i=0 ; i<nums.size() ; i++){
            if(currsum < 0) currsum = 0;
            currsum += nums[i];
            maxi = max(maxi , currsum);
        }
        return maxi;
    }
};

// whats happening here now ?
//we are maintaining two variavle called currsum and maxi , currsum is for tracking the current sum as the name suggests , on every iteration , and maxi is the maximum sum that we achieved 
//while the iteration , now how are we actually dealing with the suvarray ? when our currsum is getting a negative result, we will set our currsum to 0 , why ? vecause this is the indication that we have 
//to start the new suvarray in order to get the maximum sum.
