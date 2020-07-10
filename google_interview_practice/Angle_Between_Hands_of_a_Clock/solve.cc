class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = (double)minutes * 6.0f;
        double hourAngle = (double)hour * 30.0f + (double)minutes * 0.5f;
        double angle;
        if (hourAngle >= 360.0f) hourAngle -= 360.f;
        angle = (hourAngle > minAngle) ? (hourAngle - minAngle) : (minAngle - hourAngle);
        return (angle > 180.f) ? (360.0f - angle) : angle;
    }
};

