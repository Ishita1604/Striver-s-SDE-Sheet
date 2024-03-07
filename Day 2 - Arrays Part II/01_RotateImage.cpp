/**** LeetCode 48 - Rotate Image ****/

#include <bits/stdc++.h>
using namespace std;

/**** Brute Force Approach: ****/
// Time: O(n * n)
// Space: O(n * n)
vector<vector<int>> rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> rot_matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            rot_matrix[j][n - i - 1] = matrix[i][j];
    }
    return rot_matrix;
}




/**** Optimal Approach: ****/
// Time: O(n * n)
// Space: O(1) as inplace rotation!
void rotate2(vector<vector<int>> &matrix)
{
    // 1. Transpose the matrix.
    // 2. Reverse each row.
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i == j)
                continue;
            else
                swap(matrix[j][i], matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}




int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> rot_matrix = rotate(matrix);
    // for (int i = 0; i < rot_matrix.size(); i++)
    // {
    //     for (int j = 0; j < rot_matrix[0].size(); j++)
    //         cout << rot_matrix[i][j] << " ";
    //     cout << endl;
    // }




    rotate2(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
