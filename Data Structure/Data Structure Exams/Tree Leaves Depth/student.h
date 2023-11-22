#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, size_t aux) {
    if (n->right == nullptr && n->left == nullptr) {
        return aux;
    }

    if (n->right != nullptr && n->left == nullptr) {
        return my_recur(n->right, aux + 1);
    }

    if (n->left != nullptr && n->right == nullptr) {
        return my_recur(n->left, aux + 1);
    }

    if (n->left != nullptr && n->right != nullptr) {
        return (my_recur(n->left, aux + 1) + my_recur(n->right, aux + 1));
    }
}

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::sum_leaves_depth() {
  write your code here
  if (this->mSize == 0)
      return 0;
  size_t pathLength = 0;
  return my_recur(mRoot, pathLength);
}

#endif
