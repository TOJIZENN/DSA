class Solution {
private:
    void captureAndfreeRegions(int rows, int cols , vector<vector<char>>& board) {

        for(int i=0;i<rows;i++) {

            for(int j=0;j<cols;j++) {
                
                if(board[i][j]=='Y') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }

    void dfs(vector<vector<int>>& vis ,vector<vector<char>>& board ,int rows, int cols , int r, int c) {

        // boundary conditions
        if(r==rows || r<0 || c<0 || c==cols || vis[r][c] || board[r][c] != 'O') return;

        if(!vis[r][c]) {

            vis[r][c] = 1;
            board[r][c] = 'Y';

            dfs(vis, board , rows, cols , r-1, c); // up
            dfs(vis, board , rows, cols , r+1, c); // down
            dfs(vis, board , rows, cols , r, c-1); // left
            dfs(vis, board , rows, cols , r, c+1); // right
        }
    }

    void performDFSfromEdgeCells(vector<vector<char>>& board, int rows, int cols) {

        vector<vector<int>> vis(rows , vector<int>(cols , 0));

        for(int i=0;i<rows;i++) {
            
            for(int j=0;j<cols;j++) {

                if(i==0 || j==0 || i==rows-1 || j== cols-1) {
                    if(board[i][j]=='O') dfs(vis, board, rows, cols , i , j);
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {

        int rows = board.size(), cols = board[0].size();
        performDFSfromEdgeCells(board, rows, cols);
        captureAndfreeRegions(rows, cols , board);
    }
};