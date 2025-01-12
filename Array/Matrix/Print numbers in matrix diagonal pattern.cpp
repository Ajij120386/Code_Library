
/*

         Input: 3
Output:
1 2 4
3 5 7
6 8 9

Input: 4
Output:
1 2 4 7
3 5 8 11
6 9 12 14
10 13 15 16
*/
// C++ program to print the required pattern
#include <bits/stdc++.h>
using namespace std;

// Function to print the required pattern
int main()
{
	int n = 3;


	// arr[][] will store the pattern matrix
	int arr[n][n],  p = 1, f;

	// Store the values for upper triangle
	// of the pattern
	 for (int j = 0; j < n; ++j) {
            int row = 0;
            int col = j;

            // Traverse the anti-diagonal
            while (row < n && col >= 0) {
               arr[row][col] = p;
			      p++;
                ++row;
                --col;
            }
        }
 for (int i = 1; i < n; ++i) {
            int row = i;
            int col = n - 1;

            // Traverse the anti-diagonal
            while (row < n && col >= 0) {

                  arr[row][col] = p;
			      p++;
                ++row;
                --col;
            }

        }

	// Print the pattern
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

// Driver code


