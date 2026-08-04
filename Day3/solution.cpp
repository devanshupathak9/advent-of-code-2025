#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
typedef long long ll;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

template <typename T>
void print_vector(vector<T> &value) {
    for (auto val : value)
        cout << val << " ";
    print("");
}

int findLargestIndex(string bank, int start, int end) {
    int maxVal = 0;
    int indx;
    for (int i = start; i < end; i++) {
        int val = bank[i] - '0';
        if (val > maxVal) {
            indx = i;
            maxVal = val;
        }
    }
    return indx;
}

class Solution {
public:
    int solve(vector<string> &banks) {
        int totalJoltage = 0;
        int indx, start;
        string maxJoltage;
        for (auto bank : banks) {
            start = 0;
            maxJoltage = "";
            for (int i = 0; i < 2; i++) {
                indx = findLargestIndex(bank, start, bank.size() - 1 + i);
                maxJoltage += bank[indx];
                start = indx + 1;
            }
            totalJoltage += stoi(maxJoltage);
        }
        return totalJoltage;
    }

    ll solvep2(vector<string> &banks) {
        ll totalJoltage = 0;
        int indx, start;
        string maxJoltage;
        for (auto bank : banks) {
            start = 0;
            maxJoltage = "";
            for (int i = 0; i < 12; i++) {
                indx = findLargestIndex(bank, start, bank.size() - 11 + i);
                maxJoltage += bank[indx];
                start = indx + 1;
            }
            totalJoltage += stoll(maxJoltage);
        }
        return totalJoltage;
    }
};

int main() {
    string line;
    vector<string> banks;

    ifstream file("data.txt");
    while (getline(file, line)) {
        banks.push_back(line);
    }

    Solution sol;
    int res1 = sol.solve(banks);
    print(res1);

    ll res2 = sol.solvep2(banks);
    print(res2);

    return 0;
}