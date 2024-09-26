
////using Iterative approach

  int countSetBits(int n) //n=11
    {
        // Your logic here


      int cnt=0;
      while(n>0){

      int x= floor(log(n)/log(2)); //find 2's power value which is less than or equal to n, for 11 its 3.

       cnt+= x*(1<<(x-1));  //  1 to 7 poijonto set bit counting = 3*4=12
       cnt+=(n+1)-(1<<x);   // 8 to 11 only msb count which is =12-8=4
       n=n-(1<<x);            // then solve same function for n=11-8=3

      }
    return cnt;


    }

    ///using REcursive approach


    //Function to return sum of count of set bits in the integers from 1 to n.
    int cnt=0;
    int countSetBits(int n) //n=11
    {
        if(n==0) return 0;



      int x= floor(log(n)/log(2)); //find 2's power value which is less than or equal to n, for 11 its 3.
     int btill2powerx= x*(1<<(x-1));  //  1 to 7 poijonto set bit counting = 3*4=12
       int msb2powerxToN=(n+1)-(1<<x);   // 8 to 11 only msb count which is =12-8=4
       int rest=n-(1<<x);            // then solve same function for n=11-8=3
    int ans= btill2powerx +msb2powerxToN + countSetBits(rest);

       return ans;
    }
