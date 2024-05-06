class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int presentSize = 0, maxSize = 0, size = s.length(), prev = 0;
        int frq[129];
        memset(frq, -1, sizeof(frq));
        for (int i = 0; i < size; i++) {
            if (frq[s[i]] == -1) {
                frq[s[i]] = i;
                presentSize++;
            } else {
                while (prev <= frq[s[i]]) {
                    frq[s[prev]] = -1;
                    prev++;
                    presentSize--;
                }
                frq[s[i]] = i;
                presentSize++;
            }
            maxSize = max(maxSize, presentSize);
            // debugging print statement
            // cout<<s[i]<<" "<<frq[s[i]]<<" "<<presentSize<<" "<<maxSize<<" "<<prev<<endl;
        }
        return maxSize;
    }
};