
int f(string &s1, string &s2,int ind1,int ind2,int count)
{


 if(ind1<0 || ind2<0)
   return count;

 if(s1[ind1]==s2[ind2])
    count= f(s1,s2,ind1-1,ind2-1,count+1);

    count= max(count,max(f(s1,s2,ind1-1,ind2,0),f(s1,s2,ind1,ind2-1,0)));


  return count;

}
int lcs(string &str1, string &str2){

    int n=str1.size();
    int m=str2.size();

    return f(str1,str2,n-1,m-1,0);
    // Write your code here.

}
