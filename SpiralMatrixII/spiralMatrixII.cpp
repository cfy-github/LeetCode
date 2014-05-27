class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > r(n, vector<int>(n, 0));
        if(n<=0) return r;
        int begin=0,end=n-1;
        int num=1;
        while(begin<end) {
            for(int i=begin;i<end;i++) r[begin][i]=num++;
            for(int j=begin;j<end;j++) r[j][end]=num++;
            for(int i=end;i>begin;i--) r[end][i]=num++;
            for(int j=end;j>begin;j--) r[j][begin]=num++;
            begin++;
            end--;
        }
        if(begin==end) r[begin][end]=num;
        return r;
    }
};
