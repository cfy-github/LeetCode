class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r;
        for(int i=0;i<=rowIndex;i++) {
            for(int j=i-1;j>0;j--) r[j]=r[j-1]+r[j];
            r.push_back(1);
        }
        return r;
    }
};
