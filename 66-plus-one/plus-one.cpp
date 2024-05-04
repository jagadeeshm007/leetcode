#define pb push_back
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int carry=1;
        for(int i=0;i<digits.size();i++){
            int tmp = digits[i] + carry;
            digits[i] = tmp%10;
            carry =  tmp/10;
        }
        if(carry) digits.pb(carry);

        reverse(digits.begin(),digits.end());

        return digits;
    }
};