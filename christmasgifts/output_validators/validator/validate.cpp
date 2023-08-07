#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, m;
    judge_in >> n >> m;

    set<pii> origedges;
    vi deg(n);
    rep(i,0,m) {
        int a, b;
        judge_in >> a >> b;
        if (a>b) swap(a,b);
        origedges.insert(pii(a,b));
        deg[a-1]++;
        deg[b-1]++;
    }
    int ans = 0;
    rep(i,0,n) ans += (deg[i]%2==1);
    
    auto check = [&](istream& sol, feedback_function feedback){
        int k;
        if(!(sol >> k))
        {
            author_message("Did not output unfairness score");
            feedback("Did not output unfairness score");
        }

        if (k!=ans)
        {
            author_message("Incorrect unfairness score");
            feedback("Incorrect unfairness score");
        }

        set<pii> edges = origedges;
        vi indeg(n);
        vi outdeg(n);
        rep(i,0,m) {
            int a,b;
            if(!(sol >> a >> b))
            {
                author_message("Outputted too few edges");
                feedback("Not enough output");
            }
            for (auto x : {a,b}) if(x < 1 || x > n)
            {
                author_message("Out of bounds");
                feedback("Out of bounds edge");
            }
            
            pii p = {a,b};
            if (p.first>p.second) swap(p.first,p.second);
            if (edges.find(p)==edges.end())
            {
                author_message("Friendship output twice or never existed");
                feedback("Friendship output twice or never existed");
            }
            edges.erase(p);
            indeg[b-1]++;
            outdeg[a-1]++;
        }

        
        int res = 0;
        rep(i,0,n)
        {
            res += abs(indeg[i]-outdeg[i]);
        }

        if (res!=ans)
        {
            author_message("Construction did not achieve promised score");
            feedback("Construction did not achieve promised score");
        }

        string trailing;
        if(sol >> trailing)
        {
            author_message("Too much output");
            feedback("Trailing output");
        }
        return true;
    };

    bool judge = check(judge_ans, judge_error);
    bool author = check(author_out, wrong_answer);


    if (!judge)
    {
        wrong_answer("Judge failed to find solution");
    }

    if (!author) 
    {
        wrong_answer("Incorrect solution");
    }
    
    accept();
}
