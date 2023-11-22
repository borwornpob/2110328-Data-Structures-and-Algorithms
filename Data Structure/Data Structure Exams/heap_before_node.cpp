#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << "0" << endl;
        return 0;
    }

    vector<long long> result;

    if ((k - 2) % 2 == 0) {
        // right child
        vector<long long> valueToCheck;
        valueToCheck.push_back(k);
        for (long long i = 0; i < n; ++i)
        {
            if (find(valueToCheck.begin(), valueToCheck.end(), i) != valueToCheck.end())
            {
                valueToCheck.push_back((2 * i) + 1);
                valueToCheck.push_back((2 * i) + 2);
            }
            else
            {
                result.push_back(i);
            }
        }

        cout << result.size() << endl;
        for (long long i = 0; i < result.size(); ++i)
        {
            cout << result[i] << " ";
        }
    } else {
        vector<long long> valueToCheck;
        valueToCheck.push_back(k);
        for (long long i = 0; i < n; ++i)
        {
            if (find(valueToCheck.begin(), valueToCheck.end(), i) == valueToCheck.end())
            {
                result.push_back(i);
            }
            else
            {
                valueToCheck.push_back((2 * i) + 1);
                valueToCheck.push_back((2 * i) + 2);
            }
        }

        cout << result.size() << endl;
        for (long long i = 0; i < result.size(); ++i)
        {
            cout << result[i] << " ";
        }
    }
}