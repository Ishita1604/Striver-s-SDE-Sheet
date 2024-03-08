#include <bits/stdc++.h>
using namespace std;

/******* Merge 2 Sorted Arrays Without Extra Space *******/

// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
// Merge them in sorted order.
// Modify arr1 so that it contains the first N elements.
// And modify arr2 so that it contains the last M elements.




/* BRUTE FORCE APPROACH: */
// Uses extra space.
// Time: 2 * O(n + m)
// Space: O(n + m)
void merge(vector<int> &nums1, int n, vector<int> &nums2, int m)
{
    vector<int> nums3(n + m);
    // Using two pointers left & right:
    int l = 0;
    int r = 0;
    int index = 0; // For iterating nums3.
    while (l < n && r < m)
    {
        if (nums1[l] <= nums2[r])
        {
            nums3[index] = nums1[l];
            index++;
            l++;
        }
        else // (nums2[r] <= nums1[l])
        {
            nums3[index] = nums2[r];
            index++;
            r++;
        }
    }
    // Situation where (r > m) i.e. nums2 exhausts.
    while (l < n)
    {
        nums3[index] = nums1[l];
        index++;
        l++;
    }
    // Situation where (l > n) i.e. nums1 exhausts.
    while (r < m)
    {
        nums3[index] = nums2[r];
        index++;
        r++;
    }

    // Now we need to add elements from nums3 back to nums1 & nums2.
    for (int i = 0; i < (n + m); i++)
    {
        if (i < n)
            nums1[i] = nums3[i];
        else
            nums2[i - n] = nums3[i];
    }
}




/* OPTIMAL APPROACH 1: */
// Time: O(min((n, m)) + O(nlogn) + O(mlogm)
// Space: O(1)
void merge2(vector<int> &nums1, int n, vector<int> &nums2, int m)
{
    int l = n - 1;
    int r = 0;
    while (l >= 0 && r < m)
    {
        if (nums1[l] > nums2[r])
        {
            swap(nums1[l], nums2[r]);
            l--;
            r++;
        }
        else
            break;
        // We reach the point where an element of nums1 < nums2.
        // Then there after all elements to left of nums1 will be < nums2.
        // And all elements to right of nums2 will be > nums1.
    }
    sort(nums1.begin(), nums1.begin() + n);
    sort(nums2.begin(), nums2.begin() + m);
}




int main()
{
    vector<int> nums1 = {1, 4, 8, 10};
    vector<int> nums2 = {2, 3, 9};
    int n = 4, m = 3;
    // merge(nums1, n, nums2, m);
    merge2(nums1, n, nums2, m);

    cout << "The merged arrays are: " << endl;

    cout << "nums1[] = ";
    for (int i = 0; i < n; i++)
        cout << nums1[i] << " ";

    cout << "\nnums2[] = ";
    for (int i = 0; i < m; i++)
        cout << nums2[i] << " ";
    cout << endl;

    return 0;
}