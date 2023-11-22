#include <iostream>
#include <map>

using namespace std;

int countWays(int N, int last, int sum) {
    if (sum == N) {
        return 1;
    }

    if (sum > N) {
        return 0;
    }

    int count = 0;

    for (int i = last; i <= N; ++i) {
        count += countWays(N, i, sum + i);
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    int result = countWays(N, 1, 0);

    cout << result;

    return 0;
}