// Find the number of Islands

/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) 
consisting of '0's (Water) and '1's(Land). 
Find the number of islands.
Note: An island is either surrounded by water or the boundary of a grid 
and is formed by connecting adjacent lands horizontally or vertically or diagonally 
i.e., in all 8 directions.

Example1:
    Input: grid = [[0,1],[1,0],[1,1],[1,0]]
    Output: 1
    Explanation:
        The grid is-
        0 1
        1 0
        1 1
        1 0
        All lands are connected.

Example2:
    Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
    Output: 2
    Expanation:
        The grid is-
        0 1 1 1 0 0 0
        0 0 1 1 0 2 0 
        There are two islands in the grid. One island is marked by '1' and the other by '2'.

Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
    1 ≤ n, m ≤ 500
    0 ≤ grid[i][j] ≤ 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &vis) {
        vis[i][j] = 1;
        int nx, ny;
        for(int dx = -1; dx < 2; ++dx) {
            for(int dy = -1; dy < 2; ++dy) {
                nx = i + dx;
                ny = j + dy;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1' && !vis[nx][ny])
                    dfs(nx, ny, n, m, grid, vis);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) 
                if(grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    dfs(i, j, n, m, grid, vis);
                }
        return count;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
