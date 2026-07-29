#include <bits/stdc++.h>
using namespace std;

const int ROWS = 5, COLS = 5;
bool visited[ROWS][COLS];
    // 8 directions: up, down, left, right, and 4 diagonals
    int dRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Check if (r, c) is a valid, unvisited land cell
bool isValid(char grid[ROWS][COLS], int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) return false; // out of bounds
    if (grid[r][c] != 'L') return false;                        // not land
    if (visited[r][c]) return false;                             // already counted
    return true;
}

// Visit every land cell connected to (startR, startC) using BFS
void bfs(char grid[ROWS][COLS], int startR, int startC) {

    queue<pair<int,int>> q;
    q.push({startR, startC});
    visited[startR][startC] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int dir = 0; dir < 8; dir++) {
            int newR = r + dRow[dir];
            int newC = c + dCol[dir];

            if (isValid(grid, newR, newC)) {
                visited[newR][newC] = true;
                q.push({newR, newC});
            }
        }
    }
}

int countIslands(char grid[ROWS][COLS]) {
    memset(visited, false, sizeof(visited)); // reset visited array
    int count = 0;

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == 'L' && !visited[r][c]) {
                bfs(grid, r, c);
                count++; // found a new island
            }
        }
    }
    return count;
}

int main() {
    char grid[ROWS][COLS] = {
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}
    };

    cout << "Number of islands: " << countIslands(grid) << endl;
    return 0;
}