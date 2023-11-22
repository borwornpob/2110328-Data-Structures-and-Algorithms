void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    if (mSize == 0)
        return;

    node *a, *b;

    int mid = (mSize + 1) / 2;
    a = this->begin().ptr;

    for (int i = 0; i < mid - 1; ++i) {
        a = a->next;
    }
    b = a->next;

    list1.end().ptr->prev->next = this->begin().ptr;
    this->begin().ptr->prev = list1.end().ptr->prev;

    a->next = list1.end().ptr;
    list1.end().ptr->prev = a;

    list1.mSize += mid;

    list2.end().ptr->prev->next = b;
    b->prev =  list2.end().ptr->prev;

    this->end().ptr->prev->next = list2.end().ptr;
    list2.end().ptr->prev = this->end().ptr->prev;

    list2.mSize += mSize-mid;

    mSize = 0;
    mHeader->next = mHeader;
}
