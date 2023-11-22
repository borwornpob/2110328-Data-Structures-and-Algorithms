#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Monster {
    int position;
    int health;
};

bool compareMonster(const Monster &a, const Monster &b) {
    return a.position < b.position;
}

int main() {
    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<Monster> monsters(m);
    vector<int> towers(k);

    for (int i = 0; i < m; ++i) {
        cin >> monsters[i].position;
    }

    for (int i = 0; i < m; ++i) {
        cin >> monsters[i].health;
    }

    for (int i = 0; i < k; ++i) {
        cin >> towers[i];
    }

    sort(monsters.begin(), monsters.end(), compareMonster);

    sort(towers.begin(), towers.end());

    for (int i = 0; i < k; ++i) {
        int towerPos = towers[i];
        int maxHealth = 0;
        int maxIndex = -1;
        for (int j = 0; j < m; ++j) {
            if (monsters[j].position >= towerPos - w && monsters[j].position <= towerPos + w) {
                if (monsters[j].health > maxHealth) {
                    maxHealth = monsters[j].health;
                    maxIndex = j;
                }
            }
        }
        if (maxIndex != -1) {
            monsters[maxIndex].health--;
        }
    }

    int totalHealth = 0;
    for (int i = 0; i < m; ++i) {
        totalHealth += monsters[i].health;
    }
    cout << totalHealth << endl;

    return 0;
}
