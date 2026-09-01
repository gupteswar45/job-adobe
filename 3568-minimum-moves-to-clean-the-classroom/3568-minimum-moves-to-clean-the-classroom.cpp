class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Each litter cell ko ek unique bit denge
        vector<vector<int>> id(m, vector<int>(n, -1));

        int sx = 0, sy = 0;
        int litterCount = 0;

        // Start position aur litter find karo
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        // Agar litter hi nahi hai
        if (litterCount == 0)
            return 0;

        /*
            mask:
            1 = litter abhi collect nahi hua
            0 = litter collect ho gaya

            Example:
            3 litter -> 111
            First litter collect -> 110
            Second collect -> 100
            All collect -> 000
        */

        int fullMask = (1 << litterCount) - 1;

        // visited[x][y][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litterCount, false)
                )
            )
        );

        // x, y, currentEnergy, mask
        queue<tuple<int, int, int, int>> q;

        q.push({sx, sy, energy, fullMask});
        visited[sx][sy][energy][fullMask] = true;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [x, y, currEnergy, mask] = q.front();
                q.pop();

                // Saara litter collect ho gaya
                if (mask == 0)
                    return moves;

                // Energy 0 hai aur reset cell par nahi hain
                if (currEnergy == 0)
                    continue;

                // 4 directions
                for (int k = 0; k < 4; k++) {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    // Boundary check
                    if (nx < 0 || nx >= m ||
                        ny < 0 || ny >= n)
                        continue;

                    // Wall
                    if (classroom[nx][ny] == 'X')
                        continue;

                    // Normal movement -> energy - 1
                    int newEnergy = currEnergy - 1;

                    // Reset cell -> energy full
                    if (classroom[nx][ny] == 'R') {
                        newEnergy = energy;
                    }

                    int newMask = mask;

                    // Agar litter hai
                    if (classroom[nx][ny] == 'L') {

                        int bit = id[nx][ny];

                        // Us litter ko collected mark karo
                        newMask &= ~(1 << bit);
                    }

                    // Agar state pehle visit nahi hui
                    if (!visited[nx][ny][newEnergy][newMask]) {

                        visited[nx][ny][newEnergy][newMask] = true;

                        q.push({
                            nx,
                            ny,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};