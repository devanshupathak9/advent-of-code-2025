#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
typedef long long ll;

template <typename T>
void print(T &value) {
    cout << value << "\n";
}

vector<pair<ll, ll>> mergeIntervals(vector<pair<ll, ll>> &ingRange) {
    vector<pair<ll, ll>> stack = {ingRange[0]};
    for (int i = 1; i < ingRange.size(); i++) {
        if (ingRange[i].first > stack.back().second) {
            stack.push_back(ingRange[i]);
        }
        else {
            stack.back().second = max(stack.back().second, ingRange[i].second);
        }
    }
    return stack;
}

bool checkRange(vector<pair<ll, ll>> &mergedIngredientRange, ll ingredient) {
    int mid;
    int result = -1;
    int start = 0;
    int end = mergedIngredientRange.size() - 1;
    while (start <= end) {
        mid = start + (end - start) / 2;
        if (mergedIngredientRange[mid].first == ingredient)
            return true;
        if (mergedIngredientRange[mid].first > ingredient)
        {
            end = mid - 1;
        }
        else if (mergedIngredientRange[mid].first < ingredient)
        {
            result = mid;
            start = mid + 1;
        }
    }
    if (ingredient >= mergedIngredientRange[result].first && ingredient <= mergedIngredientRange[result].second) {
        return true;
    }
    return false;
}
c
class Solution {
private:
    vector<pair<ll, ll>> ingRange;
    vector<ll> avaIngrd;
public:
    Solution(vector<pair<ll, ll>> &iR, vector<ll> &aI) : ingRange(iR), avaIngrd(aI) {
        sort(ingRange.begin(), ingRange.end(),
             [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
                 if (a.first == b.first) {
                     return a.second < b.second;
                }
                 return a.first < b.first;
            });
    }

    int solvep1() {
        int count = 0;
        vector<pair<ll, ll>> ingridientRange = mergeIntervals(ingRange);
        for (auto it : avaIngrd) {
            if (checkRange(ingridientRange, it)) {
                count++;
            }
        }
        return count;
    }

    ll solvep2() {
        ll count = 0;
        vector<pair<ll, ll>> ingridientRange = mergeIntervals(ingRange);
        for (auto it : ingridientRange) {
            count += it.second - it.first + 1;
        }
        return count;
    }
};

pair<ll, ll> parseLine(string line) {
    size_t index = line.find('-');
    string s1 = line.substr(0, index);
    string s2 = line.substr(index + 1);
    if (s1.empty() || s2.empty())
    {
        throw invalid_argument("Empty substring after parsing");
    }
    return {stoll(s1), stoll(s2)};
}

int main() {
    vector<pair<ll, ll>> ingRange;
    vector<ll> avaIngrd;
    ifstream file("data.txt");
    string line;

    while (getline(file, line)) {
        if (line.find('-') != string::npos) {
            pair<ll, ll> p = parseLine(line);
            ingRange.push_back(p);
        }
        else if (line.size()) {
            avaIngrd.push_back(stoll(line));
        }
    }

    Solution sol(ingRange, avaIngrd);
    int answer1 = sol.solvep1();
    print(answer1);

    ll answer2 = sol.solvep2();
    print(answer2);
    return 0;
}