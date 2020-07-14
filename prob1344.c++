// https://leetcode.com/problems/angle-between-hands-of-a-clock/description/

// Time Complexity:-O(1).
// Space Complexity:-O(1).

// Approach:-
//     Use basic mental ability.

class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double hourAngle = hour * 30 + (double)minutes / 2;
        double minutesAngle = minutes * 6;

        return min(abs(hourAngle - minutesAngle), 360 - abs(hourAngle - minutesAngle));
    }
};