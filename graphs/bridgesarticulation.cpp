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

vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
int UNVISITED  = -1;
vector<vector<int>> AL;
void articulationPointAndBridge(int u){

    dfs_num[u] = dfsNumberCounter++;
    dfs_low[u] = dfs_num[u];

    for(auto & v: AL[u]){
        if(dfs_num[v] == UNVISITED){

            dfs_parent[v] = u;
            if( u == dfsRoot) ++rootChildren;

            articulationPointAndBridge(v);

            if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u] = 1; // es de articulación
            if(dfs_low[v] > dfs_num[u]){
                cout << u <<" " <<v <<'\n'; // u,v es bridge
            }
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
        }else if( v != dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u],dfs_num[v]);
        }
        
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    dfs_num.assign(n,UNVISITED);
    dfs_low.assign(n,0);
    dfs_parent.assign(n,-1);
    articulation_vertex.assign(n,0);
    dfsNumberCounter = 0;

    for(int i = 0; i < n; i++){
        if(dfs_num[i] == UNVISITED){
            dfsRoot = i;
            rootChildren = 0;
            articulationPointAndBridge(i);
            articulation_vertex[dfsRoot] = (rootChildren > 1); // Caso especial de la raíz
        }
    }
}
