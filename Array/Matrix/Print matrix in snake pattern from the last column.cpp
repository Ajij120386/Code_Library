
/*

      Input : mat[][] =
1 2 3
4 5 6
7 8 9
Output: 3 2 1 4 5 6 9 8 7

Input: mat[][] =
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Output: 4 3 2 1 5 6 7 8 12 11 10 9 13 14 15 16
*/

    // C++ program for traversing a matrix from column n-1
#include <bits/stdc++.h>
using namespace std;

// Function used for traversing over the given matrix
void traverseMatrix(vector<vector<int> > mat, int n)
{

	for (int i = 0; i < n; i++) {
		if (i%2 == 1)
			for (int j = 0; j < n; j++)
				printf("%d ", mat[i][j]);

		else
			for (int j = n - 1; j >= 0; j--)
				printf("%d ", mat[i][j]);
	}
}

// Driver function
int main()
{

	// number of rows and columns
	int n = 5;

	// 5x5 matrix
	vector<vector<int> > mat{
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 10 },
		{ 11, 12, 13, 14, 15 },
		{ 16, 17, 18, 19, 20 },
		{ 21, 22, 23, 24, 25 }
	};

	traverseMatrix(mat, n);

	return 0;
}
