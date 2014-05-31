class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> map;
        int n=num.size();
        for(auto i:num) map[i]=false;
        int max=0;
        for(auto i:num) {
            if(map[i]) continue;
            int tmp=1;
            for(int j=i+1;map.find(j)!=map.end();++j) {
                tmp++;
                map[j]=true;
            }
            for(int j=i-1;map.find(j)!=map.end();--j) {
                tmp++;
                map[j]=true;
            }
            max=max<tmp?tmp:max;
        }
        return max;
    }
};
