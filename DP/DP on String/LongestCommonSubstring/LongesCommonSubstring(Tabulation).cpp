#include <bits/stdc++.h>
using namespace std;

void printLCS(string s1,int index,int totalsize){

if(totalsize<index)  swap(totalsize,index);
int a=(totalsize-index)+1;
   for(int i=a;i<=totalsize ;i++)
    cout<<s1[i];

cout<<endl;
}
int LCSubstring(string &s1, string &s2){

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    int totalsize = 0;
    int index=0;
    for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1]){
                int val = 1 + dp[i-1][j-1];
                dp[i][j] = val;
                if(totalsize<val){
                    totalsize=val;
                    index=i-1;
                }

            }
            else
                dp[i][j] = 0;
        }
    }


  cout<<"The Length of Longest Common Substring is "<<totalsize<<endl;

  cout<<"The index of Longest Common Substring is "<<index<<endl;

  printLCS(s1,index,totalsize);

}

int main() {

  string s1= "abcjklp";
  string s2= "acjkp";
   LCSubstring(s1,s2);



}
