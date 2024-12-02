
///**************1********************

 public static int countSetBit(int num){

        int cnt = 0;
        int one = 1;
        while(num !=0){
            if((num & one) == 1){
                cnt++;
            }
            num = num >> 1;
        }
        return cnt;
    }


    ///**************2********************

 public static int countSetBit(int num){

        int cnt = 0;

        while(num !=0){

        num= num & num-1;
                cnt++;

        }
        return cnt;
    }
