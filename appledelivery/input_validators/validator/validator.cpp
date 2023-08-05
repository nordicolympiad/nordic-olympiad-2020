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
    long long N = Int(1, Arg("maxn")); Endl();
    SpacedInts(N, 0, (int)Arg("maxr", int(3e5)));
    
    Eof();
}
