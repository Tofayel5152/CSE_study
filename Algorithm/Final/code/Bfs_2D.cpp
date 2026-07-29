#include <bits/stdc++.h>
using namespace std;

const int ROWS = 4, COLS = 4;
bool visited[ROWS][COLS];
// 4 directions: up, right, down, left
    int dRow[] =  { -1, 0, 1, 0 };
    int dCol[] =  { 0, 1, 0, -1 };

bool isValid(int grid[ROWS][COLS], int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS) return false; // out of bounds
    if (visited[r][c]) return false;                             // already visited
    return true;
}

// Till now same for BSF DFS and number of island problem(8 directions so direction array changed). 

void bfs(int grid[ROWS][COLS], int startR, int startC) {

    queue<pair<int,int>> q;
    q.push({startR, startC});
    visited[startR][startC] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;

        cout << "Visiting cell: (" << r << ", " << c << ") with value: " << grid[r][c] << endl;

        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int newR = r + dRow[dir];
            int newC = c + dCol[dir];

            if (isValid(grid, newR, newC)) {
                visited[newR][newC] = true;
                q.push({newR, newC});
            }
        }
    }
}

int main() 
{ 
    // Given input matrix 
    int grid[ROWS][COLS] = { { 1, 2, 3, 4 }, 
                           { 5, 6, 7, 8 }, 
                           { 9, 10, 11, 12 }, 
                           { 13, 14, 15, 16 } }; 
 

    memset(visited, false, sizeof(visited)); // reset visited array

    bfs(grid, 0, 0);
 
    return 0; 
} 