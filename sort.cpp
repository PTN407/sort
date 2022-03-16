
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
    return ll(rng() * rng()) * rng() / pow(10, rng() % 18);
}
int random_int(int l, int r){
    return rng() % (r - l + 1) + l;
}

// quicksort source: https://en.cppreference.com/w/cpp/algorithm/partition
template <class ForwardIt>
    void quicksort(ForwardIt first, ForwardIt last){
        if(first == last) return;
        if (next(first) == last) return;
        auto pivot = *next(first, distance(first,last)/2);
        ForwardIt middle1 = partition(first, last,
                            [pivot](const auto& em){ return em < pivot; });
        ForwardIt middle2 = partition(middle1, last,
                            [pivot](const auto& em){ return !(pivot < em); });
        quicksort(first, middle1);
        quicksort(middle2, last);
    }
template<class ForwardIt>
    void mergesort(ForwardIt first, ForwardIt last){
        if (first == last) return;
        if (next(first) == last) return;
        auto pivot = next(first, distance(first,last)/2);
        mergesort(first, pivot);
        mergesort(pivot, last);
        vector<double> v(distance(first, last));
        merge(first, pivot, pivot, last, v.begin());
        copy(v.begin(), v.end(), first);
    }
template<class ForwardIt>
    void heapsort(ForwardIt first, ForwardIt last){
        make_heap(first, last);
        sort_heap(first, last);
    }
int compare(const void * a, const void * b){
    if (*(double*)a > *(double*)b) return 1;
    if (*(double*)a == *(double*)b) return 0;
    if (*(double*)a < *(double*)b) return -1;
    return 0;
}
vector<double> dat[10];
ll time_stamp[20][10];
int main(){
    fio;
    freopen("test.txt", "r", stdin);
    for (int i = 0; i < 10; i++){
        dat[i].resize(SIZE);
        for (int j = 0; j < SIZE; j++)
            cin >> dat[i][j];
    }
    std::chrono::steady_clock::time_point begin, end;
    vector<double> temp;
    for (int i = 0; i < 10; i++){
        // quicksort
        temp.resize(SIZE);
        copy(dat[i].begin(), dat[i].end(), temp.begin());
        begin = std::chrono::steady_clock::now();
        quicksort(temp.begin(), temp.end());
        end = std::chrono::steady_clock::now();
        if (!is_sorted(temp.begin(), temp.end()))
            cout << "quicksort failed to sort in testcase #" << i << endl;
        time_stamp[i][0] = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

        // heapsort
        temp.resize(SIZE);
        copy(dat[i].begin(), dat[i].end(), temp.begin());
        begin = std::chrono::steady_clock::now();
        heapsort(temp.begin(), temp.end());
        end = std::chrono::steady_clock::now();
        if (!is_sorted(temp.begin(), temp.end()))
            cout << "heapsort failed to sort in testcase #" << i << endl;
        time_stamp[i][1] = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

        // mergesort
        temp.resize(SIZE);
        copy(dat[i].begin(), dat[i].end(), temp.begin());
        begin = std::chrono::steady_clock::now();
        mergesort(temp.begin(), temp.end());
        end = std::chrono::steady_clock::now();
        if (!is_sorted(temp.begin(), temp.end())){
            cout << "mergesort failed to sort in testcase #" << i << endl;
            for (auto i : temp)
                cout << i << " ";
            cout << endl;
        }
        time_stamp[i][2] = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

        // c++ sort
        temp.resize(SIZE);
        copy(dat[i].begin(), dat[i].end(), temp.begin());
        begin = std::chrono::steady_clock::now();
        sort(temp.begin(), temp.end());
        end = std::chrono::steady_clock::now();
        if (!is_sorted(temp.begin(), temp.end()))
            cout << "c++ sort failed to sort in testcase #" << i << endl;
        time_stamp[i][3] = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    }
    string sort_label[4] = {"quicksort", "heapsort", "mergesort", "sort"};
    for (int i = -1; i < 10; i++){
        if (i == -1)
            for (int j = 0; j < 4; j++)
                cout << sort_label[j] << " \n"[j == 3];
        else
            for (int j = 0; j < 4; j++)
                cout << time_stamp[i][j] << "\t\n"[j == 3];
    }
}
