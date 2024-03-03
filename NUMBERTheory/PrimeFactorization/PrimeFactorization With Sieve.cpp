#include<iostream>
#include<stdio.h>
#include<bitset>
#include<vector>
#include<math.h>
#define N 10000000
using namespace std;
bitset <N> bits ;
int primes[N]	;
void precomputation(){
    for(int i = 2; i < N; i += 2)	primes[i] = 2 ;
	int sq=sqrt(N-1);
    for(int i = 3; i < N; i += 2)
            if (!bits[i]){
                primes[i] = i   ;
                if(i<=sq) for(int j = i * i; j < N; j += 2 * i)
                    if (!bits[j]){
                        primes[j] = i ;
                        bits[j] = 1 ;

                    }
            }

}

vector<int> getFactorization(int x)
{
	vector<int> ret;
	while (x != 1)
	{
		ret.push_back(primes[x]);
		x = x / primes[x];
	}
	return ret;
}

int main(){

    ios_base::sync_with_stdio(false)    ;   cin.tie(0)  ;
    precomputation()    ;


int x;
cin>>x;
    vector <int> p = getFactorization(x);


    for(auto it: p){
    	cout<<it<<" ";
    }
    }


