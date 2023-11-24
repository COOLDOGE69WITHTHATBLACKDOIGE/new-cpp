#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N; // Number of modules
    cin >> N;

    vector<pair<int, int>> modules(N);

    for (int i = 0; i < N; i++) {
        cin >> modules[i].first >> modules[i].second;
    }

    // Sort modules by level and complexity
    sort(modules.begin(), modules.end());

    int b = 0; // Variable to store the total complexity

    for (int i = 0; i < N; i++) {
        int level = modules[i].first;
        int complexity = modules[i].second;

        if (i + 1 < N && modules[i + 1].first == level) {
            // If there is another module with the same level, combine them
            int next_complexity = modules[i + 1].second;
            b += complexity + next_complexity; // Add their complexities
            i++; // Skip the next module as it has been combined
        } else {
            // No other module with the same level, add its complexity
            b += complexity;
        }
    }

    cout << b << endl; // Output the total complexity

    return 0;
}
