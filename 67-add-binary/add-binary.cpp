class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        string ans;
        while (i >= 0 or j >= 0 or carry) {
            if (i >= 0)
                carry += a[i--] - '0';
            if (j >= 0)
                carry += b[j--] - '0';
            ans += (carry % 2 + '0');
            carry = carry / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};