#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
#include <map>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        n = 3;
        adjacencyMatrix.resize(3, std::vector<bool>(3, false));
    }

    DenseGraph(int n_in) {
        n = n_in;
        adjacencyMatrix.resize(n, std::vector<bool>(n, false));
    }

    DenseGraph(const DenseGraph& G) {
        n = G.n;
        adjacencyMatrix = G.adjacencyMatrix;
    }

    void AddEdge(int a, int b) {
        adjacencyMatrix[a][b] = true;
    }

    void RemoveEdge(int a, int b) {
        adjacencyMatrix[a][b] = false;
    }

    bool DoesEdgeExist(int a, int b) const {
        if (adjacencyMatrix[a][b])
            return true;

        return false;
    }

    DenseGraph Transpose() const {
        DenseGraph transpose(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                transpose.adjacencyMatrix[i][j] = adjacencyMatrix[j][i];
            }
        }

        return transpose;
    }

protected:
    int n;
    vector<vector<bool>> adjacencyMatrix;
};
#endif // __DENSE_GRAPH_H__
