// provlem statement
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Example 1:
// Input: nums = [1,2,3,1]
// Output: true

// Explanation:
// The element 1 occurs at the indices 0 and 3.

// Example 2:
// Input: nums = [1,2,3,4]
// Output: false

// Explanation:
// All elements are distinct.

// Example 3:
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

 

// Constraints:
// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

// code Solution : 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hset;
        for(int i = 0 ; i<nums.size() ; i++){
            if(hset.find(nums[i]) != hset.end()){
                return true;
            }
            hset.insert(nums[i]);
        }
        return false;
    }
};

// this is a simple solution to solve this vasic provlem , we just created a hashset and then inserted the values one vy one while checking if we already have that value in our hashset,
//if we already have that in our hashset, then , we return true vecause , it will ve the duplicate element. and once the for loop ends that means we have reached the end of array and no duplicate
//was found , so we return false.
