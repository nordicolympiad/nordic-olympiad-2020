#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens
#pragma GCC optimize ("unroll-loops")

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("movbe")                                      // byte swap
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2") // SIMD

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define enablell 1

typedef long long ll;
typedef unsigned long long ull;
#if enablell
#define int ll
#define inf int(1e18)
#else
const int inf = int(2e9);
#endif
typedef vector<ull> vull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef pair<int, int> p2;
typedef vector<p2> vp2;
typedef vector<vp2> vvp2;
typedef vector<vvp2> vvvp2;
typedef tuple<int, int, int> p3;
typedef vector<p3> vp3;
typedef vector<vp3> vvp3;
typedef vector<vvp3> vvvp3;
typedef tuple<int, int, int, int> p4;
typedef vector<p4> vp4;

inline void fast() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

template <typename T> inline void read(T& a) { cin >> a; }
template <typename T> inline void read(T& a, T& b) { cin >> a >> b; }
template <typename T> inline void read(T& a, T& b, T& c) { cin >> a >> b >> c; }


#define quit cout << endl; _Exit(0);
#define dread(type, a) type a; read(a)
#define dread2(type, a, b) dread(type, a); dread(type, b)

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (int i = high-1; i >= 0; i--)

#if 1
auto Start = chrono::high_resolution_clock::now();
void resettimer() { Start = chrono::high_resolution_clock::now(); }
int elapsedmillis() { return chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - Start).count(); }
random_device rd;
mt19937 rng(rd());
template<typename T, typename U> inline int randint(T lo, U hi) { return uniform_int_distribution<int>((int)lo, (int)hi)(rng); } // [lo,hi]
template<typename T> inline T randel(vector<T>& v) { return v[uniform_int_distribution<int>(int(0), int(v.size()) - int(1))(rng)]; } // [lo,hi]
#endif
const ll mod = 1e9 + 7;
vp2 dirs = { {0,1},{0,-1},{1,0},{-1,0} };


#define UNVIS 0
#define VISITING 1
#define VISITED 2

vvi cycles;
vp2 unused;
int dfs(int u, int p, vi& color, vector<set<int>>& edges)
{
    if (color[u] == VISITED) return -1;
    if (color[u] == VISITING)
    {
        cycles.push_back({});


        cycles.back().push_back(u);
        color[u] = UNVIS;
        return u;
    }
    color[u] = VISITING;


    while (edges[u].size())
    {
        int e = *edges[u].begin();
        edges[u].erase(edges[u].begin());
        edges[e].erase(u);

        if (e == p) continue;

        int v = dfs(e, u, color, edges);
        if (v != -1)
        {
            if (v != u)
            {
                color[u] = UNVIS;
                cycles.back().push_back(u);
                return v;
            }
        }
        else
        {
            unused.emplace_back(u, e);
        }
    }

    color[u] = VISITED;
    return -1;
}

int32_t main() {
    fast();
#if 0 && _LOCAL
    ifstream instream("C:\\users\\matis\\source\\repos\\comp_prog\\x64\\debug\\in.txt");
    cin.rdbuf(instream.rdbuf());
#endif


    int n = int(1e5); int m = int(2e5);
    vector<set<int>> edges(n);

    rep(i, m)
    {
        while (1)
        {
            int a = randint(0, n - 1);
            int b = randint(0, n - 1);
            if (a==b) continue;
            if (edges[a].find(b) != edges[a].end()) continue;
            edges[a].insert(b);
            edges[b].insert(a);
            break;
        }
    }


    vi color(n, UNVIS);
    rep(i, n)
    {
        while (dfs(i, -1, color, edges) != -1) {}
    }

    int k = 0;
    repe(c, cycles)
    {
        if (c.size()==1) continue;
        rep(i, c.size())
        {
            k++;
        }
    }
    cout << n << " " << k << "\n";
    repe(c, cycles)
    {
        if (c.size()==1) continue;
        rep(i, c.size())
        {
            cout << c[i] + 1 << " " << c[(i + 1) % c.size()] + 1 << "\n";
        }
    }
    return 0;
}
