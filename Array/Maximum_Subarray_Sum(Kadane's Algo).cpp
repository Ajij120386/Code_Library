
/*           1st Approach      */

class Solution {
public:

    int maxSubArray(vector<int>& nums) {

        int mx=nums[0];
        int s=0,start=0,ansstart=0,ansend=0;

        for(int i=0;i<nums.size();i++)
        {

              if(s==0) start=i;
            s+=nums[i];

              if(s>mx)
              {
                mx=s;
                ansstart=start;
                ansend=i;
              }

           if(s<0) s=0;

        }

    return mx;
   // return ansstart;
    //return ansend;

    }
};

/*           @nd Approach      */

class Solution {
public:

    int maxSubArray(vector<int>& nums) {

        int mx=nums[0];
        int s=nums[0];
        int start=0,ansstart=0,ansend=0;

        for(int i=1;i<nums.size();i++)
        {

             s=max(nums[i],s+nums[i]);
             mx=max(mx,s);

        }

    return mx;


    }
};
