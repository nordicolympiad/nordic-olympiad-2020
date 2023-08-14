#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

void cycleDfs(vector<unordered_set<int>>& graph, vector<unordered_set<int>>& cycleEdges, int i, vi& successor, unordered_set<int>& ancestors, unordered_set<int>& notVisited, vector<pii>& answer, int& walkingUpTo) {
    if (notVisited.count(i) == 0) {
        return;
    }
    ancestors.insert(i);
    trav(x, graph[i]) {
        if (cycleEdges[i].count(x)) continue;
        // if parent
        if (successor[x] == i) continue;
        // if cycle
        if (ancestors.count(x)) {
            successor[i] = x;
            int par = i;
            do {
                int child = successor[par];
                answer.push_back({par, child});
                cycleEdges[par].insert(child);
                cycleEdges[child].insert(par);
                par = child;
            } while (par != i);
            walkingUpTo = x;
            ancestors.erase(i);
            // to prevent accidental quadratic
            trav(x, cycleEdges[i]) {
                graph[i].erase(x);
            }
            return;
        } else {
            successor[i] = x;
            cycleDfs(graph, cycleEdges, x, successor, ancestors, notVisited, answer, walkingUpTo);
            if (walkingUpTo == i) walkingUpTo = -1;
            if (walkingUpTo != -1) {
                ancestors.erase(i);
                return;
            }
        }
    }
    ancestors.erase(i);
    notVisited.erase(i);
}

void treeDfs(vector<unordered_set<int>>& graph, int i, bool ingoing, vi& parent, vector<pii>& answer, unordered_set<int>& unused) {
    assert(unused.count(i));
    unused.erase(i);
    //cerr << "Removing " << i << " from unused" << endl;
    trav(x, graph[i]) {
        if (x == parent[i]) continue;
        parent[x] = i;
        if (ingoing) {
            answer.push_back({i, x});
        } else {
            answer.push_back({x, i});
        }
        treeDfs(graph, x, ingoing, parent, answer, unused);
        ingoing = !ingoing;
    }
}

int main() {
    int N, M; cin >> N >> M;
    vector<unordered_set<int>> graph(N);
    rep(i, 0, M) {
        int A, B;
        cin >> A >> B; A--; B--;
        graph[A].insert(B);
        graph[B].insert(A);
    }
    int numOdd = 0;
    rep(i, 0, N) {
        numOdd += sz(graph[i]) % 2;
    }
    /*{
        // DEBUG
        cerr << "Graph: " << endl;
        rep(i, 0, N) {
            cerr << i << ": ";
            trav(x, graph[i]) {
                cerr << x << " ";
            }
            cerr << endl;
        }
        cerr << "----------" << endl;
    }*/
    vector<pii> answer; answer.reserve(M);
    // find and remove cycles
    {
        vector<unordered_set<int>> cycleEdges(N);
        vi successor(N, -1);
        unordered_set<int> notVisited;
        rep(i, 0, N) notVisited.insert(i);
        while (!notVisited.empty()) {
            //cerr << "Starting with " << *notVisited.begin() << endl;
            unordered_set<int> ancestors;
            int walkingUpTo = -1;
            cycleDfs(graph, cycleEdges, *notVisited.begin(), successor, ancestors, notVisited, answer, walkingUpTo);
        }
        rep(i, 0, N) {
            trav(x, cycleEdges[i]) {
                graph[i].erase(x);
            }
        }
    }
    /*{
        // DEBUG
        cerr << "Removed cycle edges:" << endl;
        trav(x, answer) {
            cout << x.first << " " << x.second << endl;
        }
        cerr << "--------" << endl;
        cerr << "Left of graph: " << endl;
        rep(i, 0, N) {
            cerr << i << ": ";
            trav(x, graph[i]) {
                cerr << x << " ";
            }
            cerr << endl;
        }
        cerr << "----------" << endl;
    }*/
    // traverse forest
    {
        unordered_set<int> unused;
        rep(i, 0, N) unused.insert(i);
        vi parent(N, -1);
        while (!unused.empty()) {
            //cerr << "Starting with " << *unused.begin() << endl;
            treeDfs(graph, *unused.begin(), true, parent, answer, unused);
        }
    }
    assert(sz(answer) == M);

    cout << numOdd << '\n';
    trav(x, answer) {
        cout << x.first+1 << " " << x.second+1 << '\n';
    }
    cout << flush;
}
