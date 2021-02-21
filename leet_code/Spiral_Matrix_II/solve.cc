class Solution {
private :
    enum dir {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ret;
        int up = 0, right = n - 1;
        int down = n - 1, left = 0;
        int row = 0, col = 0;
        dir d = RIGHT;

        for (int i = 0; i < n; ++i) {
            vector<int> vec(n, 0);
            ret.push_back(vec);
        }
        
        for (int i = 1; i <= n * n;) {
            ret[row][col] = i++;

            if (d == RIGHT) {
                if (++col > right) {
                    col = right--;
                    ++row;
                    d = DOWN;
                }
            } else if (d == DOWN) {
                if (++row > down) {
                    row = down--;
                    --col;
                    d = LEFT;
                }
            } else if (d == LEFT) {
                if (--col < left) {
                    col = left++;
                    --row;
                    d = UP;
                }
            } else {
                if (--row <= up) {
                    row = ++up;
                    ++col;
                    d = RIGHT;
                }
            }
        }

        return ret;
    }
};
