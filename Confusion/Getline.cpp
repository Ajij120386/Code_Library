
//******************1**************
/*
input: 3

       i am a student
       iam good


       i am a teacher
       iam best


       i am a police
       iam bad guy



*/

#include<bits/stdc++.h>
using namespace std;

int main()
{



    string s,s1;
    int t;
    cin>>t;
      getline( cin, s1 );
    for(int i=0;i<t;i++)
    {
         getline( cin, s1 );
    getline( cin, s );


    cout<<s1<<endl;
    cout<<s<<endl;
    }



    return 0;
}


//**************2**************

/*


    input :
         iam a student;
*/



#include<bits/stdc++.h>
using namespace std;

int main()
{



   char c;
    cin >> c;
    getline( cin, s );
    s = c + s;

    cout << s << endl;


    return 0;
}
