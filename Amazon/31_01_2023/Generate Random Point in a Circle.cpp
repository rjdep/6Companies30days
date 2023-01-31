class Solution {
public:

    long double x,y,rad;
    Solution(double radius, double x_center, double y_center) {
        x = x_center;
        y = y_center;
        rad = radius;
    }
    
    vector<double> randPoint() {
        double r = rad*sqrt((double)random()/RAND_MAX);
        // double PI = 3.14159265359;
        double theta = 2*M_PI*((double)random()/RAND_MAX);
        double xx = x+r*cos(theta);
        double yy = y+r*sin(theta);
        return {xx,yy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
