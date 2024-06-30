class Solution {
public:
    int reverse(int x) {
        int num=0, digit=0;
        while(x){
            if (num>INT_MAX/10 || num<INT_MIN/10) return 0;
            digit = x%10;
            num=num*10 + digit;
            x/=10;
        }
        return num;
    }
};