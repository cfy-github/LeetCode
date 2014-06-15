class Solution {
    struct mycomp{
        bool operator() (pair<int ,int> a, pair<int ,int> b) {return a.first<b.first;}
    } comp;
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n=numbers.size();
        vector<int> r;
        if(n<2) return r;
        vector<pair<int, int> > nums;
        for(int i=0;i<n;++i) {
            nums.push_back(make_pair(numbers[i], i+1));
        }
        sort(nums.begin(),nums.end(), comp);
        int first=0, last=n-1;
        while(first<last) {
            int sum=nums[first].first+nums[last].first;
            if(sum<target) first++;
            else if(sum>target) last--;
            else {
                int a=nums[first].second, b=nums[last].second;
                r.push_back(a<b?a:b);
                r.push_back(a<b?b:a);
                return r;
            }
        }
        return r;
    }
};
