#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v = A;

    for (const auto& elem : B) {
        if (find(v.begin(), v.end(), elem) == v.end()) {
            v.push_back(elem);
        }
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    unordered_set<T> s(B.begin(), B.end());
    vector<T> v;

    for (const auto& elem : A) {
        if (s.find(elem) != s.end()) {
            v.push_back(elem);
        }
    }

    return v;
}