#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
typedef long long ll;

template <typename T>
void print(T value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> value) {
    for (auto it: value) {
        cout << it << " ";
    }
    print("");
}

ll performOp(vector<int> &numbers, char op) {
    ll ans;
    if (op == '*') {
        ans = 1;
        for (auto it: numbers) ans = ans * it;
    } else {
        ans = 0;
        for (auto it: numbers) ans = ans + it;
    }
    return ans;
}

vector<int> findNumber(vector<string> &words) {
    vector<int> number;
    print_vector(words);
    for (int j = 0; j < words.size(); j++) {
        string num = "";
        for (int i = 0; i < words.size(); i++) {
            if (words[i][j] != 'x') {
                num += words[i][j];
            }
        }
        number.push_back(stoi(num));
    }
    print_vector(number);
    return number;
}

class Solution {
public:
    ll solve(vector<vector<string>> &data, vector<char> &operation) {
        ll ans, total = 0;
        for (int j = 0; j < operation.size(); j++) {
            char op = operation[j];
            if (op == '*') {
                ans = 1;
                for (int i = 0; i < data.size(); i++) {
                    ans = ans * stoll(data[i][j]);
                }
            } else {
                ans = 0;
                for (int i = 0; i < data.size(); i++) {
                    ans = ans + stoll(data[i][j]);
                }
            }
            total = total + ans;
        }
        return total;
    }

    ll solve2(vector<string> &lines) {
        ll total = 0;
        string num;
        vector<int>number;
        vector<string> words;
        int n = lines[0].size();
        for (int j = n-1; j >= 0; j--) {
            num = "";
            for(int i = 0; i < lines.size() - 1; i++) {
                if (lines[i][j] != ' ') {
                    num += lines[i][j];
                }
            }
            if (num != "") number.push_back(stoi(num));

            if (lines.back()[j] == '*' || lines.back()[j] == '+') {
                if (!number.empty()) {
                    total += performOp(number, lines.back()[j]);
                    number.clear();
                }
                continue;
            }
        }
        return total;  
    }
};

int main() {
    vector<vector<string>> data;
    vector<char> operation;
    vector<string>lines;
    ifstream file("data.txt");
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
        size_t pos = line.find('+');
        if (pos == string::npos) {
            string word;
            stringstream ss(line);
            vector<string> words;
            while (ss >> word) {
                words.push_back(word);
            }
            data.push_back(words);
        } else {
            for (auto it: line) {
                if (it != ' '){
                    operation.push_back(it);
                }
            }
        }
    }
    
    Solution sol;
    ll ans1 = sol.solve(data, operation);
    print(ans1);

    ll ans2 = sol.solve2(lines);
    print(ans2);

    return 0;
}