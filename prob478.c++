// https://leetcode.com/problems/generate-random-point-in-a-circle/description/

// Time Complexity:-O(1).
// Space Complexity:-O(1).

class Solution
{
public:
    Solution(double radius, double x_center, double y_center)
    {
        r = radius;
        x = x_center;
        y = y_center;
    }

    vector<double> randPoint()
    {
        double theta = 2 * 3.14159265358979323846264 * uniform();
        double R = sqrt(uniform());

        return vector<double>{
            x + R * r * cos(theta),
            y + R * r * sin(theta)};
    }

private:
    double r, x, y;

    double uniform()
    {
        return (double)rand() / RAND_MAX;
    }
};