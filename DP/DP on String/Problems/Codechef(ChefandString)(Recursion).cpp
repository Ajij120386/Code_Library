#include <bits/stdc++.h>
using namespace std;

int f(int ind,string &s) {

	if (ind <= 0)

            return 0;


	int take = 0;
	if ((s[ind] == 'y' && s[ind-1] == 'x') || (s[ind] == 'x' && s[ind-1] == 'y'))
             take = 1 + f(ind-2,s);

	int nottake = 0+f(ind-1,s);

	return max(take, nottake);
}

int main() {
	ios_base::sync_with_stdio(0);
	int t;
    cin >> t;
    string s;
	while (t--)
    {

		cin >> s;
		int n=s.size();


		cout <<f(n-1,s) <<endl;
	}
}

