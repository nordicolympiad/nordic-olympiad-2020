#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;




void run() {
    int n = Int(1, Arg("maxn")); Space();
    int m = Int(1, Arg("maxm")); Endl();
    set<pii> seen;
    vi deg(n);
    rep(r,0,m)
    {
        int a = Int(1, n); Space();
        int b = Int(1, n); Endl();
        a--; b--;
        pii e = {a,b};
        assert(a!=b);
        if (e.first>e.second) swap(e.first,e.second);
        assert(seen.find(e)==seen.end());
        seen.insert(e);
        deg[a]++;
        deg[b]++;
    }

    if ((int)Arg("evendeg", 0))
    {
        rep(i,0,n) assert(deg[i]%2==0);
    }
    
    Eof();
}
