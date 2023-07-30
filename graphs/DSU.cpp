#include <bits/stdc++.h>
using namespace std;

struct DSU{

    vector<int> parent;
    vector<int> sz;

    void init(int n){

        parent.resize(n);
        sz.resize(n);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
            sz[i] = 1;
        }

    }

    int find(int a){
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }

    void unite(int a,int b){
        a = find(a);
        b = find(b);

        if(a != b){
            if(sz[a] < sz[b]) swap(a , b);

            parent[a] = b;
            sz[a] += sz[b];
        }
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}