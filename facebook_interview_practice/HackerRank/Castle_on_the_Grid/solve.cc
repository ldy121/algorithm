const char avail = '.';
const char wall  = 'X';
const char visit = '^';

class point {
    public :
        point(int x, int y) : m_x(x), m_y(y){};
        int m_x;
        int m_y;
};

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    queue<point> q;
    bool arrive = false;
    int ret = 0;

    q.push(point(startX, startY));
    grid[startX][startY] = visit;

    for (ret = 0; arrive == false; ++ret) {
        for (int size = q.size(); size > 0; --size) {
            int x = q.front().m_x;
            int y = q.front().m_y;

            if ((x == goalX) && (y ==goalY)) {
                arrive = true;
                break;
            } else {
                q.pop();
            }

            for (int i = x - 1; (i >= 0) && (grid[i][y] != wall); --i) {
                if (grid[i][y] == avail) {
                    q.push(point(i, y));
                    grid[i][y] = visit;
                }
            }

            for (int i = x + 1; (i < grid.size()) && (grid[i][y] != wall); ++i) {
                if (grid[i][y] == avail) {
                    q.push(point(i, y));
                    grid[i][y] = visit;
                }
            }

            for (int i = y - 1; (i >= 0) && (grid[x][i] != wall); --i) {
                if (grid[x][i] == avail) {
                    q.push(point(x, i));
                    grid[x][i] = visit;
                }
            }

            for (int i = y + 1; (i < grid[x].length()) && (grid[x][i] != wall); ++i) {
                if (grid[x][i] == avail) {
                    q.push(point(x, i));
                    grid[x][i] = visit;
                }
            }
        }
    }

    return ret - 1;
}
