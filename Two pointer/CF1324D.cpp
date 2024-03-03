#include <bits/stdc++.h>

using namespace std;


int findPairs (vector<int>&arr , int n )

{
        int l = 0, r = n-1;

        int result = 0;

        while (l < r)
        {
            if (arr[l] + arr[r] > 0)
            {
                result += (r - l);
                l++;
            }
            else
                r--;
        }
        return result;
    }
int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto &it : a) cin >> it;
	for (auto &it : b) cin >> it;
	vector<int> c(n);
	for (int i = 0; i < n; ++i) {
		c[i] = a[i] - b[i];
	}
	sort(c.rbegin(), c.rend());




	cout << findPairs(c,n) << endl;

	return 0;
}
