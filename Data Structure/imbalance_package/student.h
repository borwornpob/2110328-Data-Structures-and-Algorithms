#ifndef __STUDENT_H__
#define __STUDENT_H__

int calculateHeight(Node *n, KeyT &key, int &bal) {
    int height = 0;
    if (n == nullptr)
        return -1;

    int heightL = calculateHeight(n->left, key, bal);
    int heightR = calculateHeight(n->right, key, bal);

    int newBal = (heightL - heightR) >= 0 ? (heightL - heightR) : (heightR - heightL);
    if (newBal > bal) {
        key = n->data.first;
        bal = newBal;
    } else if (newBal == bal) {
        key = n->data.first;
    }

    return 1 + std::max(heightL, heightR);
}

KeyT getValueOfMostImbalanceNode() {
    int maxBal = 0;
    KeyT minKey = mRoot->data.first;
    calculateHeight(mRoot, minKey, maxBal);

    return minKey;
}

#endif __STUDENT_H__
