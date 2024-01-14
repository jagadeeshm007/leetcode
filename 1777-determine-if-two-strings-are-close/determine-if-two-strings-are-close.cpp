class Solution {
public:
    bool closeStrings(string word1, string word2) {
        //speeds up code , dont know whyyy  :)
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

            // my code starts here
        if(word1.length() != word2.length() ) return false;
        vector<int> a(26,0),b(26,0) ;
        set<char> s1,s2;
        for(auto i : word1) a[i - 'a']++, s1.insert(i);
        for(auto i : word2) b[i - 'a']++, s2.insert(i);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b && s1 == s2) return true;
        return false;
    }
};