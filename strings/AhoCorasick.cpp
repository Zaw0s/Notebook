#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
using namespace std;
using namespace __gnu_pbds;
using ll=long long;
using ld=long double;
using vi=vector<int>;
using lnum = vector<ll>;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

const ll base = 1000000000;

lnum ADD(lnum const& a,lnum const &b){
    ll carry = 0;
    lnum c = a;
    for(int i = 0; i < max(c.size(),b.size())||carry;i++){
        if( i == c.size()){
            c.push_back(0);
        }
        c[i] += carry + (i < b.size() ? b[i] : 0);
        carry = c[i]>=base;
        if(carry) c[i] -=base;
    }
    return c;
}

int sz = 1;
const int K = 50;

struct Vertex{
    
    int next[K];
    int go[K];
    char pch;
    bool output = false;
    int p = -1;
    int link = -1;
    Vertex(){
        fill(begin(next),end(next),-1);
        fill(begin(go),end(go),-1);
    }
};

map<char,int> mp;
vector<Vertex> Trie(1);

void add_string(string const &s){
    int p1 = 0;
    for(int i = 0; i<s.size();i++){
        if(Trie[p1].next[mp[s[i]]] == -1){
            Trie.emplace_back();
            Trie[(int)Trie.size() - 1].p = p1;
            Trie[(int)Trie.size() - 1].pch = s[i];
            Trie[p1].next[mp[s[i]]] = (int)Trie.size() - 1;
            sz++;
        }
            p1 = Trie[p1].next[mp[s[i]]];
    }
    Trie[p1].output = true;
}

int go(int v,char ch);

int get_link(int v){
    if(Trie[v].link == -1){
        if(v == 0 ||Trie[v].p == 0){
            Trie[v].link = 0;
        }else{
            Trie[v].link = go(get_link(Trie[v].p),Trie[v].pch);
        }
    }
    return Trie[v].link;
}

int go(int v,char ch){
    int c = mp[ch];
    if(Trie[v].go[c] == -1){
        if(Trie[v].next[c] != -1){
            Trie[v].go[c] = Trie[v].next[c];
        }else{
            Trie[v].go[c] = v == 0 ? 0 : go(get_link(v),ch);
        }
    }
    return Trie[v].go[c];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m , p;
    cin >> n >> m >> p;
    queue<int> q;
    string letters;
    cin.ignore();
    getline(cin,letters);
    map<int,char> rev;
    for(int i = 0; i < n; i++){
        mp[letters[i]] = i;
        rev[i] = letters[i];
    }
    string palabra;

    FOR(i,0,p){
        cin >> palabra;
        add_string(palabra);
    }
    for(int i = 0;i<sz;i++){
        for(int j = 0; j < n; j++){
            go(i,rev[j]);
        }
    }

    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(Trie[get_link(u)].output){
            Trie[u].output = true;
        }
        for(int i = 0; i < n; i++){
            if(Trie[u].next[i]!=-1) q.push(Trie[u].next[i]);
        }
    }
    


    vector<lnum> dp(sz);
    dp[0].push_back(1);
    for(int i = 0; i < m; i++){
        vector<lnum> dp1(sz,{0});
        for(int j = 0; j < sz; j++){
            for(int z = 0; z < n; z++){
                if(Trie[j].output) continue;
                if(Trie[Trie[j].go[z]].output) continue;
                dp1[Trie[j].go[z]] = ADD(dp1[Trie[j].go[z]],dp[j]);
            }
        }
        dp = dp1;
    }
    lnum ans ={0};
    for(int i = 0; i < sz;i++){
        ans = ADD(ans,dp[i]);
    }


        printf ("%d", ans.empty() ? 0 : ans.back());
        for (int i=(int)ans.size()-2; i>=0; --i)
        printf ("%09d", ans[i]);
        
        printf("\n");
}