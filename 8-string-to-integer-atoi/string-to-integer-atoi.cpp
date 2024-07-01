class Solution {
public:
    int myAtoi(string s) {
        int num = 0, i = 0;
        int sign = 1;
        while (i < s.length() && s[i] == ' ') i++;

        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            if (num > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return num * sign;
    }
};
