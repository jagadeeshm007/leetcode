class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int arr[257],visit[257];
        memset(arr,-1,sizeof(arr));

        for(int i = 0 ; i<s.length();i++){

            if(arr[s[i]] == -1){
                if(visit[t[i] ] ==0){
                    arr[s[i] ] = t[i] ;
                    visit[t[i] ] = 1;
                }
                else{
                    return false;
                }
                
            }
            else if( (t[i] ) != arr[s[i] ] ){
                    return false;
                }
        }
        return true;
    }
};