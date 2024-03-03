
//In the name of ALLAH
 //complexity O(n*ln(n))
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 5e6+123;
int phi[mx];
void EulerPhi(int n)
{

  for(int i=1;i<=n;i++) phi[i]=i;

        for(int i=2;i<=n;i++)
        {
            if(phi[i]==i)
             {
                for(int j=i;j<=n;j+=i)
                {
                  phi[j]*=(i-1);
                  phi[j]/=i;
                }

              }
          }

}
 int main()
{
    optimize();
    int lim=5000050;
   EulerPhi(lim);
    int  n;
    cin>>n;

        for(int i=1;i<=n;i++)
            cout<<i<<" "<<phi[i]<<endl;
      return 0;
}

