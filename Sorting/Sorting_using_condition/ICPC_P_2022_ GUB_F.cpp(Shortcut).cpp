#include <bits/stdc++.h>
using namespace std;



struct info
{
  string time,email,birth,bg;
};

bool cmp(info &a,info &b){

  return (a.time<b.time);
}
int main(){

  int n;
  cin>>n;
  info a[n];

for(int i=0;i<n;i++){

  cin>>a[i].time>>a[i].email>>a[i].birth>>a[i].bg;


  }
  sort(a,a+n,cmp);
  cout<<endl;
  cout<<endl;
  cout<<endl;

  for(int i=0;i<n;i++){

  cout<<a[i].time<<" "<<a[i].email<<" "<<a[i].birth<<" "<<a[i].bg<<endl;


  }
  map<string,pair<string,string > >mp;


  for(int i=0;i<n;i++){


        mp[a[i].email]={ a[i].birth.substr(6,9),a[i].bg } ;
  }
   cout<<endl;
  cout<<endl;
  cout<<endl;

  map<string,int>bgcnt;
  map<string,int>yrcnt;

 bgcnt["A+"]=0;
  bgcnt["A-"]=0;
  bgcnt["AB+"]=0;
  bgcnt["AB-"]=0;
 bgcnt["B+"]=0;
 bgcnt["B-"]=0;
bgcnt["O+"]=0;
  bgcnt["O-"]=0;


  for(auto [email,bi_bg]: mp){

        cout<<email<<" "<<bi_bg.first<<" "<<bi_bg.second<<endl;
       bgcnt[bi_bg.second]++; //blood group counting
       yrcnt[bi_bg.first]++; //year counting
  }

for(auto it: bgcnt){

        cout<<it.first<<" "<<it.second<<endl;
}
cout<<endl;
  cout<<endl;
  cout<<endl;

for(auto it: yrcnt){

        cout<<it.first<<" "<<it.second<<endl;
}


}

/*

12
01/02/2023#15:58:31 2022100011006@seu.edu.bd 28/07/2001 A+
01/02/2023#17:46:00 2022100000101@seu.edu.bd 13/03/2003 A+
01/02/2023#18:29:15 2019100010035@seu.edu.bd 09/10/1994 A+
01/02/2023#20:09:54 2021200000054@seu.edu.bd 18/07/2001 A+
01/02/2023#22:47:33 2021100000021@seu.edu.bd 03/10/2002 A+
04/02/2023#20:10:10 2020000000014@seu.edu.bd 04/05/2001 A+
01/02/2023#10:40:16 2018200010061@seu.edu.bd 15/11/1997 A-
05/02/2023#11:21:51 2022100000067@seu.edu.bd 02/11/2002 AB+
05/02/2023#11:46:17 2018100011010@seu.edu.bd 16/12/1997 AB+
01/02/2023#23:20:28 2018100000041@seu.edu.bd 15/06/2000 B-
02/02/2023#21:58:11 2021200010017@seu.edu.bd 15/06/1997 B-
02/02/2023#21:59:11 2021200010017@seu.edu.bd 15/06/1997 B+
*/

