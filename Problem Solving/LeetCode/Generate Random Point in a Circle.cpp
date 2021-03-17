class Solution {
private:
    const double PI = M_PI;
    double m_radius, m_x_center, m_y_center;
    vector<double> ans;
public:
    double uniform() {
        return (double)rand() / RAND_MAX;
    }
    Solution(double radius, double x_center, double y_center) {
      srand(time(NULL));
      m_radius = radius;
      m_x_center = x_center;
      m_y_center = y_center;
    }
    vector<double> randPoint() {
       double theta = 2 * M_PI * uniform();
       double r = sqrt(uniform());
        return vector<double>{
            m_x_center + r * m_radius * cos(theta),
            m_y_center + r * m_radius * sin(theta)
        };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
