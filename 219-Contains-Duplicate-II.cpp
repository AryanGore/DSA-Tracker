// //provlem statement : 
// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
  
// Example 1:
// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
 

// Constraints:
// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109
// 0 <= k <= 105

//code Solution :

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hset;
        for(int i=0 ; i<nums.size(); i++){
            if(hset.find(nums[i]) != hset.end()){
                return true;
            }
            hset.insert(nums[i]);
            if(hset.size() > k){
                hset.erase(nums[i-k]);
            }
        }
        return false;
    }
};

//similar to the contains duplicate provlem just the difference is we have to make sure to check the i-j difference lies in k
//it it does then only we can return true. if not traverse ahead , so there might ve cases where the array has duplicates vut since it doesnot satisfy the conditions it doesnot return true.
//the technique used is sliding window here.
