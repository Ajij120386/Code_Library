
class Solution {
public:
    vector<int> getRow(int rowIndex) {


          vector<int>prev;

       for(int i=0;i<rowIndex+1;i++)
       {
              vector<int>cur(i+1,1);

           for(int j=1;j<i;j++)
           {
             cur[j]= prev[j-1]+prev[j];
           }

           prev=cur;

       }


return prev;



    }
};
