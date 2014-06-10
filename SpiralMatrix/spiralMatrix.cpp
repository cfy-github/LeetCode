class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> r;
        int m=matrix.size();
        if(m==0) return r;
        int n=matrix[0].size();
        if(n==0) return r;
        int cbegin=0, cend=m-1, rbegin=0, rend=n-1;
        while(cbegin<cend && rbegin<rend) {
            for(int j=rbegin;j<rend;++j) r.push_back(matrix[cbegin][j]);
            for(int i=cbegin;i<cend;++i) r.push_back(matrix[i][rend]);
            for(int j=rend;j>rbegin;--j) r.push_back(matrix[cend][j]);
            for(int i=cend;i>cbegin;--i) r.push_back(matrix[i][rbegin]);
            cbegin++;
            rbegin++;
            cend--;
            rend--;
        }
        if(cbegin==cend&&rbegin==rend) {
            r.push_back(matrix[cbegin][rbegin]);
            return r;
        }
        if(cbegin==cend) {
            for(int j=rbegin;j<=rend;++j) r.push_back(matrix[cbegin][j]);
        }
        if(rbegin==rend) {
            for(int i=cbegin;i<=cend;++i) r.push_back(matrix[i][rend]);
        }
        
        return r;
    }
};
