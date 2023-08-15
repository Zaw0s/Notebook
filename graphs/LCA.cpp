const int N = 2e5;

int up[N][20];
int parent[N];
int depth[N];

void fill(){

    for(int i = 0; i < n; i++){
        up[i][0] = parent[i];
    }

    for(int i = 1; i < 20; i++){
        for(int j = 0 ; j < N; j++){
            up[j][i] = up[up[j][i-1]][i-1];
        }
    }

}


int jump(int x,int d){
    for(int i = 19; i >= 0; i--){
        if( (d &(1<<i)) == 1){
            x = up[x][i];
        }
    }
    return x;
}

int LCA(int x,int y){

    if(depth[x] < depth[y]) swap(x,y);

    x = jump(x, depth[y]-depth[x]);

    if(x == y) return x;

    for(int i = 19; i>= 0; i--){
        if(up[x][i] != up[y][i]){
            x = up[x][i];
            y = up[y][i];
        }
    }

    return up[x][0];

}
