class Solution {
public:
    int myAtoi(string s) {
        //if(s == "-2147483648") return INT_MIN;
        //if(s == "2147483647") return INT_MAX;
        int num=0,i=0;
        int mx = INT_MAX, mi = INT_MIN;
        int d=0,sg=0;
        while(i<s.length() && s[i]==' ') i++;
        for(i;i<s.length();i++) {
            int digit = 0;
            if(isdigit(s[i])){
                digit = s[i] - '0';
                d++;
            }
            else{
                if(sg==0 && d==0){
                    if(s[i] == '-') sg = -1;
                    else if(s[i] == '+') sg = 1;
                    else break;
                }
                else{
                    break;
                }
            }
            // HANDLE OVERFLOW
            if((sg==1 || sg==0) && num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > INT_MAX % 10)){
                //cout<<sg<<num<<" "<<sg*digit <<" "<< INT_MIN % 10<<" "<<(sg*num == INT_MIN / 10 && sg*digit <= INT_MIN % 10)<<" -> ";
                if(sg==-1){
                    if(sg*num == INT_MIN / 10 && sg*digit <= INT_MIN % 10){
                        return INT_MIN;
                    }
                }
                return INT_MAX;
            }
            //HANDLE UNDERFLOW
            if((sg ==-1) && sg*num < INT_MIN / 10 || (sg*num == INT_MIN / 10 && sg*digit < INT_MIN % 10)){
                return INT_MIN;
            }

            num = num*10 + digit;
        }
        if(sg==0) sg=1;
        return sg*num;
    }
};