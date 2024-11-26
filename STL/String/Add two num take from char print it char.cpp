

/*

*/
vector<char> sum(vector<char> &A, vector<char> &B){

    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());

    vector<char> sum;

    int c = 0;
    int i=0,j=0;
    while(true){
        int a=0,b=0;
        if( i<A.size() ) a = A[i++]-'0';
        if( j<B.size() ) b = B[j++]-'0';

        int s = (a+b+c)%10;
        c = (a+b+c)/10;
        sum.push_back(s+'0');
        if( i>=A.size() and j>=B.size() and c == 0 ) break;
    }
    reverse(sum.begin(),sum.end());
    return sum;
}
