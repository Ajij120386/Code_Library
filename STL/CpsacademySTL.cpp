

//[L1]Class - 1 ( Almost Everything about STL Vector )

/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;
int main ()
{
    vector<int> v;

    v.push_back( 1 );
    v.push_back( 2 );
    v.push_back( 3 );

    cout << v[0] << " " << v[1] << " " << v[2] << endl; /// 1 2 3

    v[1] = 3;
    cout << v[0] << " " << v[1] << " " << v[2] << endl; /// 1 3 3

    cout << v.size() << endl; /// 3
    for ( int i = 0; i < v.size(); i++ ) cout << v[i] << " "; /// 1 3 3
    cout << endl;

    vector <int> v1 = { 2, 3, 4 };

    cout << v1.size() << endl; /// 3
    for ( int i = 0; i < v1.size(); i++ ) cout << v1[i] << " "; /// 2 3 4
    cout << endl;

    v.clear();
    cout << v.size() << endl; /// 0
    cout << v.empty() << endl; /// 1
    cout << v1.empty() << endl; /// 0

    v1.resize(5);
    cout << v1.size() << endl; /// 5
    for ( int i = 0; i < v1.size(); i++ ) cout << v1[i] << " "; /// 2 3 4 0 0
    cout << endl;

    vector<int> a(5);

    cout << a.size() << endl; /// 5
    for ( int i = 0; i < a.size(); i++ ) cout << a[i] << " "; /// 0 0 0 0 0
    cout << endl;

    a = v1;

    for ( auto u : a ) cout << u << " "; /// 2 3 4 0 0
    cout << endl;

    vector<int>::iterator it;
    for ( it = a.begin(); it != a.end(); it++ ) cout << *it << " "; /// 2 3 4 0 0
    cout << endl;

    a = { 3, 4, 5, 1, 2 };

    sort ( a.begin(), a.end() ); ///O(n*log2(n))

    for ( auto u : a ) cout << u << " "; /// 1 2 3 4 5
    cout << endl;

    sort ( a.rbegin(), a.rend() );

    for ( auto u : a ) cout << u << " "; /// 5 4 3 2 1
    cout << endl;


    a = { 3, 4, 5, 1, 2 };
    sort ( a.begin(), a.end(), greater<int>() );

    for ( auto u : a ) cout << u << " "; /// 5 4 3 2 1
    cout << endl;

    a = { 3, 4, 5, 1, 2 };

    reverse( a.begin(), a.end() );

    for ( auto u : a ) cout << u << " "; /// 2 1 5 4 3
    cout << endl;

    cout << a.back() << endl; /// 3
    a.pop_back(); /// O(1) complexity.
    cout << a.back() << endl; /// 4


    a = { 3, 4, 5, 1, 2 };
    cout << *a.begin() << endl; /// 3

    a.erase( a.begin() ); /// O(n) complexity.
    for ( auto u : a ) cout << u << " "; /// 4 5 1 2
    cout << endl;

    a.erase( a.begin()+2 );
    for ( auto u : a ) cout << u << " "; /// 4 5 2
    cout << endl;

    a = { 1, 1, 2, 2, 2, 3, 3 };
    unique( a.begin(), a.end() );

    for ( auto u : a ) cout << u << " "; /// 1 2 3 2 2 3 3
    cout << endl;


    a = { 1, 1, 2, 2, 2, 3, 3 };
    int n = unique( a.begin(), a.end() ) - a.begin();

    cout << n << endl; /// 3
    for ( int i = 0; i < n; i++ ) cout << a[i] << " "; /// 1 2 3
    cout << endl;

    a = { 2, 3, 1, 5 };
    cout << max_element( a.begin(), a.end() ) - a.begin() << endl; /// 3
    cout << *max_element( a.begin(), a.end() ) << endl; /// 5

    return 0;
}



//Class - 2 ( Discussion on Practice problems of STL Vector )



///A. Sereja and Dima ( Codeforces )


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v (n);

    for ( int i = 0; i < n; i++ ) cin >> v[i];

    int s = 0, d = 0, f1 = 1;

    while ( !v.empty() ) {
        if ( f1 == 1 ) {
            if ( v[0] > v.back() ) {
                s += v[0];
                v.erase( v.begin() );
            }
            else {
                s += v.back();
                v.pop_back();
            }

            f1 = 2;
        }

        else {
            if ( v[0] > v.back() ) {
                d += v[0];
                v.erase( v.begin() );
            }
            else {
                d += v.back();
                v.pop_back();
            }

            f1 = 1;
        }
    }

    cout << s << " " << d << endl;


    return 0;
}


// 852. Peak Index in a Mountain Array
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {

        int i = max_element( A.begin(), A.end() ) - A.begin();

        return i;
    }
};

//1502. Can Make Arithmetic Progression From Sequenc


class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {

        sort ( arr.begin(), arr.end() );

        int d = arr[1] - arr[0];
        for ( int i = 2; i < arr.size(); i++ ) {
            if ( arr[i] - arr[i-1] != d ) return false;
        }

        return true;
    }
};

//Distinct Count


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while ( t-- ) {
      int n, x;
      cin >> n >> x;

      vector<int> v(n);
      for ( int i = 0; i < n; i++ ) cin >> v[i];

      sort ( v.begin(), v.end() );
      int Sz = unique ( v.begin(), v.end() ) - v.begin();

      if ( Sz == x ) cout << "Good" << endl;
      else if ( Sz > x ) cout << "Average" << endl;
      else cout << "Bad" << endl;

    }


    return 0;
}


// Class - 3 ( Almost everything about STL String )


///In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

int main ()
{
    /// Declare string
    string s;

    /// Assign string
    s = "abcdf";

    /// Printing size of string
    cout << s.size() << endl; /// 5

    /// Printing string
    cout << s << endl; /// abcdf

    /// Pushing char back to a string
    s += 'b';
    s += 'c';
    cout << s << endl; /// abcdfbc

    /// Taking input string
    cin >> s;
    cout << s << endl;

    s = "asdfgg";

    /// Checking is a string empty or not
    string s1;
    cout << s.empty() << endl; /// 0
    cout << s1.empty() << endl; /// 1

    /// Assigning an string in another string variable
    s1 = s;
    s.clear();

    cout << s.empty() << endl; /// 1
    cout << s1.empty() << endl; /// 0

    /// assigning 'k' in 0-th index
    s = "asdfg";
    s[0] = 'k';
    cout << s << endl;  ///kasdfg;

    s = "abc";
    s1 = "def";

    /// String concatenation
    string tmp = s + s1;
    cout << tmp << endl; /// abcdef

    /// String iterator
    string::iterator it;
    for ( it = s.begin(); it != s.end(); it++ ) cout << *it; /// abc
    cout << endl;

    /// For each loop
    for ( auto c : s ) cout << c; /// abc
    cout << endl;


    s = "asd";
    tmp = s;

    /// Comparing two strings
    if ( tmp == s ) cout << "Yes Match\n";
    else "No Match\n";

    /// String reverse and checking is a string is palindrome or not
    s = "asddsa";
    tmp = s;
    reverse( tmp.begin(), tmp.end() );

    if ( tmp == s ) cout << "Yes Palindrome" << endl;
    else cout << "Not Palindrome" << endl;

    /// String sorting in non-decreasing order
    s = "gfds";
    sort ( s.begin(), s.end() );
    cout << s << endl; /// dfgs

    /// String sorting in non-increasing order
    sort ( s.rbegin(), s.rend() );
    cout << s << endl; /// sgfd

    /// Getting all unique elements of a string. Be care full, string should be sorted.
    s = "aaadddsss";
    int n = unique( s.begin(), s.end() ) - s.begin();
    for ( int i = 0; i < n; i++ ) cout << s[i];/// ads
    cout << endl;

    /// Getting maximum element of string
    cout << *max_element( s.begin(), s.end() ) << endl; /// s
    /// Getting minimum element of string
    cout << *min_element( s.begin(), s.end() ) << endl; /// a

    /// When we want to take input with space
    /// input : Muhammad Shahriar Alam

    char c;
    cin >> c;
    getline( cin, s );
    s = c + s;

    cout << s << endl; /// Muhammad Shahriar Alam

    /// If we need to sort some string on lexicographical order :

    vector<string> v;
    v.push_back( "Muhammad" );
    v.push_back( "Nova" );
    v.push_back( "Maslenia Mubarrat" );
    v.push_back( "CPS Academy" );
    v.push_back( "Rashedul Alam Anik" );
    v.push_back( "Farhan sadik Sakib" );
    v.push_back( "Gazi Mohaimin Iqbal" );

    sort ( v.begin(), v.end() );
    for ( auto u : v ) cout << u << endl;

    /**

    Out put :

    CPS Academy
    Farhan sadik Sakib
    Gazi Mohaimin Iqbal
    Maslenia Mubarrat
    Muhammad
    Nova
    Rashedul Alam Anik

    */

	s = "asdf";

	s.pop_back(); /// removes last char of string
	cout << s.back() << endl; /// print last char of string

	v.clear();

	v = { "Shahriar", "Shahriar", "Momo", "Momo", "Sharif", "Sharif" };
	int Sz = unique ( v.begin(), v.end() ) - v.begin();


	cout << Sz << endl; /// Number of unique strings in vector v;
	for ( int i = 0; i < Sz; i++ ) cout << v[i] << endl; /// Prints all unique strings in vector v

	/// Converting int to string
	int a = 123;
	s = to_string (a);
	cout << s << endl; /// 123
	s[0] = '3';
	cout << s << endl; /// 323

	/// Converting string to integer

	s = "123";
	a = stoi ( s );
	cout << a << endl; /// 123
	a++;
	cout << a << endl; /// 124;

	/// Deleting a substring from string

	s = "ShaKAKAhriar";

	s.erase ( s.begin()+3, s.begin()+7 ); /// erase substring "KAKA" from string s
	cout << s << endl;


	/// Copying a substring of a string to a string
	tmp = "Gagha Alam Gadha";
	s = "Shahriar ";

	copy ( tmp.begin()+6, tmp.begin()+10, back_inserter ( s ) ); /// copying "Alam substring to string s back.
	cout << s << endl; /// Shahriar Alam

	/// Erasing all occurrence of a specific char from string.

	s = "aaassdddaaasdd";
	s.erase ( remove ( s.begin(), s.end(), 'a' ), s.end() ); /// removes all 'a' from s
	cout << s << endl;

	/// Checking is a string is substring of another string in O(n*m)
	s = "ashshasdakks";

	if ( s.find( "asd" ) != -1 ) cout << "Substring found";
	else cout << "Not found";


    return 0;
}

//Class - 4 ( Discussion on Practice problems of STL String

       //A. String Task ( Codeforces )

             /// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool isVowel ( char c )
{
    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'  );
}

int main()
{
    optimize();

    string s, ans;

    cin >> s;

    for ( auto u : s ) {
        char c = tolower ( u );

        if ( isVowel ( c ) == 0 ) {
            ans += '.';
            ans += c;
        }
    }

    cout << ans << endl;

}
//The Palindrome ( Hacker earth )
/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{
    optimize();

    int t;
    cin >> t;

    while ( t-- ) {
        string s;
        cin >> s;

        string tmp = s;
        reverse ( tmp.begin(), tmp.end() );


        if ( s == tmp ) cout << "Yes\n";
        else cout << "No\n";
    }
}

//Sum of Digit is Palindrome or not ( Geeks for Geeks )

/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{
    optimize();

    int t;
    cin >> t;

    while ( t-- ) {

        string s;
        cin >> s;

        int digitSum = 0;

        for ( auto u : s ) {
            digitSum += ( u - '0' );
        }

        string str = to_string ( digitSum );

        string tmp = str;

        reverse ( tmp.begin(), tmp.end() );

        if ( tmp == str ) cout << "YES\n";
        else cout << "NO\n";


    }
}
//A. Petya and Strings ( Codeforces )

/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{
    optimize();

    string s1, s2;
    cin >> s1 >> s2;

    for ( int i = 0; i < s1.size(); i++ ) s1[i] = tolower ( s1[i] );
    for ( int i = 0; i < s2.size(); i++ ) s2[i] = tolower ( s2[i] );

    if ( s1 < s2 ) cout << "-1";
    else if ( s1 > s2 ) cout << "1";
    else cout << "0";

}

//A. Haiku ( Codeforces )
/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool isVowel ( char c )
{
    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' );
}

int main()
{
    optimize();

    vector<string> v;
    int cnt[] = { 5, 7, 5 };

    for ( int i = 0; i < 3; i++ ) {
        string s;
        char c;
        cin >> c;
        getline ( cin, s );
        s = c + s;

        v.push_back ( s );
    }

    for ( int i = 0; i < 3; i++ ) {
        int c = 0;

        for ( auto u : v[i] ) {
            if ( isVowel(u) ) c++;
        }

        if ( c != cnt[i] ) return cout << "NO\n", 0;
    }

    cout << "YES\n";
}
//LexoGeek ( Hacker earth )

/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    optimize();

    int t;
    cin >> t;

    while ( t-- ) {
        string s;
        cin >> s;

        if ( next_permutation ( s.begin(), s.end() ) ) {
            cout << s << endl;
        }
        else cout << "no answer\n";
    }

}
//Class - 5 ( Almost everything about STL pair with practice problems )

///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


bool cmp ( const pair<int,int> &p1, const pair<int, int> &p2  )
{
	if ( p1.first > p2.first ) return 1;
	if ( p1.first == p2.first ) return ( p1.second < p2.second );
	return 0;
}

int main()
{

	/// Declear a pair o integers

	pair<int,int> p;

	p = make_pair ( 2, 3 );
	cout << p.first << " " << p.second << endl; /// 2 3

	p.first++;
	cout << p.first << " " << p.second << endl; /// 3 3

	pair<int, int> p1 = { 2, 3 };
	pair<int, int> p2 = { 1, 6 };

	/// Getting minimum of 2 pairs
	p = min ( p1, p2 );
	cout << p.first << " " << p.second << endl; /// 1 6

	/// Getting maximum of 2 pairs
	p = max ( p1, p2 );
	cout << p.first << " " << p.second << endl; /// 2 3

	/// Sorting pair of integers

	vector<pair<int,int>> v;
	v.push_back ( { 1, 5 } );
	v.push_back ( { 2, 5 } );
	v.push_back ( { 7, 1 } );
	v.push_back ( { 3, 6 } );
	v.push_back ( { 3, 6 } );
	v.push_back ( { 7, 1 } );

	sort ( v.begin(), v.end() );
	for ( auto u : v ) cout << u.first << " " << u.second << endl;
	cout << endl;
	/**
	1 5
	2 5
	3 6
	3 6
	7 1
	7 1

	*/

	/// Making unique pair of integers

	int Sz = unique ( v.begin(), v.end() ) - v.begin();
	cout << Sz << endl;
	for ( int i = 0; i < Sz; i++ ) cout << v[i].first << " " << v[i].second << endl;
	cout << endl;

	/**
	4
	1 5
	2 5
	3 6
	7 1

	*/

	/// sorting using comparator
	v = { {2, 3}, {4, 5}, {1, 5}, {1, 6}, {6, 7}, {6, 8} };

	sort ( v.begin(), v.end(), cmp );
	for ( auto u : v ) cout << u.first << " " << u.second << endl;
	cout << endl;

	/**

	6 7
	6 8
	4 5
	2 3
	1 5
	1 6

	*/


	v = { {2, 3}, {4, 5}, {1, 5}, {1, 6}, {6, 7}, {6, 8} };

	for ( int i = 0; i < v.size(); i++ ) v[i].first *= -1;
	sort ( v.begin(), v.end() );
	for ( auto u : v ) cout << (u.first*-1) << " " << u.second << endl;
	cout << endl;

	/**

	6 7
	6 8
	4 5
	2 3
	1 5
	1 6

	*/


	return 0;
}

//A. Indian Summer ( Codeforces )


/** In the Name of ALLAH */


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    optimize();

    int n;
    cin >> n;
    vector<pair<string, string>> v (n);

    for ( int i = 0; i < n; i++ ) {
        cin >> v[i].first >> v[i].second;
    }

    sort ( v.begin(), v.end() );
    int Sz = unique ( v.begin(), v.end() ) - v.begin();
    cout << Sz << endl;


}

//Count distinct pairs with difference k ( Geeks for Geeks )

/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;


#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{
    optimize();

    int t;
    cin >> t;

    while ( t-- ) {
        string s;
        cin >> s;

        string tmp = s;
        reverse ( tmp.begin(), tmp.end() );


        if ( s == tmp ) cout << "Yes\n";
        else cout << "No\n";
    }
}

//A. Rank List ( Codeforces )


/** In the Name of ALLAH */


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);



int main()
{
    optimize();

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v (n);

    for ( int i = 0; i < n; i++ ) {
        cin >> v[i].first >> v[i].second;
        v[i].first *= -1;
    }

    sort ( v.begin(), v.end() );

    int ans = 0;

    for ( auto u : v ) {
        if ( u == v[k-1] ) ans++;
    }

    cout << ans << endl;

}

//Class - 6 (Almost everything about STL Map with practice problems : Part-1)

// Find the Frequency (Geeks for Geeks ) [Google interview question

int findFrequency(vector<int> v, int x){

    map<long long, int> cnt;

    for ( auto u : v ) cnt[u]++;
    return cnt[x];

}
//Twice counter ( Geeks for Geeks ) [Amazon interview question]

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;

    while ( t-- ) {
        int n;
        cin >> n;
        map<string, int> cnt;

        for ( int i = 0; i < n; i++ ) {
            string s;
            cin >> s;
            cnt[s]++;
        }

        int ans = 0;

        for ( auto u : cnt ) {
            if ( u.second == 2 ) ans++;
        }

        cout << ans << endl;
    }
}
//Word with maximum frequency ( Geeks for Geeks ) [Amazon interview question

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin >> t;

    while ( t-- ) {
        string s;
        char c;
        cin >> c;
        getline ( cin, s );
        s = c + s;

        string tmp;

        vector<string> v; /// the devil in the sky
        for ( auto u : s ) {
            if ( isspace( u ) ) {
                v.push_back ( tmp );
                tmp.clear();
            }

            else tmp += u;
        }

        v.push_back ( tmp );

        map<string,int> cnt;

        int mxFrq = 0;
        for ( auto u : v ) {
            cnt[u]++;
            mxFrq = max ( mxFrq, cnt[u] );
        }

        string ans;

        for ( auto u : v ) {
            if ( cnt[u] == mxFrq ) {
                ans = u;
                break;
            }
        }

        cout << ans << " " << mxFrq << endl;



    }
}

//C - Good Sequence ( Atcoder )




#include<bits/stdc++.h>
using namespace std;


int main()
{
    map<int, int> cnt;
    int n;
    cin >> n;
    for ( int i = 1; i <= n; i++ ) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    int ans = 0;

    for ( auto u : cnt ) {
        if ( u.second >= u.first ) ans += ( u.second - u.first );
        else ans += u.second;
    }

    cout << ans << endl;
}


//Class - 7 ( STL Map & practice problem Part - 2 )



// A. Tom Riddle's Diary ( Codeforces )

/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{

    optimize();

    int n;
    cin >> n;

    map<string, bool> vis;

    while ( n-- ) {
        string s;
        cin >> s;
        if ( vis[s] == 1 ) cout << "YES\n";
        else cout << "NO\n";

        vis[s] = 1;
    }

}

//C. Registration system ( Codeforces )

/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{

    optimize();

    int n;
    cin >> n;

    map<string, int> cnt;

    while ( n-- ) {
        string s;
        cin >> s;

        if ( cnt[s] == 0 ) cout << "OK\n";
        else cout << s << cnt[s] << endl;

        cnt[s]++;
    }

}

//B. Radio Station ( Codeforces )

/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{

    optimize();

    int n, m;
    cin >> n >> m;

    map<string, string> ipName;

    for ( int i = 0; i < n; i++ ) {
        string name, ip;
        cin >> name >> ip;

        ipName[ip] = name;
    }

    while ( m-- ) {
        string s1, ip;
        cin >> s1 >> ip;

        ip.pop_back();
        cout << s1 << " " << ip << "; #" << ipName[ip] << endl;
    }
}
//RPLD - Database ( SPOJ )

/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{

    optimize();

    int t;
    cin >> t;

    for ( int tc = 1; tc <= t; tc++ ) {
        int n, m;
        cin >> n >> m;

        map<pair<int, int>, bool> vis;

        bool done = 1;
        while ( m-- ) {
            int a, b;
            cin >> a >> b;

            if ( vis[{a, b}] ) done = 0;
            vis[{a, b}] = 1;
        }

        if ( done == 1 ) cout << "Scenario #" << tc << ": possible" << endl;
        else cout << "Scenario #" << tc << ": impossible" << endl;

    }
}
//C. Boxes Packing ( Codeforces )
/// In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 5e3+123;
int a[mx];

int main()
{

    optimize();

    map<int, int> freq;
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i];
        freq[a[i]]++;
    }

    int ans = 0;

    for ( int i = 0; i < n; i++ ) ans = max ( ans, freq[a[i]] );
    cout << ans << endl;
}

//]Class - 8 ( Almost everything about STL Set )

///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


int main()
{
    /// Declaration of set of integers
	set<int> s = { 1, 1, 2, 1, 3 };

	/// Printing size and elements
	cout << s.size() << endl;
	for ( auto u : s ) cout << u << " "; /// 1 2 3
	cout << endl;

	set<int>:: iterator it;
	for ( it = s.begin(); it != s.end(); it++ ) cout << *it << " "; /// 1 2 3
	cout << endl;

	/// clearing and checking is empty set
	s.clear();
	cout << s.empty() << endl; /// 1

	/// inserting in set
	s.insert ( 1 );
	s.insert ( 1 );
	s.insert ( 1 );
	s.insert ( 2 );
	s.insert ( 1 );
	s.insert ( 3 );

	cout << s.size() << endl; /// 3
	for ( auto u : s ) cout << u << " "; /// 1 2 3
	cout << endl;

	/// checking is specific element is in a set
	cout << s.count ( 2 ) << endl; /// 1
	cout << s.count ( 4 ) << endl; /// 0


    /// Front element in set
    cout << *s.begin() << endl; /// 1

    /// Last element in set
    cout << *(--s.end()) << endl; /// 3
    cout << *s.rbegin() << endl; /// 3


    /// Erase an element;

    s = { 1, 2, 3, 4, 5, 6 };

    s.erase ( 2 );
    cout << s.size() << endl; /// 5
	for ( auto u : s ) cout << u << " "; /// 1 3 4 5 6
	cout << endl;

	s.erase ( 10 );
    cout << s.size() << endl; /// 5
	for ( auto u : s ) cout << u << " "; /// 1 3 4 5 6
	cout << endl;


	/// Erasing front element in set

	s = { 1, 2, 3, 4, 5, 6 };

    s.erase ( s.begin() );
    cout << s.size() << endl; /// 5
	for ( auto u : s ) cout << u << " "; /// 2 3 4 5 6
	cout << endl;

	/// Erasing back element in set

	s = { 1, 2, 3, 4, 5, 6 };

    s.erase ( --s.end() );
    cout << s.size() << endl; /// 5
	for ( auto u : s ) cout << u << " "; /// 1 2 3 4 5
	cout << endl;


	/// set of pair
	set<pair<int, int>> s1;

	s1.insert ( { 1, 2 } );
	s1.insert ( { 1, 2 } );
	s1.insert ( { 4, 2 } );
	s1.insert ( { 4, 3 } );
	s1.insert ( { 2, 2 } );
	s1.insert ( { 2, 1 } );

	/**

	Output :

	5
    1 2
    2 1
    2 2
    4 2
    4 3

    */

	cout << s1.size() << endl;
	for ( auto u : s1 ) cout << u.first << " " << u.second << endl;

	/// Set of string

	set<string> s2;

	s2.insert ( "momo" );
	s2.insert ( "momo" );
	s2.insert ( "prety" );
	s2.insert ( "prety" );
	s2.insert ( "shahriar" );
	s2.insert ( "nobel" );
	s2.insert ( "sharif" );
	s2.insert ( "proma" );

	cout << s2.size() << endl;
	for ( auto u : s2 ) cout << u << endl;

	/**

	Output :

	6
    momo
    nobel
    prety
    proma
    shahriar
    sharif

    */

    /// set in discanding order
    set<int, greater<int>> s3 = {3, 4, 1, 2};
    for ( auto u : s3 ) cout << u << " "; /// 4 3 2 1
    cout << endl;


    set<string, greater<string>> s4;

	s4.insert ( "momo" );
	s4.insert ( "momo" );
	s4.insert ( "prety" );
	s4.insert ( "prety" );
	s4.insert ( "shahriar" );
	s4.insert ( "nobel" );
	s4.insert ( "sharif" );
	s4.insert ( "proma" );

	cout << s4.size() << endl;
	for ( auto u : s4 ) cout << u << endl;

	/**
	Output :

	6
    sharif
    shahriar
    proma
    prety
    nobel
    momo

    */

    set<pair<int, int>, greater<pair<int,int>>> s5;

	s5.insert ( { 1, 2 } );
	s5.insert ( { 1, 2 } );
	s5.insert ( { 4, 2 } );
	s5.insert ( { 4, 3 } );
	s5.insert ( { 2, 2 } );
	s5.insert ( { 2, 1 } );


	cout << s5.size() << endl;
	for ( auto u : s5 ) cout << u.first << " " << u.second << endl;

	/**

	Output :
	5
    4 3
    4 2
    2 2
    2 1
    1 2

    */


	return 0;
}


//Class - 9 ( STL Set Practice problems )

//Sets-STL ( Hackerrank )
///In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;


int main()
{
    set<int> s;

    int q;
    cin >> q;

    while ( q-- ) {
        int typ, x;
        cin >> typ >> x;

        if ( typ == 1 ) s.insert ( x );
        else if ( typ == 2 ) s.erase ( x );
        else {
            if ( s.count ( x ) == 1 ) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}

//C++ STL | Set 6 (set) ( Geeks for Geeks )



#include <bits/stdc++.h>
using namespace std;

void insert(set<int> &s,int x);

void print_contents(set<int> &s);

void erase(set<int> &s,int x);

int find(set<int> &s,int x);

int size(set<int> &s);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		set<int> s;
		int q;
		cin>>q;
		while(q--)
		{
			char c;
			cin>>c;
			if(c=='a')
			{
				int x;
				cin>>x;
				insert(s,x);
			}
			if(c=='b')
			{
				print_contents(s);
			}
			if(c=='c')
			{
				int x;
				cin>>x;
				erase(s,x);
			}
			if(c=='d')
			{
				int x;
				cin>>x;
				cout<<find(s,x)<<" ";
			}
                       if(c=='e')
                       cout<<size(s)<<" ";

		}
cout<<endl;
	}
	return 0;
}// } Driver Code Ends


/* You are required to complete below methods */

/*inserts an element x to the set s */
void insert(set<int> &s,int x)
{
    s.insert ( x );
}

/*prints the contents of the set s */
void print_contents(set<int> &s)
{
    for ( auto u : s ) cout << u << " ";
}

/*erases an element x from the set s */
void erase(set<int> &s,int x)
{
    s.erase ( x );
}

/*returns 1 if the element x is
present in set s else returns -1 */
int find(set<int> &s,int x)
{
    if ( s.count ( x ) == 1 ) return 1;
    else return -1;
}

/*returns the size of the set s */
int size(set<int> &s)
{
    return s.size();
}


//Set Operations ( Geeks for Geeks )


//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

set<int> setInsert(int arr[],int n); //Function to insert elements of array into a set and return a set


void setDisplay(set<int>s); //function to print the elements of the set


void setErase(set<int>&s,int x); //function to erase x from set if it exists


 // } Driver Code Ends


//User function Template for C++


set<int> setInsert(int arr[],int n)
{
    set<int>s;
    for ( int i = 0; i < n; i++ ) s.insert ( arr[i] );

    return s;

}


void setDisplay(set<int>s)
{
    for ( auto u : s ) cout << u <<  " ";
    cout<<endl;
}


void setErase(set<int>&s,int x)
{
    if ( s.count ( x ) ) {
        cout<<"erased "<<x;
        s.erase ( x );
    }

    //write else condition here
    else cout<<"not found";


    cout<<endl;
}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n]; //array of size n
        for(int i=0;i<n;i++)
        cin>>arr[i]; //Input the array

        set<int>s=setInsert(arr,n); //call the insert function that returns a set
        setDisplay(s);// display the inserted set
        int x;
        cin>>x; //x element that needs to be erased from set

        setErase(s,x); //try to erase x from set
        setDisplay(s); //print the set after erase operation


    }
	return 0;
}
  // } Driver Code Ends



  //A. I Wanna Be the Guy ( Codeforces )


  ///In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;


int main()
{
    set<int> s;
    int n;
    cin >> n;

    int p;
    cin >> p;
    for ( int i = 0; i < p; i++ ) {
        int a;
        cin >> a;
        s.insert ( a );
    }


    cin >> p;
    for ( int i = 0; i < p; i++ ) {
        int a;
        cin >> a;
        s.insert ( a );
    }

    if ( s.size () == n ) cout << "I become the guy.\n";
    else cout << "Oh, my keyboard!\n";
}
///217. Contains Duplicate ( LeetCode )

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for ( auto u : nums ) {
            s.insert ( u );
        }

        return ( s.size () != nums.size());
    }
};

//A. Second Order Statistics ( Codeforces )

///In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;


int main()
{
    set<int> s;
    int n;
    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        int a;
        cin >> a;
        s.insert ( a );
    }

    if ( s.size() == 1 ) cout << "NO\n";
    else {
        cout << *( ++s.begin() ) << endl;
    }
}

//////Class - 10 ( STL Multiset and practice problem )

//Multiset Operations ( Geeks for Geeks )
/// Declare multiset
    multiset<int> s;

    /// insert in multiset.
    s.insert( 1 );
    s.insert( 4 );
    s.insert( 2 );
    s.insert( 2 );

    /// Print multiset size and its elements using for each loop
    cout << s.size() << endl; /// 4
    for ( auto u : s ) cout << u << " "; /// 1 2 2 4
    cout << endl;

    ///Print it elements using iterator
    set<int>::iterator it;
    for ( it = s.begin(); it != s.end(); it++ ) cout << *it << " "; /// 1 2 2 4
    cout << endl;

    /// element erase in multiset
    s.erase( 2 );
    cout << s.size() << endl; /// 2
    for ( auto u : s ) cout << u << " "; /// 1 4
    cout << endl;

    s.insert( 2 );
    s.insert( 2 );

    it = s.find( 2 );
    if ( it != s.end() ) s.erase( it );

    cout << s.size() << endl; /// 3
    for ( auto u : s ) cout << u << " "; /// 1 2 4
    cout << endl;

    s.erase( 5 );
    cout << s.size() << endl; /// 3
    for ( auto u : s ) cout << u << " "; /// 1 2 4
    cout << endl;

    /// another way of multiset declare and assigning a multiset into another
    multiset<int> tmp = { 6, 6, 1, 2, 3, 4, 5 };
    s = tmp;
    cout << s.size() << endl; /// 7
    for ( auto u : s ) cout << u << " "; /// 1 2 3 4 5 6 6
    cout << endl;

    /// Finding pointer where element 2 is located
    it = s.find( 2 );

    /// Checking is a element exist in multiset
    if ( it != s.end() ) cout << "Element exist\n";
    else cout << "Element not exist\n";

    /// Counting number of occurrence's of an element of multiset
    cout << s.count( 6 ) << endl; /// 2
    cout << s.count( 10 ) << endl; /// 0

    /// Checking is a multiset is empty of not
    cout << s.empty() << endl; /// 0

    /// Clearing full multiset
    s.clear();
    cout << s.empty() << endl; /// 1

    /// Printing smallest element in multiset
    s = tmp;
    cout << *s.begin() << endl; /// 1

    /// Printing largest element in a multiset
    cout << *(--s.end() ) << endl; /// 6
    cout << *s.rbegin() << endl; /// 6

    return 0;
}

#include<bits/stdc++.h>
using namespace std;


int main()
{
    /// Declaration of set of integers
	multiset<int> s = { 1, 1, 2, 1, 3 };

	/// Printing size and elements
	cout << s.size() << endl; /// 5
	for ( auto u : s ) cout << u << " "; /// 1 1 1 2 3
	cout << endl;

	multiset<int>:: iterator it;
	for ( it = s.begin(); it != s.end(); it++ ) cout << *it << " "; /// 1 1 1 2 3
	cout << endl;

	/// clearing and checking is empty set
	s.clear();
	cout << s.empty() << endl; /// 1

	/// inserting in set
	s.insert ( 1 );
	s.insert ( 1 );
	s.insert ( 1 );
	s.insert ( 2 );
	s.insert ( 1 );
	s.insert ( 3 );

	cout << s.size() << endl; /// 6
	for ( auto u : s ) cout << u << " "; /// 1 1 1 1 2 3
	cout << endl;

	/// checking is specific element is in a set
	cout << s.count ( 1 ) << endl; /// 4
	cout << s.count ( 4 ) << endl; /// 0

    /// Front element in set
    cout << *s.begin() << endl; /// 1

    /// Last element in set
    cout << *(--s.end()) << endl; /// 3
    cout << *s.rbegin() << endl; /// 3


    /// Erase an element;

    s = { 1, 2, 2, 3, 3, 3,4, 5, 6 };

    s.erase ( 2 );
    cout << s.size() << endl; /// 7
	for ( auto u : s ) cout << u << " "; /// 1 3 3 3 4 5 6
	cout << endl;

	if ( s.find( 3 ) != s.end() ) s.erase ( s.find(3) );
    cout << s.size() << endl; /// 6
	for ( auto u : s ) cout << u << " "; /// 1 3 3 4 5 6
	cout << endl;


	/// Erasing front element in set

	s = { 1, 2, 3, 4, 5, 6 };

    s.erase ( s.begin() );
    cout << s.size() << endl; /// 5
	for ( auto u : s ) cout << u << " "; /// 2 3 4 5 6
	cout << endl;

	/// Erasing back element in set

	s = { 1, 2, 3, 4, 5, 6 };

    s.erase ( --s.end() );
    cout << s.size() << endl; /// 5
	for ( auto u : s ) cout << u << " "; /// 1 2 3 4 5
	cout << endl;


	/// set of pair
	multiset<pair<int, int>> s1;

	s1.insert ( { 1, 2 } );
	s1.insert ( { 1, 2 } );
	s1.insert ( { 4, 2 } );
	s1.insert ( { 4, 3 } );
	s1.insert ( { 2, 2 } );
	s1.insert ( { 2, 1 } );

	/**

	Output :

	6
    1 2
    1 2
    2 1
    2 2
    4 2
    4 3

    */

	cout << s1.size() << endl;
	for ( auto u : s1 ) cout << u.first << " " << u.second << endl;

	/// Set of string

	multiset<string> s2;

	s2.insert ( "momo" );
	s2.insert ( "momo" );
	s2.insert ( "prety" );
	s2.insert ( "prety" );
	s2.insert ( "shahriar" );
	s2.insert ( "nobel" );
	s2.insert ( "sharif" );
	s2.insert ( "proma" );

	cout << s2.size() << endl;
	for ( auto u : s2 ) cout << u << endl;

	/**

	Output :

	8
	momo
	momo
	nobel
	prety
	prety
	proma
	shahriar
	sharif

    */

    /// set in discanding order
    multiset<int, greater<int>> s3 = {3, 4, 1, 2};
    for ( auto u : s3 ) cout << u << " "; /// 4 3 2 1
    cout << endl;


    multiset<string, greater<string>> s4;

	s4.insert ( "momo" );
	s4.insert ( "momo" );
	s4.insert ( "prety" );
	s4.insert ( "prety" );
	s4.insert ( "shahriar" );
	s4.insert ( "nobel" );
	s4.insert ( "sharif" );
	s4.insert ( "proma" );

	cout << s4.size() << endl;
	for ( auto u : s4 ) cout << u << endl;

	/**
	Output :

	8
	sharif
	shahriar
	proma
	prety
	prety
	nobel
	momo
	momo

    */

    multiset<pair<int, int>, greater<pair<int,int>>> s5;

	s5.insert ( { 1, 2 } );
	s5.insert ( { 1, 2 } );
	s5.insert ( { 4, 2 } );
	s5.insert ( { 4, 3 } );
	s5.insert ( { 2, 2 } );
	s5.insert ( { 2, 1 } );


	cout << s5.size() << endl;
	for ( auto u : s5 ) cout << u.first << " " << u.second << endl;

	/**

	Output :
	6
	4 3
	4 2
	2 2
	2 1
	1 2
	1 2

    */


	return 0;
}


//Initial Template for C++
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

multiset<int> multisetInsert(int arr[],int n); //Function to insert elements of array into a multiset and return a multiset


void multisetDisplay(multiset<int>s); //function to print the elements of the multiset


void multisetErase(multiset<int>&s,int x); //function to erase x from multiset if it exists


 // } Driver Code Ends


//User function Template for C++


multiset<int> multisetInsert(int arr[],int n)
{
    multiset<int> ret;
    for ( int i = 0; i < n; i++ )  ret.insert ( arr[i] );
    return ret;
}


void multisetDisplay(multiset<int>s)
{
    for ( auto u : s ) cout << u << " ";
    cout << endl;
}


void multisetErase(multiset<int>&s,int x)
{
    if ( s.count ( x ) >= 1 ) {
        s.erase ( x );
        cout << "erased " << x << endl;
    }
    else cout << "not found" << endl;

}

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n]; //array of size n
        for(int i=0;i<n;i++)
        cin>>arr[i]; //Input the array

        multiset<int>s=multisetInsert(arr,n); //call the insert function that returns a multiset
        multisetDisplay(s);// display the inserted multiset
        int x;
        cin>>x; //x element that needs to be erased from multiset

        multisetErase(s,x); //try to erase x from multiset
        multisetDisplay(s); //print the multiset after erase operation


    }
	return 0;
}



  // } Driver Code Ends

  //Class - 11 ( STL Stack and practice problems )

  #include<bits/stdc++.h>
using namespace std;

int main()
{


    stack<int> st;

    st.push ( 1 );
    st.push ( 3 );
    st.push ( 4 );
    st.push ( 2 );

    cout << st.top() << endl; /// 2
    cout << st.size() << endl; /// 4;

    while ( !st.empty() ) {
        cout << st.top() << " "; /// 2 4 3 1
        st.pop();
    }


    return 0;
}

  //balanced brackets ( Hacker Earth)

  ///In the name of ALLAH
#include<bits/stdc++.h>
using namespace std;

bool isBalanced ( char c1, char c2 )
{
    return  ( c1 == '(' && c2 == ')' ) || ( c1 == '{' && c2 == '}' ) || ( c1 == '[' && c2 == ']' );
}

int main()
{
    int n ;
    cin >> n;

    while ( n-- ) {
        string s;
        cin >> s;

        stack<char> st;
        bool done = 1;

        for ( auto u : s ) {
            if ( u == '(' || u == '{' || u == '[' ) st.push ( u );
            else {
                if ( st.empty() ) {
                    done = 0;
                    break;
                }
                else {
                    if ( isBalanced( st.top(), u ) ) {
                        st.pop();
                    }
                    else {
                        done = 0;
                        break;
                    }
                }
            }
        }

        if ( !st.empty() ) done = 0;

        if ( done ) cout << "YES\n";
        else cout << "NO\n";

    }

}

//Special Stack ( Geeks for Geeks )

#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}// } Driver Code Ends


/*Complete the function(s) below*/
void push(int a)
{
     s.push (a);
}

bool isFull(int n)
{
     return n == s.size();
}

bool isEmpty()
{
    return s.empty();
}

int pop()
{
    s.pop();
}

int getMin()
{
    int mn = 2e9;

    while ( !s.empty() ) {
        mn = min ( s.top(), mn );
        s.pop();
    }

    return mn;
}

//682. Baseball Game ( LeetCode)

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;

        for ( auto u : ops ) {
            if ( u.size() > 1 ) {
                st.push ( stoi ( u ) );
            }
            else if ( isdigit ( u[0] ) ) {
                st.push ( u[0] - '0' );
            }
            else if ( u[0] == '+' ) {
                int a1 = -1, a2 = -1;

                if ( !st.empty() ) {
                    a1 = st.top();
                    st.pop();
                }

                if ( !st.empty() ) {
                    a2 = st.top();
                    st.pop();
                }

                if ( a2 != -1 ) {
                    st.push ( a2 );
                    st.push ( a1 );
                    st.push ( a1+a2 );
                }

                else if ( a1 != -1 ) {
                    st.push ( a1 );
                }
            }
            else if ( u[0] == 'D' ) {
                if ( !st.empty() ) {
                    st.push ( 2 * st.top() );
                }
            }
            else {
                if ( !st.empty() ) st.pop();
            }
        }

        long long ans = 0;

        while ( !st.empty() ) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

// 1047. Remove All Adjacent Duplicates In String ( LeetCode )

class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;

        for ( auto u : s ) {
            if ( !st.empty() ) {
                if ( !st.empty() && st.top() == u ) st.pop();
                else st.push(u);
            }
            else st.push(u);
        }

        s.clear();
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }

        reverse ( s.begin(), s.end() );
        return s;

    }
};

//Class - 12 ( Almost everything about Queue, Deque & Practice problems )

#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main()
{

    queue <int> q;
    q.push( 1 );
    q.push( 2 );
    q.push( 3 );
    q.push( 7 );


    cout << q.size() << endl; /// 4
    cout << q.front() << endl; /// 1

    while ( !q.empty() ) {
        cout << q.front () << " "; /// 1 2 3 7
        q.pop();
    }


    return 0;
}
// Queue Push & Pop ( Geeks for Geeks )

//Initial Template for C++
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

queue<int>_push(int arr[],int n);


void _pop(queue<int>s);


 // } Driver Code Ends





//User function Template for C++


//User function Template for C++

queue<int>_push(int arr[],int n)
{
    queue<int> q;

    for ( int i = 0; i < n; i++ ) q.push ( arr[i] );
    return q;

}

void _pop(queue<int>s)
{
    while ( !s.empty() ) {
        cout << s.front() << " ";
        s.pop();
    }
}


// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    queue<int>mys=_push(arr,n);
	    _pop(mys);
	    cout<<endl;



	}
	return 0;
}

  // } Driver Code Ends



  // Reverse First K elements of Queue ( Geeks for Geeks )


  //Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<ll> modifyQueue(queue<ll> q, int k);
int main(){
    ll t;
    cin>>t;
    while(t-->0){
        ll n,k;
        cin>>n>>k;
        queue<ll> q;
        while(n-->0){
            ll a;
            cin>>a;
            q.push(a);
        }
        queue<ll> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

queue<ll> modifyQueue(queue<ll> q, int k)
{

    stack<ll> st;
    queue<ll> ret;

    while ( k-- ) {
        st.push ( q.front() );
        q.pop();
    }

    while ( !st.empty() ) {
        ret.push ( st.top() );
        st.pop();
    }

    while ( !q.empty() ) {
        ret.push ( q.front() );
        q.pop();
    }

    return ret;


}

//Queue Reversal ( Geeks for Geeks )

//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<long long int> rev(queue<long long int> q);
int main()
{
    long long int test;
    cin>>test;
    while(test--)
    {
    queue<long long int> q;
    long long int n, var;
    cin>>n;
    while(n--)
    {
        cin>>var;
        q.push(var);
    }
    queue<long long int> a=rev(q);
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl;
    }
}// } Driver Code Ends


//function Template for C++

queue<long long int> rev(queue<long long int> q)
{
    queue<long long> ret;
    stack<long long> st;

     while ( !q.empty() ) {
        st.push ( q.front() );
        q.pop();
    }

    while ( !st.empty() ) {
        ret.push ( st.top() );
        st.pop();
    }

    return ret;

}

///////////// Deque

// Deque Implementations ( Geeks for Geeks )


#include<bits/stdc++.h>
using namespace std;

#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main()
{
    deque<int> q;
    q.push_back ( 1 );
    q.push_back ( 3 );
    q.push_front ( 2 );

    cout << q.front() << endl; /// 2
    cout << q.back() << endl; /// 3

    q.pop_back();
    cout << q.back() << endl; ///1

    q.pop_front();
    cout << q.front() << endl; /// 1

    cout << q.size() << endl; /// 1


    return 0;
}
//Initial Template for C++

// CPP code to implement dequeue functions
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends





//User function Template for C++

/* Function to push element to front
* dq : dqueue in which element is to be pushed
* x : element to be pushed
*/
void push_back_pb(deque<int> &dq, int x){

    dq.push_back(x);

}

/* Function to pop element from back
* dq : dqueue From which element is to be popped
*/
void pop_back_ppb(deque<int> &dq){

    if(!dq.empty()) dq.pop_back();

    return;

}

/* Function to return element from front
* dq : dqueue from which element is to be returned
*/
int front_dq(deque<int> &dq){

    if(!dq.empty()) return dq.front();
    else return -1;

}

/* Function to push element to front
* dq : dqueue in which element is to be pushed
* x : element to be pushed
*/
void push_front_pf(deque<int> &dq, int x){

    dq.push_front(x);

}


// { Driver Code Starts.

// Driver code
int main() {

	int testcase;
	cin >> testcase;

	// declaring deque
	deque<int> dq;

	while(testcase--){

	    int queries;
	    cin >> queries;

	    while(queries--){
	    string s;
	    cin >> s;

	    // if query is to push back
	    if(s == "pb"){
	        int x;
	        cin >> x;
	        push_back_pb(dq, x);
	        cout << dq.back() << endl;
	    }

	    // if query is to push front
	    if(s == "pf"){
	        int x;
	        cin >> x;
	        push_front_pf(dq, x);
	        cout << dq.front() << endl;
	    }

	    // if query is to pop back
	    if(s == "pp_b"){
	        pop_back_ppb(dq);
	        cout << dq.size() << endl;
	    }

	    // if query is to return front
	    if(s == "f"){
	        int x = front_dq(dq);
	        cout << x << endl;
	    }
	    }
	    dq.clear();
	}

	return 0;
}  // } Driver Code Ends

////Class - 13 ( Almost everything about STL Priority queue & Practice problem )

///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


int main()
{

	priority_queue<int> q;

	q.push ( 2 );
	q.push ( 4 );
	q.push ( 1 );

	cout << q.top() << endl; /// 4
	q.pop();
	cout << q.top() << endl; /// 2
	q.pop();

	q.push( 1 );
	q.push( 5 );
	q.push( 4 );
	q.push( 4 );

	while ( !q.empty() ) {
		cout << q.top() << " "; /// 5 4 4 1 1
		q.pop();
	}

	cout << endl;

	cout << q.size() << endl; /// 0

	priority_queue<int, vector<int>, greater<int>> qr;

	qr.push ( 2 );
	qr.push ( 4 );
	qr.push ( 1 );

	cout << qr.top() << endl; /// 1
	qr.pop();
	cout << qr.top() << endl; /// 2
	qr.pop();

	qr.push( 1 );
	qr.push( 5 );
	qr.push( 4 );
	qr.push( 4 );

	while ( !qr.empty() ) {
		cout << qr.top() << " "; /// 1 4 4 4 5
		qr.pop();
	}
	cout << endl;

	cout << qr.size() << endl; /// 0




	return 0;
}



//Monk and Multiplication(HackerEarth)


#include<bits/stdc++.h>
using namespace std;

const int mx = 1e5+123;
int a[mx];

int main()
{
    priority_queue <int> q;

    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> a[i];

    for ( int i = 0; i < n; i++ ) {
        q.push ( a[i] );
        if ( q.size() >= 3 ) {
            int a1 = q.top();
            q.pop();

            int a2 = q.top();
            q.pop();

            int a3 = q.top();
            q.pop();

            cout << 1LL * a1 * a2 * a3 << endl;

            q.push ( a1 );
            q.push ( a2 );
            q.push ( a3 );
        }
        else cout << -1 << endl;


    }
}

//Monk And Champions League ( HackerEarth )


#include<bits/stdc++.h>
using namespace std;

const int mx = 1e5+123;
int a[mx];

int main()
{

    int m, n;
    cin >> m >> n;
    priority_queue<long long> q;

    for ( int i = 0; i < m; i++ ) {
        int x;
        cin >> x;
        q.push ( x );
    }

    long long ans = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( !q.empty() ) {
            int a = q.top();
            q.pop();

            ans += a;
            a--;
            if ( a > 0 ) q.push ( a );
        }
    }

    cout << ans << endl;
}

//REDARR2 - Reduce the array ( Spoj )

///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {			cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


int dx[] = { 0, 0, +1, -1, -1  +1, -1, +1 };
int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };

int main()
{
	optimize();

	int t;
	cin >> t;

	while ( t-- ) {
		int n;
		cin >> n;
		priority_queue<ll> q;

		for ( int i = 0; i < n; i++ ) {
			int a;
			cin >> a;
			q.push ( -a );
		}

		ll ans = 0;
		while ( q.size() > 1 ) {
			ll a = -q.top();
			q.pop();

			ll b = -q.top();
			q.pop();

			q.push ( - (a + b) );
			ans += (a+b);
		}

		cout << ans << endl;
	}


	return 0;
}

//T-shirt buying (Codeforces)
#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int mx = 2e5+123;
int a[mx];
int b[mx];
int p[mx];

int main()
{
    optimize();
    int n;
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> p[i];
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    for ( int i = 1; i <= n; i++ ) cin >> b[i];

    priority_queue< int, vector<int>, greater<int> > q[5][5];


    for ( int i = 1; i <= n; i++ ) {
        q[a[i]][b[i]].push ( p[i] );
    }

    int m;
    cin >> m;

    while ( m-- ) {
        int c;
        cin >> c;

        int ans = INT_MAX;
        int f, b;

        for ( int i = 1; i <= 3; i++ ) {
            if ( !q[c][i].empty() && q[c][i].top() < ans ) {
                ans = q[c][i].top();
                f = c, b = i;
            }
        }

        for ( int i = 1; i <= 3; i++ ) {
            if ( !q[i][c].empty() && q[i][c].top() < ans ) {
                ans = q[i][c].top();
                f = i, b = c;
            }
        }

        if ( ans == INT_MAX ) ans = -1;
        else {
            q[f][b].pop();
        }

        cout << ans << " ";
    }

    cout << endl;
}


///Constructing the Array (Codeforces

         #include<bits/stdc++.h>
using namespace std;

const int mx = 1e5+123;
int a[mx];

int main()
{
    priority_queue <int> q;

    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> a[i];

    for ( int i = 0; i < n; i++ ) {
        q.push ( a[i] );
        if ( q.size() >= 3 ) {
            int a1 = q.top();
            q.pop();

            int a2 = q.top();
            q.pop();

            int a3 = q.top();
            q.pop();

            cout << 1LL * a1 * a2 * a3 << endl;

            q.push ( a1 );
            q.push ( a2 );
            q.push ( a3 );
        }
        else cout << -1 << endl;


    }
}
