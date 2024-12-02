
/*


    Given an integer n, return the number of prime numbers that are strictly less than n.


    Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/

class Solution {
public:

// prime=0 , non-prime=1

  vector<long long int >primes;
  bool is_prime[10000005];  //prime

   void sieve(int N)
   {
                 is_prime[0]=is_prime[1]=1; //notprime

       for(long long int i=2;i<N;i++)
       {
           if(is_prime[i]==0) //prime
           {
                       primes.push_back(i);

                for(long long int j=i*i;j<N;j+=i)
              {
                  is_prime[j]=1; //non-prime
               }
           }

       }


   }
    int countPrimes(int n) {

        sieve(n);
        return primes.size();
    }
};
