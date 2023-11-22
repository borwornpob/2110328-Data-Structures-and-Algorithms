#include <iostream>
#include <set>
#include <utility>

using namespace std;

// Function to add and merge intervals
void buyProperty(set<pair<int, int>>& intervals, int start, int end) {
    // Temporary interval for comparison
    auto it = intervals.lower_bound({start, end});

    // Adjust the starting point for merging. This is for adjacent intervals
    if (it != intervals.begin() && prev(it)->second + 1 >= start) {
        --it;
    }

    // Merging overlapping or adjacent intervals
    while (it != intervals.end() && it->first - 1 <= end) {
        start = min(start, it->first);
        end = max(end, it->second);
        it = intervals.erase(it);
    }

    // Adding the merged interval
    intervals.insert({start, end});
}

// Function to report intervals
void reportProperties(const set<pair<int, int>>& intervals) {
    // for (const auto& interval : intervals) {
    //     cout << interval.first << " " << interval.second << "\n";
    // }
    cout << intervals.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // Number of actions
    cin >> n;

    set<pair<int, int>> intervals;

    for(int i = 0; i < n; ++i) {
        int action, start, end;
        cin >> action;

        if (action == 1) { // Buy action
            cin >> start >> end;
            buyProperty(intervals, start, end);
        } else if (action == 2) { // Report action
            reportProperties(intervals);
        }
    }

    return 0;
}
