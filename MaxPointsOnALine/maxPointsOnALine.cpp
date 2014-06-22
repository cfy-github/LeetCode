/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n=points.size();
        if(n<3) return n;
        
        unordered_map<double, int> m;
        
        int r=0;
        for(int i=0;i<n;++i) {
            m.clear();
            int same=0;
            int count=0;
            int currMax=1;
            for(int j=i+1;j<n;++j) {
                double slope;
                if(points[i].x==points[j].x) {
                    slope=numeric_limits<double>::infinity();
                    if(points[i].y==points[j].y) {
                        same++;
                        continue;
                    }
                } else {
                    slope=1.0*(points[i].y-points[j].y)/(points[i].x-points[j].x);
                }
                if(m.find(slope)!=m.end()) {
                    count=++m[slope];
                } else {
                    count=2;
                    m[slope]=2;
                }
                currMax=count>currMax?count:currMax;
            }
            r=max(r, currMax+same);
        }
        return r;
    }
};
