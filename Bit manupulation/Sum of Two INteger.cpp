class Solution {
public:
    int getSum(int a, int b) {
        int carry=b,sum=a;

      while(carry !=0 ) {

        sum=a^b;
        carry = (a&b)<<1;
        a=sum;
        b=carry;

      }
      return sum;
    }
};
