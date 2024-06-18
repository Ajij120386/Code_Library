
//1st


class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<int, int> ump;

        for(int i=0; i<=sqrt(c); i++){
            ump[i*i]++;
            int req = c - i*i;

            if(ump[req]){
                return true;
            }
        }

        return false;
    }
};

//2nd

class Solution {
public:
    bool judgeSquareSum(int c)
    {
    	if(c<0)
    		return false;
    	long int left=0,right=sqrt(c);
    	while(left<=right)
    	{
    		long int cur=left*left+right*right;
    		if(cur<c)
    			left++;
    		else if(cur>c)
    			right--;
    		else
    			return true;
    	}
    	return false;
    }
};
