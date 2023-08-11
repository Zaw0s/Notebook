#include <bits/stdc++.h>
using namespace std;

const int MXN =2e5;
vector<int> AL[MXN], AL_T[MXN];
int vis[MXN];
vector<int> order;
int ans = 0;

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

    for(int i = 0; i < MXN ; i++){
        if(!vis[i]) Kosaraju(i,1);
    }

    init(n);

    for(int i = MXN - 1; i >= 0; i--){
        if(!vis[order[i]]){
            Kosaraju(order[i],2);
            ans++;
        }
    }

    cout << ans <<'\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

}
