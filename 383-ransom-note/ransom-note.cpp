class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ransomNoteFreq(26,0);
        vector<int> magazineFreq(26,0);

        for(int i=0;i<ransomNote.length();i++){
            ransomNoteFreq[ransomNote[i] - 'a']++;
        }
        for(int i=0;i<magazine.length();i++){
            magazineFreq[magazine[i] - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(ransomNoteFreq[i]>magazineFreq[i]) return false;
        }
        return true;
    }
};