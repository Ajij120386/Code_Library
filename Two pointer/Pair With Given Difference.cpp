int Solution::solve(vector<int> &A, int B) {


    int i=0,j=1,n=A.size();
    sort(A.begin(),A.end());

    while(i<n && j<n)
    {
        if(A[j]-A[i]==B && i!=j)
          return 1;

        else if(A[j]-A[i]<B)
          j++;
         else
          i++;
    }
        return 0;

}
