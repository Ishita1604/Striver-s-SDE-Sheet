#include <bits/stdc++.h>
using namespace std;

int pascalTriangle1(int n, int r)
{
    // FORMULA:
    // Element = (r - 1)C(c - 1)
    int element;
    int num = 1;
    int den = 1;
    // Trick to calculate nCr:
    for (int i = r; i > 0; i--)
    {
        num *= n;
        n--;
        den *= i;
    }
    element = num / den;
    return element;
}




void pascalTriangle2(int n)
{
    // For every row, first element is initialized as 1.
    // To find next element, it uses previous element of that row.
    // And division also done in same step.
    int el = 1;
    for (int c = 0; c < n; c++)
    {
        cout << el << " ";
        el = el * (n - 1 - c) / (c + 1);
    }
}




void print2DVector(vector<vector<int>> ansLst)
{
    int r = ansLst.size();
    for (int i = 0; i < r; i++)
    {
        int c = ansLst[i].size();
        for (int j = 0; j < c; j++)
            cout << ansLst[i][j] << " ";
        cout << endl;
    }
}

int findnCr(int n, int r)
{
    int el;
    int num = 1;
    int den = 1;
    for (int i = 0; i < r; i++)
    {
        // For num, n is multiplied r times.
        // For den, r is multiplied r times.
        num = num * (n - i);
        den = den * (i + 1);
    }
    el = num / den;
    return el;
}

vector<vector<int>> pascalTriangle3(int numRows)
{
    // Every row has row number of columns!
    vector<vector<int>> ansLst;
    int el;
    for (int r = 1; r <= numRows; r++)
    {
        vector<int> tempLst;
        for (int c = 1; c <= r; c++)
        {
            el = findnCr(r - 1, c - 1);
            tempLst.push_back(el);
        }
        ansLst.push_back(tempLst);
    }
    return ansLst;
}




vector<vector<int>> pascalTriangle4(int n)
{
    vector<vector<int>> ansLst;
    for (int i = 0; i < n; i++)
    {
        vector<int> tempLst;
        int el = 1;
        for (int j = 0; j <= i; j++)
        {
            // Generate entire row:
            tempLst.push_back(el);
            el = el * (i - j) / (j + 1);
        }
        ansLst.push_back(tempLst);
    }
    return ansLst;
}




int main()
{
    /**** VARIATION 1: Value of Row and Column given, find corresponding element. ****/
    // TIME: O(r)
    // SPACE: O(1)

    // int row, col;
    // cout << "Enter Position of Row (R): ";
    // cin >> row;
    // cout << "Enter Position of Column (C): ";
    // cin >> col;
    // cout << "Element at Position (R, C) is: " << pascalTriangle1(row - 1, col - 1) << endl;




    /**** VARIATION 2: Print Nth row of Pascal's Triangle. ****/
    // TIME: O(n)
    // SPACE: O(1)

    // int row;
    // cout << "Enter the Number of Rows: ";
    // cin >> row;
    // pascalTriangle2(row);




    /**** VARIATION 3 - LeetCode 118: Given an integer numRows, return 1st numRows of Pascal's Triangle. ****/

    /** Naive Approach using Variation 1 and 2: **/
    // TIME ~= O(n^3)
    // SPACE: O(1) as we created vectors only to store the answer.
    // int numRows;
    // cout << "Enter the Number of Rows: ";
    // cin >> numRows;
    // vector<vector<int>> ansLst = pascalTriangle3(numRows);
    // print2DVector(ansLst);


    /** Optimal Approach using Variation 2: **/
    // Pushing the entire row in the ansLst.
    // TIME = O(n^2)
    // SPACE: O(1) as we created vectors only to store the answer.
    int numRows;
    cout << "Enter the Number of Rows: ";
    cin >> numRows;
    vector<vector<int>> ansLst = pascalTriangle4(numRows);
    print2DVector(ansLst);

    return 0;
}