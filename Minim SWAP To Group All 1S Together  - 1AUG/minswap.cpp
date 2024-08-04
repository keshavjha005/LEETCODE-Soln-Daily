prblm  :---- A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

 

Example 1:

Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.
Example 2:

Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
Example 3:

Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.




// Code:-
INTUTION :-- 
The problem requires finding the minimum number of swaps to group all 1s together in a circular array. Intuitively, we can focus on a window of size equal to the total number of 1s. We need to find the minimum number of zeros within this window as that's directly related to the number of swaps required.

Approach
We'll use a sliding window approach:

1. Calculate the total number of 1s (window size).
2. Count the number of zeros within the initial window.
3. Slide the window and update the count of zeros.
4. Keep track of the minimum number of zeros encountered.
5. The minimum number of swaps required is equal to the minimum number of zeros encountered.


Complexity
Time complexity:O(n)
Space complexity: O(1)




//  Code
class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int window = 0;

        for(auto num: nums){

            if (num == 1) window++;
            
        }

        int n = nums.size();
        int zero = 0;

        for(int i=0;i<window;i++){

            if(nums[i]==0) zero++;
            
        }

        int swap = zero;

        for(int i=window;i<n + window;i++){

            if(nums[i % n] == 0) zero++;

            if(nums[i-window] == 0) zero--;

            swap = min(swap,zero);
            
        }

        return swap;
        
    }
};