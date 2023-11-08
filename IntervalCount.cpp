#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unsigned long long n, m, k;

    cin >> n >> m >> k;

    vector<unsigned long long> N(n);

    for (unsigned long long i = 0; i < n; i++) {
        cin >> N[i];
    }

    sort(N.begin(), N.end());

    for (unsigned long long i = 0; i < m; i++) {
        unsigned long long p;
        cin >> p;

        auto start_it = lower_bound(N.begin(), N.end(), p > k ? p - k : 0);
        auto end_it = upper_bound(N.begin(), N.end(), p + k);

        unsigned long long count = distance(start_it, end_it);

        cout << count << " ";
    }

    cout << endl;

    return 0;
}
