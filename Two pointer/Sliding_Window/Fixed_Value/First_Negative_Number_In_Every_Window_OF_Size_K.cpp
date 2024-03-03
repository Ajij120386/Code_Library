
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {


                  vector<long long>ans;
                  queue<long long>q;
        int n=N;
        long long i=0,j=0,sum=0,res=INT_MIN;
        while(j<n)
        {


            if(A[j]<0)

                 q.push(A[j]);


             if(j-i+1<K)
                   j++;

              else
           {

               if(q.empty()) ans.push_back(0);

               else
               {


                   ans.push_back(q.front());

                   if(A[i]==q.front()) q.pop();

               }

                     i++;
                     j++;
           }
        }
        return ans;


 }
