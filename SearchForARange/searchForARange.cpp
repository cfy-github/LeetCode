class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        auto from=lower_bound(A, A+n, target);
        auto to=upper_bound(from, A+n, target);
        if(from==A+n||*from!=target) return vector<int> {-1,-1};
        else return vector<int> {distance(A,from),distance(A,prev(to))};
    }
    template<typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first,
            ForwardIterator last, T &val) {
                while(first!=last) {
                    auto mid=next(first,distance(first,last)/2);
                    if(*mid<val) first=++mid;
                    else last=mid;
                }
        return first;
    }
    template<typename ForwardIterator, typename T>
    ForwardIterator upper_bound(ForwardIterator first,
            ForwardIterator last, T &val) {
                while(first!=last) {
                    auto mid=next(first, distance(first,last)/2);
                    if(*mid<=val)  first=++mid;
                    else last=mid;
                }
                return first;
    }
};
