class Solution {
public:
    int addDigits(int num) {
        int tmp=0;
        while(num!=0){
            tmp+=num%10;
            num/=10;
            if(num==0 && tmp>9){
                num=tmp;
                tmp=0;
            }
        }

        return tmp;
    }
};