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
const ll MOD = 1e9+7;
ll binpow( ll a, ll b){
    ll ans = 1;
    ll mul = a;
    while( b > 0 ){
        if( b & 1 ){
            ans = ( ans * mul )%MOD;
        }
        mul = ( mul * mul )%MOD;
        b/=2;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
