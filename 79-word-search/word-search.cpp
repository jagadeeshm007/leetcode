class Solution {
public:
    bool check(vector<vector<char>>& board,int i,int j,int k, string& word) {
        if(k >= word.length()){
            return true;
        }
        if( i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]!=word[k] ){
            return false;
        } 
        bool right=false,left=false,top=false,down=false;
        char tmp = board[i][j];
        board[i][j]=' ';
            right = check(board,i,j+1,k+1,word);
            left = check(board,i,j-1,k+1,word);
            top = check(board,i+1,j,k+1,word);
            down = check(board,i-1,j,k+1,word);
        board[i][j] = tmp;
        return top or down or left or right ;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0] && check(board,i,j,0,word)) return true;
            }
        }
        return false;
    }
};