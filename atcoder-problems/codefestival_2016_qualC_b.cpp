#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                               \
  ifstream in("atcoder-problems/codefestival_2016_qualC_b.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int K, T;
  cin >> K >> T;

  priority_queue<P, vector<P>, greater<P>> que;
  rep(i, T) {
    int a;
    cin >> a;
    que.push(make_pair(a, i));
  }

  int ans = 0;
  int last = -1;
  while ((que.size() >= 2)) {
    P top = que.top();
    que.pop();
    P next = que.top();
    que.pop();

    last = last == top.second ? next.second : top.second;
    if (top.first > 1) que.push(make_pair(top.first - 1, top.second));
    if (next.first > 1) que.push(make_pair(next.first - 1, next.second));
  }
  if (!que.empty()) {
    P top = que.top();
    ans = last == top.second ? top.first : top.first - 1;
  }

  cout << ans << endl;
}