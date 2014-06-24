class Solution {
public:
    int removeDuplicates(int A[], int n) {
        const int occur=2;
        if(n<=occur) return n;
        
        int index=occur;
        for(int i=occur;i<n;++i) {
            if(A[i]!=A[index-occur]) A[index++]=A[i];
        }
        return index;
    }
};
