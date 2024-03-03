#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)
#define whatis(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;

#define mx 10000
int ar[mx];
int tree[mx];

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

void print(int *ar, int n) {
    for (int i = 1; i <= n; ++i) {
        cout << ar[i] << " ";
    }
    puts("");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) { cin >> ar[i]; update(i, ar[i], n); }

    cout << "input array:\t";
    print(ar, n);
    cout << "\n";

    cout << "tree array:\t";
    print(tree, n);
    cout << "\n";

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
			update(l,val,n);
		}


}
}
/*
input:
16
1 0 2 1 1 3 0 4 2 5 2 2 3 1 0 2


5
1  2 13   query 1
input array:    1 0 2 1 1 3 0 4 2 5 2 2 3 1 0 2
tree array:     1 1 2 4 1 4 0 12 2 7 2 11 3 4 0 29

25          query 1 output
2 13 2         update 1
1  2 13          query 2
27            query 2 output
2 13 -2       update 2
1  2 13      query 3
25           query 3 output
*/
