#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
using namespace __gnu_pbds;
using ll=long long;
using ld=long double;
using vi=vector<int>;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

vector<int> ans;
vector<bool> vis;

void toposort(int x, vector<vector<int>> &AL){
    vis[x] = true;
    for(auto &u:AL[x]){
        if(!vis[u]) toposort(u,AL);
    }
    ans.push_back(x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 7;
    vis.assign(n,false);

    vector<vector<int>> AL(n);

    AL[0] = {1,3};
    AL[1] = {2 ,4};
    AL[3] = {4 ,6};
    int tam = n;

    for(int i = 0; i < tam; i++){
        if(!vis[i]) toposort(i,AL);
    }

    reverse(ans.begin(),ans.end());
    for(auto &u: ans) cout << u <<" ";
    cout <<'\n';
}