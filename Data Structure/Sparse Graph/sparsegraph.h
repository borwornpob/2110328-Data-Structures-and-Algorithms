#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here

using namespace std;

struct EdgeNode {
    int dest;
    EdgeNode *next;
    EdgeNode *prev;

    EdgeNode(int d) : dest(d), next(nullptr), prev(nullptr) {}
};

class SparseGraph{
public:
    SparseGraph() {
        // Your code here
        v = new EdgeNode *[3]();
        mSize = 3;
    }

    SparseGraph(int n_in) {
        int n = n_in;
        v = new EdgeNode *[n]();
        mSize = n;
    }

    ~SparseGraph() {
        for (int i = 0; i < mSize; ++i) {
            EdgeNode* current = v[i];
            while (current != nullptr) {
                EdgeNode* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] v;
    }

    SparseGraph(const SparseGraph& G) {
        mSize = G.mSize;
        v = new EdgeNode *[mSize]();

        for (int i = 0; i < mSize; ++i) {
            EdgeNode *current = G.v[i];
            EdgeNode **tail = &v[i];

            while (current != nullptr) {
                EdgeNode *newNode = new EdgeNode(current->dest);
                *tail = newNode;
                tail = &newNode->next;

                current = current->next;
            }
        }
    }

    SparseGraph& operator=(const SparseGraph& G) {
        if (this != &G) {
            for (int i = 0; i < mSize; ++i) {
                EdgeNode* current = v[i];
                while (current != nullptr) {
                    EdgeNode* temp = current;
                    current = current->next;
                    delete temp;
                }
            }
            delete[] v;

            mSize = G.mSize;
            v = new EdgeNode*[mSize]();
            for (int i = 0; i < mSize; ++i) {
                EdgeNode* currentInG = G.v[i];
                EdgeNode** tail = &v[i];

                while (currentInG != nullptr) {
                    EdgeNode* newNode = new EdgeNode(currentInG->dest);
                    *tail = newNode;
                    tail = &newNode->next;

                    currentInG = currentInG->next;
                }
            }
        }
        return *this;
    }

    void AddEdge(int a, int b) {
        if (!DoesEdgeExist(a,b)) {
            EdgeNode *newNode = new EdgeNode(b);
            newNode->next = v[a];
            if (v[a] != nullptr) {
                v[a]->prev = newNode;
            }
            v[a] = newNode;
        }
    }

    void RemoveEdge(int a, int b) {
        EdgeNode* current = v[a];
        while (current != nullptr) {
            if (current->dest == b) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                }
                if (current == v[a]) {
                    v[a] = current->next;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    bool DoesEdgeExist(int a, int b) const {
        EdgeNode* current = v[a];
        while (current != nullptr) {
            if (current->dest == b) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    SparseGraph Transpose() const {
        SparseGraph transposedGraph(mSize);
        for (int i = 0; i < mSize; ++i) {
            EdgeNode* current = v[i];
            while (current != nullptr) {
                transposedGraph.AddEdge(current->dest, i);
                current = current->next;
            }
        }
        return transposedGraph;
    }

protected:
    EdgeNode **v;
    int mSize;
};
#endif // __SPARSE_GRAPH_H__

