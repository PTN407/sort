
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;



//----------define--------------//
#define FILE_IN     "B.inp"
#define FILE_OUT    "B.out"
#define ofile       freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio         ios::sync_with_stdio(0);cin.tie(0)
#define MOD         (ll(998244353))
#define MAXN        100010
#define INF         (ll(1000000007))
#define x           first
#define y           second
#define pii         pair<int,int>
#define pll         pair<long long,long long>
#define pli         pair<long long, int>
#define piii        pair<int,pii>
#define pb          push_back
#define endl        "\n"
#define vt          vector
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> order_set;
typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> order_trie;
typedef long long ll;

//---------functions-------------//
class DisjointSet{ public:
    vector<int> parent, size;
    DisjointSet(int n): parent(n), size(n) { for(int i=0; i<n; i++) {parent[i] = i; size[i] = 0;}; }
    int sz(int a){return size[find(a)];}
    void join(int a, int b) { if (!check(a, b)) size[find(a)] += size[find(b)]; parent[find(b)] = find(a); }
    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }
    bool check(int a, int b){ return find(a) == find(b); }
};
ll powmod(ll a,ll b) {ll res=1;a%=MOD; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

//---------END-------------------//
const int SIZE = 1000000;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double random_double(){
    return rng() / pow(10, rng() % 9);
}
int random_int(int l, int r){
    return rng() % (r - l + 1) + l;
}
vector<double> dat[10];

int main(){
    freopen("test.txt", "w", stdout);
    for (int i = 0; i < 10; i++){
        dat[i].resize(SIZE);
        for (double &j : dat[i])
            j = random_double();
    }
    sort(dat[0].begin(), dat[0].end());
    sort(dat[1].begin(), dat[1].end(), greater<double>());
    for (int i = 0; i < 10; i++){
        for (double j : dat[i])
            cout << fixed << setprecision(9) << j << " ";
        cout << endl;
    }
}
