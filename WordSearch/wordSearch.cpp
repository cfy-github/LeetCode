class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(word.size()==0) return true;
        int m=board.size();
        if(m==0) return false;
        int n=board[0].size();
        if(n==0) return false;
        vector<vector<bool> > f(m, vector<bool>(n, true));
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(board[i][j]==word[0]) {
                    f[i][j]=false;
                    if(dfs(f,word,board,i,j+1,1)) return true;
                    else if(dfs(f,word,board,i,j-1,1)) return true;
                    else if(dfs(f,word,board,i-1,j,1)) return true;
                    else if(dfs(f,word,board,i+1,j,1)) return true;
                    f[i][j]=true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<bool> > &f, string &w, vector<vector<char> > &b, int i, int j, int k) {
        if(k==w.size()) return true;
        if(i>=0&&i<b.size()&&j>=0&&j<b[0].size()&&f[i][j]) {
            if(b[i][j]==w[k]) {
                f[i][j]=false;
                if(dfs(f,w,b,i,j+1,k+1)) return true;
                else if(dfs(f,w,b,i,j-1,k+1)) return true;
                else if(dfs(f,w,b,i-1,j,k+1)) return true;
                else if(dfs(f,w,b,i+1,j,k+1)) return true;
                f[i][j]=true;
            }
        }
        return false;
    }
};
