class Solution {
public:
    void solve(vector<vector<char> > &board) {
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();
        if(n==0) return;
        
        if(m==1 || n==1) return;
        
        queue<pair<int,int> > q;
        for(int j=0;j<n-1;++j) if(board[0][j]=='O') q.push(make_pair(0,j));
        for(int i=0;i<m-1;++i) if(board[i][n-1]=='O') q.push(make_pair(i,n-1));
        for(int j=n-1;j>0;--j) if(board[m-1][j]=='O') q.push(make_pair(m-1,j));
        for(int i=m-1;i>0;--i) if(board[i][0]=='O') q.push(make_pair(i,0));
        
        while(!q.empty()) {
            auto c=q.front();
            int s=c.first, t=c.second;
            board[s][t]='1';
            q.pop();
            if(valid(s+1,t,board)) q.push(make_pair(s+1,t));
            if(valid(s,t+1,board)) q.push(make_pair(s,t+1));
            if(valid(s-1,t,board)) q.push(make_pair(s-1,t));
            if(valid(s,t-1,board)) q.push(make_pair(s,t-1));
        }
        
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='1') board[i][j]='O';
            }
        }
    }
    inline bool valid(int i, int j, vector<vector<char> > &b) {
        return (0<=i && i<b.size() && 0<=j && j<b[0].size() && b[i][j]=='O');
    }
};
