class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n=gas.size();
        for(int i=0;i<n;i++) {
            gas[i]-=cost[i];
        }
        int sum=0, begin=0, end=0, i=0;
        do {
            if(sum<0) {
                begin=(n+begin-1)%n;
                sum+=gas[begin];
            } else {
                sum+=gas[end];
                end=(end+1)%n;
            }
        } while(begin!=end);
        if(sum>=0) return begin;
        else return -1;
    }
};
