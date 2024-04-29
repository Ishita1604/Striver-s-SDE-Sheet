/****** Largest Sum Contiguous Subarray (Kadane's Algorithm) ******/

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE APPROACH:
// TIME: O(n^3)
// SPACE: O(1)
class Solution
{
public:
    int maxSubArray0(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                    sum += nums[k];
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }




    // BETTER APPROACH - ELIMINATES A FOR LOOP:
    // TIME: O(n^2)
    // SPACE: O(1)
    int maxSubArray1(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                maxi = max(sum, maxi);
            }
        }

        return maxi;
    }




    // OPTIMAL APPROACH - KADANE'S ALGORITHM:
    // TIME: O(n)
    // SPACE: O(1)
    int maxSubArray2(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            maxi = max(sum, maxi);
            if (sum < 0)
                sum = 0; // Discard the sum obtained as sum < 0 only decreases our "maximum sum"!
        }

        // In some questions, it is mentioned that if none of the sum is < 0, the return answer as 0.
        // if (maxi < 0)
        //     return 0;

        return maxi;
    }
};



int main()
{
    // vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
    // vector<int> nums = {-2, 1, 5};
    vector<int> nums = {2, 3, -5};

    // Solution obj1;
    // int ans1 = obj1.maxSubArray0(nums);
    // cout << "Maximum sum of a contiguous subarray is: " << ans1 << endl;

    // Solution obj2;
    // int ans2 = obj2.maxSubArray1(nums);
    // cout << "Maximum sum of a contiguous subarray is: " << ans2 << endl;

    Solution obj3;
    int ans3 = obj3.maxSubArray2(nums);
    cout << "Maximum sum of a contiguous subarray is: " << ans3 << endl;

    return 0;
}

// LeetCode 53 - Maximum Subarray (3 Ways)
