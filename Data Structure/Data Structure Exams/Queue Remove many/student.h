#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
    std::sort(pos.begin(), pos.end());
    // if (pos[pos.size() - 1] > mSize) {
    //     return;
    // }

    int indexForPos = 0;

    CP::queue<T> trim;

    for (size_t i = 0; i < mSize; ++i) {
        if (i != pos[indexForPos]) {
            trim.push(mData[(mFront + i) % mCap]);
        } else {
            indexForPos++;
        }
    }

    *this = trim;
}

#endif
