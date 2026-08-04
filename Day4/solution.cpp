#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

bool isValid(int x, int y, int r, int c) {
    if (x < 0 || x >= r || y < 0 || y >= c)
        return false;
    return true;
}

class Solution {
private:
    vector<pair<int, int>> actions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
public:
    vector<pair<int, int>> getIndexes(vector <string> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int answer = 0, counter;
        vector<pair<int, int>> p;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    counter = 0;
                    for (auto it: actions) {
                        int x = i + it.first;
                        int y = j + it.second;
                        if (isValid(x, y, n, m) && grid[x][y] == '@') {
                            counter += 1;
                        }
                    }
                    if (counter < 4) p.push_back({i, j});
                }
            }
        }
        return p;
    }

    int solve(vector <string> &grid) {
        vector<pair<int, int>> coordinates = ge
        return answer;
    }


    int solvep2(vector <string> &grid) {
        int answer = 0;
        while (true) {
            vector<pair<int, int>> p = getIndexes(grid);
            if (p.empty()) {
                break;
            }
            answer += p.size();
            for (auto it: p) {
                grid[it.first][it.second] = 'x';
            }
        }
        return answer;
    }
};

int main() {
    string line;
    ifstream file("data.txt");
    vector <string> grid;
    while (getline(file, line)) {
        grid.push_back(line);
    }

    Solution sol;
    int answer = sol.solve(grid);
    print(answer);

    int answer2 = sol.solvep2(grid);
    print(answer2);
    return 0; 
}