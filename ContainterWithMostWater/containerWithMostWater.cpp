class Solution {
public:
    int maxArea(vector<int> &height) {
        int begin=0;
        int end=height.size()-1;
        int r=0;
        while(begin<end) {
            r=max(r,(end-begin)*min(height[begin],height[end]));
            if(height[begin]<=height[end]) begin++;
            else end--;
        }
        return r;
    }
};
