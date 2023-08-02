#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
using namespace __gnu_pbds;
using ll=long long;
using ld=long double;
using vi=vector<int>;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

// Tested in https://judge.yosupo.jp/problem/scc

const int MXN =5e5+10;
vector<int> AL[MXN], AL_T[MXN];
int vis[MXN];
vector<int> order;
int ans = 0;
vector<vector<int>> components;

void Kosaraju(int x,int step){
    vis[x] = 1;
    if(step == 1){

        for(auto &u:AL[x]){

            if(vis[u] == 0){
                Kosaraju(u,step);
            }

        }

        order.push_back(x);
    }else{
        components[ans].push_back(x);
        for(auto &u:AL_T[x]){

            if(vis[u] == 0){
                Kosaraju(u,step);
            }

        }

    }
}

void init(int n){
    for(int i = 0; i < n; i++) vis[i] = 0;
}

void SCC(int n){

    init(n);

    for(int i = 0; i < n ; i++){
        if(!vis[i]) Kosaraju(i,1);
    }

    init(n);

    for(int i = n - 1; i >= 0; i--){
        if(!vis[order[i]]){
            components.push_back({});
            Kosaraju(order[i],2);
            ans++;
        }
    }
    cout << ans <<'\n';
    for(int i = 0; i < ans; i++){
        cout << components[i].size() <<" ";
        for(auto &u: components[i]) cout << u <<" ";
        cout <<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        AL[a].push_back(b);
        AL_T[b].push_back(a);
    }
    SCC(n);
}