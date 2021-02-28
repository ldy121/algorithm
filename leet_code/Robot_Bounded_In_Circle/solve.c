class Solution {
private :
    enum direction {
        north,
        east,
        south,
        west
    };
    
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, dir = north;
        for (int j = 0; j < 4; ++j) {
            for (int i = 0; i < instructions.length(); ++i) {
                char ch = instructions[i];
            
                if (ch == 'G') {
                    switch(dir) {
                        case south :
                            --y;
                            break;
                        case north :
                            ++y;
                            break;
                        case west :
                            --x;
                            break;
                        case east :
                            ++x;
                            break;
                    }
                } else if (ch == 'R') {
                    dir = (dir + 1) % 4;
                } else {
                    dir = (dir + 3) % 4;
                }
            }
            if (x == 0 && y == 0 && dir == north) {
                return true;
            }
        }
        return false;
    }
};
