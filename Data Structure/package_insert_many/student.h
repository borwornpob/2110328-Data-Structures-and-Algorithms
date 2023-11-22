#ifndef __STUDENT_H_
#define __STUDENT_H_
#define ll long long

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int,T>> data) {
  //write your code here
  std::sort(data.begin(), data.end());

  T *newData = new T[mSize + data.size()];

  ll current = 0;
  ll target = 0;

  for (ll i = 0; i < mSize; i++) {
    if(i == data[current].first) {
        newData[target++] = data[current++].second;
    }
    newData[target++] = mData[i];
  }

  // for the end
  if (data[data.size() - 1].first == mSize) {
    newData[target] = data[data.size() - 1].second;
  }

  delete[] mData;
  mSize = mSize + data.size();
  mCap = mSize;
  mData = newData;
  ensureCapacity(mCap);
}

#endif
