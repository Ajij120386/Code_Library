#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int ar[mx];
int tree[mx*4];



const int MX = 1e7+123;
bitset<MX> is_prime;
vector<int> prime;

void primeGen ( int n )
{
    n += 100;
    for ( int i = 3; i <= n; i += 2 ) is_prime[i] = 1;
   is_prime[2] = 1;
    int sq = sqrt ( n );
    for ( int i = 3; i <= sq; i += 2 ) {
        if ( is_prime[i] == 1 ) {
            for ( int j = i*i; j <= n; j += ( i + i ) ) {
                is_prime[j] = 0;
            }
        }
    }



}

int Prefixsum(int idx){
    int sum = 0;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int rangeSum(int l,int r)
{
    return Prefixsum(r)-Prefixsum(l-1);
}
void update(int idx, int val, int n){

    while (idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main()
{


    primeGen(MX);

   int n;
   cin>>n;

   for(int i=1;i<=n;i++)
   {
       cin>>ar[i];


            update(i, is_prime[ar[i]],n);
    }

         int q;
	cin >> q;

	while(q--) {
		int type;
		cin >> type;
		if(type==1) {

			int l, r;
			cin >> l >> r;
			cout << rangeSum(l,r) << endl;
		}
		else {

			int l,val;
			cin >> l >> val;


                update(l, -is_prime[ar[l]],n);
                 update(l, is_prime[val],n);



		}


}
      return 0;
}

