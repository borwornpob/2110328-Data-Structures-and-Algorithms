#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::insert(iterator position,iterator first,iterator last) {
  //write your code here
  long long newElementSize = std::distance(first, last);

  T *newData = new T[mSize + newElementSize];

  iterator it = std::copy(mData, position, newData);

  it = std::copy(first, last, it);

  std::copy(position, mData + mSize, it);

  delete[] mData;
  mData = newData;
  mSize = mSize + newElementSize;
}

#endif
