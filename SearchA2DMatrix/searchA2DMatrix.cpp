class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m=matrix.size();
        if(m==0) return false;
        int n=matrix[0].size();
        if(n==0) return false;
        int r0=0, r1=m-1;
        while(r0<=r1) {
            int mid=(r0+r1)/2;
            if(target<matrix[mid][0]) r1=mid-1;
            else if(target>matrix[mid][n-1]) r0=mid+1;
            else return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
        }
        return false;
    }
};
