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
    rep(r,0,N)
    {
        int m = Int(1, 6); Space();
        int n = Int(1, 6); Space();
        int s = Int(0, 10000); Endl();
        vector<string> lines;
        rep(i,0,n)
        {
            string s = Line();
            lines.push_back(s);
        }

        bool alldash = true;
        rep(i,0,n)
        {
            if (lines[i][0]=='#') alldash = 0;
        }
        assert(!alldash);

        alldash = 1;
        rep(i,0,n)
        {
            if (lines[i][m-1]=='#') alldash = 0;
        }
        assert(!alldash);

        alldash = 1;
        rep(i,0,m)
        {
            if (lines[0][i]=='#') alldash = 0;
        }
        assert(!alldash);

        alldash = 1;
        rep(i,0,m)
        {
            if (lines[n-1][i]=='#') alldash = 0;
        }
        assert(!alldash);
    }
    
    Eof();
}
