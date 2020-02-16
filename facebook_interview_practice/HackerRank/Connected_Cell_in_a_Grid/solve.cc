#include <bits/stdc++.h>

using namespace std;


// Complete the maxRegion function below.
const int filled = 1;

void fill_color(vector<vector<int> >& grid, int row, int col, int color)
{
    if (((row < 0) || (row >= grid.size())) ||
        ((col < 0) || (col >= grid[row].size())) ||
        ((grid[row][col] != filled))) {
            return;
    } else {
        grid[row][col] = color;
        fill_color(grid, row - 1, col,      color);
        fill_color(grid, row - 1, col - 1,  color);
        fill_color(grid, row - 1, col + 1,  color);
        
        fill_color(grid, row + 1, col,      color);
        fill_color(grid, row + 1, col - 1,  color);
        fill_color(grid, row + 1, col + 1,  color);

        fill_color(grid, row, col - 1,      color);
        fill_color(grid, row, col + 1,      color);
    }
}

int maxRegion(vector<vector<int>> grid) {
    int color = filled + 1;
    int ret = 0;

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == filled) {
                fill_color(grid, i, j, ++color);
            }
        }
    }

    vector<int> color_map(color + 1, 0);
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] > filled) {
                ++color_map[grid[i][j]];
            }
        }
    }

    for (int i = 0; i < color_map.size(); ++i) {
        if (color_map[i] > ret) {
            ret = color_map[i];
        }
    }

    return ret;
}
