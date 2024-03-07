/**** LeetCode 56 - Merge Intervals ****/

#include <bits/stdc++.h>
using namespace std;

/* BRUTE FORCE APPROACH */
// Time: O(nlogn) + O(2n) as in nested loops, almost every iteration gets skipped, and each interval is visited exactly twice.
// Space: O(n) as `ans` list is used to store the result.
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    vector<vector<int>> ans; // In `ans` we will insert merged intervals.
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        // Select the first element from first row as the first interval.
        int start = arr[i][0];
        int end = arr[i][1];

        // Skipping already merged intervals:
        if (!ans.empty() && end <= ans.back()[1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]); // Overlapping or merging occurs.
            else
                break;
        }

        ans.push_back({start, end});
    }
    return ans;
}



/* OPTIMAL APPROACH */
// Time: O(nlogn) + O(n)
// Space: O(n)

// Here we will use only one loop.
// Insert first interval.
// And next onwards check if interval must be skipped or merged.
vector<vector<int>> mergeOverlappingIntervals2(vector<vector<int>> &arr)
{
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        // Check if it must be pushed as it is, without merging:
        if (ans.empty() || arr[i][0] > ans.back()[1])
            ans.push_back(arr[i]);
        else
            // When interval has to be merged:
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
    return ans;
}



void printMergedIntervals(vector<vector<int>> a)
{
    cout << "Merged Intervals: " << endl;
    for (auto it : a)
        cout << "[" << it[0] << ", " << it[1] << "] ";
    cout << endl;
}



int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    // vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    // printMergedIntervals(ans1);


    vector<vector<int>> ans2 = mergeOverlappingIntervals2(arr);
    printMergedIntervals(ans2);

    return 0;
}