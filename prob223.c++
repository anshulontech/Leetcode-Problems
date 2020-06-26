// https://leetcode.com/problems/rectangle-area/s

class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        if (C <= E || A >= G || H <= B || D <= F)
            return (C - A) * (D - B) + (G - E) * (H - F);

        int length = min(C, G) - max(A, E);
        int width = min(D, H) - max(B, F);

        int area = -length * width + (C - A) * (D - B) + (G - E) * (H - F);

        return area;
    }
};