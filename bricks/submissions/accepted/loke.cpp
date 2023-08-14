#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

struct block {
    vector<vb> content;
    int w, h;
    block() {}
    block(vector<vb> ncontent) {
        w = sz(ncontent[0]);
        h = sz(ncontent);
        content = ncontent;
    }
    block turn() {
        vector<vb> newContent(w, vb(h));
        rep(i, 0, w) {
            rep(j, 0, h) {
                newContent[i][j] = content[j][w-i-1];
            }
        }
        return block(newContent);
    }
    vi count_per_column() {
        vi ans(w);
        rep(i, 0, h) {
            rep(j, 0, w) {
                ans[j] += content[i][j];
            }
        }
        return ans;
    }
};

int main() {
    vi pow3 = {1, 3, 9, 27, 81, 243};
    int N; cin >> N;
    vector<block> blocks(N);
    vi s(N);
    rep(i, 0, N) {
        int w, h; cin >> w >> h >> s[i];
        vector<vb> content(h, vb(w));
        rep(j, 0, h) {
            rep(k, 0, w) {
                char ch; cin >> ch;
                content[j][k] = (ch == '#');
            }
        }
        blocks[i] = block(content);
    }
    vector<vi> DP(N+1, vi(729, INT32_MIN));
    DP[0][0] = 0;
    rep(n, 0, N) { // last round
        rep(state, 0, 729) {
            rep(turn, 0, 4) {
                rep(pos, 0, 6) {
                    vi vstate(6);
                    rep(i, 0, 6) {
                        vstate[i] = (state / pow3[i]) % 3;
                    }
                    vi vblock = blocks[n].count_per_column();
                    if (pos + sz(vblock) > 6) continue;
                    rep(i, 0, sz(vblock)) {
                        vstate[pos + i] += vblock[i];
                    }
                    int score = 0;
                    rep(i, 0, 6) {
                        if (vstate[i] >= 3) {
                            score += s[n] * vstate[i];
                            vstate[i] = 0;
                        }
                    }
                    int nstate = 0;
                    rep(i, 0, 6) {
                        nstate += vstate[i] * pow3[i];
                    }
                    DP[n+1][nstate] = max(DP[n+1][nstate], DP[n][state] + score);
                }
                blocks[n] = blocks[n].turn();    
            }
        }
    }
    int answer = -1;
    trav(x, DP[N]) {
        answer = max(answer, x);
    }
    cout << answer << endl;
}
