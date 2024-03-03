#include<bits/stdc++.h>
using namespace std;
void printbinary(int num){

   for(int i=31;i>=0;i--)
    {
     cout<<((num>>i)&1);
     }
  cout<<endl;
}
int main(){


   printbinary(9);
int a=9;






 /*
   //set bit check


       00001001  1<<1=0000010
      *00000010
       ________
       00000000
       so unset


       00001001  1<<0=00000001
      *00000001
       ________
       00000001
       so set
    */
      int i=1;
   if(a&(1<<i))
    cout<<"set bit"<<endl;

   else
     cout<<"Not set bit"<<endl;







     /*

  int countsetBits(int num)
{
    int count = 0;
    for(int i = 31; i>=0; --i){
        if(( num & (1<<i ))!=0)
          count++;
         }
    return count;
}

            OR



            int countsetBits(int num)
{
    int count = 0;
    for(int i = 31; i>=0; --i){
        count+=( ( num>>i) & 1);

         }
    return count;
}



 // count set bit USing Inbuilt function
    cout<<__builtin_popcount(a)<<endl;
     cout<<__builtin_popcountll((1LL<<35)-1)<<endl;

*/







   /*
       how to set in a bit

       00001001  1<<1=00001000
      +00000010
       _________
       00001011
    */
       i=1;
      printbinary(a | (1<<i) );






    /*
        how to clear/unset in a bit

       00001001  1<<3=00001000    ~(1<<3)= 11110111
      *11110111
       __________
       00000001
    */
      i=3;
      printbinary(a & ~(1<<i) );





   /*
        how to toggle in a bit
     we know xor 1^0=1 , 0^0=0, 1^1=0

       00001001  1<<2=00000100
      ^00000100
       __________
       00001101

    */
      i=2;
      printbinary(a ^ (1<<i) );









   /*
        how to remove last set bit in a bit

      let, a=9   a=00001001
       * a-1=8 a-1=00001000
    ___________________________
                   00001000


     again let, a=8   a=00001000
            * a-1=7 a-1=00000111
      ____________________________
                       000000000
    */

      i=2;
      printbinary(a&(a-1) );










       /*
        how to check odd even

      let, a=9   a=00001001
                 1=00000001
    ___________________________
                   00000001
         so odd

      let, a=8   a=00001000
                 1=00000001
    ___________________________
                   00000000
         so even
    */


   if(a&1==0)
    cout<<"even "<<endl;

   else
     cout<<"odd"<<endl;




     /*







        how to multiply==left shift and divide==right shift
   2^1=2    n<<1 ==by 2 multiply
   2^2=4    n<<2===by 4 multiply
   2^3=8    n<<3===by 8 multiply

   2^1=2    n>>1 ==by 2 divide
   2^2=4    n>>2===by 4 divide
   2^3=8    n>>3===by 8 divide

      let, a=9   a=00001001
             a<<3  01001000   ==9*8=72

       let, a=9   a=00001001
             a>>3 00000001   ==9/8=1
    */
    cout<<(a<<3)<<endl; //multiply
    cout<<(a>>3)<<endl;   //divide







    /*



        check uppercase to lowercase
        A= 00001000001
        a= 00001100001
        B= 00001000010
        b= 00001100010

        the difference between capital and small letter  binary number 5th bit set or not


       A | (1<<5) set 5th bit (1<<5)===space/' '

       uppercase to lowercase

        char x= X | ' '

        Lowercase to Uppercase

         A &  (~(1<<5) )         (~(1<<5) )='_' /underscore
        char X= x & '_';

    */

       char B='B';
     //uppercase to lowercase
        char b= B | ' ';
        cout<<b<<endl;



        char d='d';
        //Lowercase to Uppercase
          char D= d & '_';
   cout<<D<<endl;




    /*
          clear LSB
         a=15= 00001111
         i=2 th bit clear
        so a=00001000

                          if we make this by 1<<i+1==1<<3=00001000
                             then            (1<<i+1)-1 ===00000111

                                             ~`1<<i+1)-1===11111000
          a=15=00001111
             *11111000
           ------------
              00001000


    */

     printbinary(15);
   int e=15;
    i=2;
    int f=(e&(~((1<<(i+1))-1)));
    printbinary(f);



    /*


          clear MSB
         a=15= 00001111
         i=1 th bit clear
          so a=00000011

                          if we make this by 1<<i+1==1<<2= 00000100
                             then            (1<<i+1)-1 ===00000011


          a=15=00001111
              *00000011
           ------------
               00000011



                 printbinary(15);

                 */
     int g=15;
     i=1;
    int h=(g&(((1<<(i+1))-1)));
    printbinary(h);


     //Finding MSB:

    int bitp(ll v)
{

    int r = 0;

     while (v >>= 1)
    {
        r++;
    }
     return r;

}
or
using  ind=int m=log2(x);
//





    /*
          check power of two

          a=15=  00001111
        a-1=14= *00001101
           --------------
                 00001101

    not power of two;


          a=16=  00010000
        a-1=15= *00001111
           --------------
                 00000000

     power of two;
    */
    int n=16;
    if(n&(n-1))
         cout<<"not power of two"<<endl;

     else
     cout<<" power of two"<<endl;
}

