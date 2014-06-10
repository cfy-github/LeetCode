class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> st;
        int ret=0, i=0;
        while(i<height.size()) {
            if(st.empty()||height[i]>=height[st.top()]) st.push(i++);
            else {
                int tp=st.top();
                st.pop();
                ret=max(ret, height[tp]*(st.empty()?i:i-st.top()-1));
            }
        }
        while(!st.empty()) {
            int tp=st.top();
            st.pop();
            ret=max(ret, height[tp]*(st.empty()?i:i-st.top()-1));
        }
        return ret;
    }
};
