#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, year, month;
    cin >> n >> m;
    
    set<pair<int, int>> publications;

    for (int i = 0; i < n; ++i) {
        cin >> year >> month;
        publications.insert({year, month});
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> year >> month;
        auto it = publications.lower_bound({year, month});
        
        if (it != publications.end() && *it == make_pair(year, month)) {
            cout << "0 0 ";
        } else {
            if (it == publications.begin()) {
                cout << "-1 -1 ";
            } else {
                --it;
                cout << it->first << " " << it->second << " ";
            }
        }
    }
    cout << '\n';

    return 0;
}
