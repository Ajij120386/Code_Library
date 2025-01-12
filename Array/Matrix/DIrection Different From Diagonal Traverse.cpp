

/*  n=5
11 19 20 24 25
10 12 18 21 23
4 9 13 17 22
3 5 8 14 16
1 2 6 7 15
*/
#include <bits/stdc++.h>
using namespace std;

// Function to print the required pattern
int main()
{
	int n = 5;


	// arr[][] will store the pattern matrix
	int arr[n][n],  p = 1, f;

    int m=n;
      int row=m-1;
      int col=0;
      bool up=true;
      //The above are some intilisations;
      vector<int>result;
      while(row>=0 and col>=0){

          if(up==true){
              //when we are moving in the up direction
              while(row<m-1 and col<n-1){
               // cout<<1<<" "<<p<<endl;
               arr[row][col]=p;
              p++;
               row++;
               col++;
              }
              arr[row][col]=p;
             // cout<<1<<" "<<p<<endl;
              p++;
              if(col==n-1){
                  row--;
              }
              else{
                  col++;
              }
          }
         else{
             //when we are moving in the down direction
             while(col>0 and row>0){

                  //   cout<<2<<" "<<p<<endl;
                arr[row][col]=p;
              p++;
                 row--;
                 col--;
             }
           arr[row][col]=p;
          // cout<<2<<" "<<p<<endl;
              p++;
             if(row==0){
                 col++;
             }
             else{
                 row--;
             }
         }
         up=!up; //reversing the condition to move in alternate direction
      }


	// Print the pattern
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
