#include <bits/stdc++.h>
using namespace std;

const int ROWS = 3, COLS = 3;
bool visited[ROWS][COLS];

// 4 directions: up, right, down, left
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

bool inBounds(int r, int c) {
    return (r >= 0 && r < ROWS && c >= 0 && c < COLS);
}

void dfs(int grid[ROWS][COLS], int startR, int startC) {
    stack<pair<int, int>> st;
    st.push({startR, startC});

    while (!st.empty()) {
        pair<int, int> curr = st.top();
        st.pop();

        int row = curr.first;
        int col = curr.second;

        // Skip if already processed (could be pushed multiple times)
        if (visited[row][col]) continue;

        // Mark visited at processing time — not when pushed
        visited[row][col] = true;

        cout << "Current cell: (" << row << ", " << col << ") "
             << "with Value: " << grid[row][col] << endl;

        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            // Only check bounds + not-yet-visited; don't mark visited here
            if (inBounds(newRow, newCol) && !visited[newRow][newCol]) {
                st.push({newRow, newCol});
            }
        }
    }
}

int main() {
    int grid[ROWS][COLS] = {
        {-1, 2, 3},
        {0, 9, 8},
        {1, 0, 1}
    };

    memset(visited, false, sizeof(visited));

    dfs(grid, 0, 0);

    return 0;
}