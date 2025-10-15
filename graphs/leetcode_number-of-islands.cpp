void island(vector<vector<char>> &grid, int i, int j) {
    // Check bounds and if current cell is land ('1')
    if (0 <= i && i < grid.size() && 0 <= j && j < grid[i].size() && grid[i][j] == '1') {
        grid[i][j] = '0';  // Mark current land as visited (turn into water)
        // Recursively visit all 4 directions
        island(grid, i+1, j);
        island(grid, i, j+1);
        island(grid, i-1, j);
        island(grid, i, j-1);
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        // Traverse the grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                // If land found
                if (grid[i][j] == '1') {
                    island(grid, i, j);  // Mark entire island
                    res++;               // Increment island count
                }
            }
        }
        return res;
    }
};
