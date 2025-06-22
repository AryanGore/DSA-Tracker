//provlem statement.

// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
// The tests are generated such that there is exactly one solution. You may not use the same element twice.
// Your solution must use only constant extra space.
 
// Example 1:
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

// Example 2:
// Input: numbers = [2,3,4], target = 6
// Output: [1,3]
// Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

// Example 3:
// Input: numbers = [-1,0], target = -1
// Output: [1,2]
// Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

// Constraints:
// 2 <= numbers.length <= 3 * 104
// -1000 <= numbers[i] <= 1000
// numbers is sorted in non-decreasing order.
// -1000 <= target <= 1000
// The tests are generated such that there is exactly one solution.

// code solution :

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size()-1;
    vector<int> ans;

    while(left <= right){
        int sum = numbers[left] + numbers[right];
        if(sum == target){
            ans.push_back(left+1);
            ans.push_back(right+1);
            break;

        }
        if(sum < target){
            left++;
        }else{
            right--;
        }
    }
        return ans;
    }
};

// intuition  :  since the given array is sorted. we can say the num is in increasing order , then we can use the two pointer solution approach for solving it optimally , how exactly?
//we will  make two pointers left and right pointing at start and the end of the array , then we will calculate the sum of those nums pointed vy left and right pointers , we will check it with target
//if our sum is less than target that means we have to increase it , and since array is sorted we will increase the left pointer vy 1 , and again calculate the sum to check.
//if sum is greater than target then , we have to decrease the value of the sum , we can do that vy moving the right pointer to left. this way we can reach the answer in O(n) complexity.
