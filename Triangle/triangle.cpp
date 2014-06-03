class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        //f(i,j)=min(f(i,j+1),f(i-1,j+1))+f(i,j)
        int n=triangle.size();
        if(n==0) return 0;
        vector<int> v=triangle[n-1];
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<triangle[i].size();j++) {
                v[j]=(v[j]>v[j+1]?v[j+1]:v[j])+triangle[i][j];
            }
        }
        return v[0];
    }
};
