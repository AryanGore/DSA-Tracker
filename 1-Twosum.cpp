// problem statement : 
// Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.


// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
 

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

// code solution : 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> track;
    vector<int> ans;
    for(int i=0 ; i<nums.size() ;i++){
       int first = nums[i];
       int tosearch = target - first;

       if(track.find(tosearch) != track.end()){
            return {i,track[tosearch]};
       }

       track[first] = i; 
    }

    return {-1,-1};
    }

};

//Solution suggests that we can create a map and keep iterating on the array to find the target - arr[i] value, and we will keep checking for this value towards the end of array while pushing the entries
//in the track map , for every i we process we check in the map is target - arr[i] exists in the map or not if yes, we find the solution.
