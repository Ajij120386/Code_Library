
////1st solution TC: 0(n)+0(26log26)=0(n)   SC: 0(26)=0(1)


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>cnt;

        for(auto it: tasks)
         cnt[it]++;

         priority_queue<int>pq;

         for(auto it:cnt)
         pq.push(it.second);

         int result=0;

         while(!pq.empty())
         {
             vector<int>tmp;
             for(int i=0;i<n+1;i++)
            {
                 if(!pq.empty()){
                     tmp.push_back(pq.top()-1);
                     pq.pop();

                 }
             }
             for(auto it:tmp)
             {
                 if(it)
                      pq.push(it);
             }
             if(pq.empty())

                 result+=tmp.size();

             else

                 result+=n+1;

         }
        return result;
    }
};



//2nd solution TC: 0(n)+0(26log26)=0(n)   SC: 0(26)=0(1)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

         vector<int>freq(26);

         for(auto ch: tasks)
           freq[ch-'A']++;

        sort(freq.begin(),freq.end(),greater<int>());

        int idletime=(freq[0]-1)*n;
        for(int i=1;i<freq.size();i++)
        {
            idletime= idletime-min(freq[0]-1,freq[i]);

        }


        return tasks.size()+max(0,idletime);
    }
};
