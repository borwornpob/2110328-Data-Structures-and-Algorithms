#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
  //write your code here
  long long current = 0;
  long long target = 0;

  for (size_t i = 0; i < pos.size(); i++) {
    while (current < pos[i]) {
      mData[target++] = mData[current++];
    }
    ++current;
  }

  while (current < mSize) {
    mData[target++] = mData[current++];
  }

  mSize = target;
}

#endif
