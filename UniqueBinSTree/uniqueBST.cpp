class Solution {
public:
    int numTrees(int n) {
        if(n==0 || n==1) return 1;
        int r=0;
        if(n%2==0) {
            for(int i=0;i<n/2;i++){
                r+=numTrees(i)*numTrees(n-1-i);
            }
            r=r*2;
        } else {
             for(int i=0;i<(n-1)/2;i++){
                r+=numTrees(i)*numTrees(n-1-i);
            }
            r=r*2+pow(numTrees((n-1)/2),2);
        }
        return r;
    }
};
