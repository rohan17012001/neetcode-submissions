class Solution {
public:
    bool solve(int i, int j, int m, int n, string word, int ind, vector<vector<char>>& board, int x[], int y[]){
        if(ind==word.length()) return true;
        if(i>=m || i<0 || j>=n || j<0 || ind>word.length()) return false;
        if(board[i][j]==word[ind]){
            char ch=board[i][j];
            board[i][j]='#';
            for(int k=0; k<4; k++){
                int ni=i+x[k];
                int nj=j+y[k];
                // if(ni>=0 && ni<m && nj>=0 && nj<n && board[ni][nj]!='#'){
                    if(solve(i+x[k], j+y[k], m, n, word, ind+1, board, x, y)) return true;
                // }
            }
            board[i][j]=ch;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        // string ans;
        int x[]={0,1,0,-1};
        int y[]={1,0,-1,0};
        // vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    if(solve(i, j, m, n, word, 0, board, x, y)) return true;
                }
            }
        }
        return false;
        // return solve(0, 0, m, n, word, ans, board, vis);
    }
};
