#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

ll within_radius(ll r) {
    ll ans = 1 + 4*r;
    for (ll x = 1; x < r; x++) {
        // maybe float imprecision?
        ll max_y = (ll)sqrtl(r*r - x*x);
        ans += 4 * max_y;
    }
    return ans;
}

ll within_radius_mod8(ll r) {
    ll t = (r + (ll)((long double)M_SQRT2 / 2 * r)) % 2;
    return 1 + t*4;
}

int main() {
    int N; cin >> N;
    vi r(N);
    ll toRemove = 0;
    rep(i, 0, N) {
        cin >> r[i];
        toRemove += within_radius_mod8(r[i]);
    }
    toRemove %= 8;
    sort(all(r));
    vi one_radii;
    vi five_radii;
    for (
        int i = 0; 
    (i < sz(r)) && (sz(one_radii) != 8 || sz(five_radii) != 8); 
    i++) {
        if (within_radius_mod8(r[i]) == 5) {
            five_radii.push_back(i);
        } else {
            one_radii.push_back(i);
        }
    }
    ll ans = LLONG_MAX;
    // We remove a number of r:s
    // 1. congruent to toRemove mod 4
    // 2. >= 0 and <= 7
    for (int toRem = toRemove % 4; toRem < 8; toRem += 4) {
        rep(numOnesRem, 0, toRem+1) {
            ll cost = 0;
            rep(i, 0, min(numOnesRem, sz(one_radii))) {
                cost += within_radius(r[one_radii[i]]);
            }
            rep(i, 0, min(toRem - numOnesRem, sz(five_radii))) {
                cost += within_radius(r[five_radii[i]]);
            }
            if (cost % 8 == toRemove) {
                ans = min(ans, cost);
            }
        }
    }
    cout << ans << endl;
    assert(within_radius(0) == 1);
    assert(within_radius(1) == 5);
    assert(within_radius(2) == 13);
    assert(within_radius(3) == 29);
    rep(i, 0, 20) {
        if (within_radius(i) % 8 != within_radius_mod8(i)) {
            cerr << "WRONG: " << i << " " << within_radius(i) << " " << within_radius_mod8(i) << endl;
        }
    }
}
