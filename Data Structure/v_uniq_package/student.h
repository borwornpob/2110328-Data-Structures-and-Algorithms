#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <unordered_set>
#include <algorithm>

template <typename T>
void CP::vector<T>::uniq() {
    std::unordered_set<T> s;
    CP::vector<T> v;

    for (const auto& elem : *this) {
        if (s.find(elem) == s.end()) {
            s.insert(elem);
            v.push_back(elem);
        }
    }

    *this = v;
}

#endif
