class Solution {
public:
    int reverse(int x) {
        int num=0, digit=0;
        while(x){
            digit = x%10;
            // HANDLE OVERFLOW
            if(num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > INT_MAX % 10)){
                return 0;
            }
            //HANDLE UNDERFLOW
            if(num < INT_MIN / 10 || (num == INT_MIN / 10 && digit < INT_MIN % 10)){
                return 0;
            }
            num=num*10 + digit;
            x/=10;
        }
        return num;
    }
};