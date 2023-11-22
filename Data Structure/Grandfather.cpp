#include <iostream>
#include <unordered_map>
using namespace std;

long long find_grandfather(long long person, unordered_map<long long, long long> &parent) {
    if (parent.find(person) == parent.end()) return -1;
    long long father = parent[person];
    if (parent.find(father) == parent.end()) return -1;
    return parent[father];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    unordered_map<long long, long long> parent;

    for (long long i = 0; i < N; ++i) {
        long long F, S;
        cin >> F >> S;
        parent[S] = F;
    }

    for (long long i = 0; i < M; ++i) {
        long long A, B;
        cin >> A >> B;
        long long grandfatherA = find_grandfather(A, parent);
        long long grandfatherB = find_grandfather(B, parent);

        if (grandfatherA == grandfatherB && grandfatherA != -1 && A != B) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
