#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    T t = mData[mFront];
    mData[mFront] = mData[(mFront + pos) % mCap];

    for (int i = mFront + 1; i <= mFront + pos; i++) {
        T tmp = mData[i % mCap];
        mData[i % mCap] = t;
        t = tmp;
    }
}


#endif
