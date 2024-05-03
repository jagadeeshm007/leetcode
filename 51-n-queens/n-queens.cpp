class Solution {
public:
    bool Placeable(int row, int col,vector<string>& Board, int n) {
        int cpyrw = row , cpycol = col;
        while(col>=0 && row>=0){
            if(Board[row][col]=='Q') return false;
            col--;
            row--;
        }
        row=cpyrw;
        col=cpycol;
        while(col>=0){
            if(Board[row][col]=='Q') return false;
            col--;
        }
        row=cpyrw;
        col=cpycol;
        while(col>=0 && row<n){
            if(Board[row][col]=='Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void Queens(int col, vector<string>& Board, vector<vector<string>>& Result, int n){
        if(col==n){
            Result.push_back(Board);
            return;
        }

        for(int row=0;row<n;row++){
            if(Placeable(row,col,Board,n)){
                Board[row][col] = 'Q';
                Queens(col+1,Board,Result,n);
                Board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> Result;
        vector<string> Board(n);
        string tmp(n,'.');
        for(int i=0;i<n;i++){
            Board[i]=tmp;
        }

        Queens(0,Board,Result,n);

        return Result;
    }
};