#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> v(100001,0);
unordered_map<int,int> M;

int main(){
    int n,m,st;
    cin >> n >> m >> st;
    for(int i = 0; i < n; ++i){
        int a,b;
        cin >> a >> b;
        M.emplace(a, b);
    }
    v[0] = st;
    int money = st;
    for(int i = 1; i <= 100000; ++i){
        if(M.find(i) != M.end()){
            money = M[i];
        }
        v[i] = v[i-1] + money;
    }
    for(int i = 0; i < m; ++i){
        int a ,b;
        cin >> a >> b;
        int ans = a + v[b];
        if(a <= v[b]){
            ans = a;
        }
        auto pos = lower_bound(v.begin(),v.end(),ans) - v.begin();
        cout << pos << " ";
    }
}