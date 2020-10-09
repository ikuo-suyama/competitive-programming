#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/abc059_b.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
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
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

void solve(int a, int b) {
  if (a > b) {
    cout << "GREATER" << endl;
  } else if (b > a) {
    cout << "LESS" << endl;
  }
}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  string A, B;
  cin >> A >> B;
  
  if (A.size() != B.size()) {
    solve(A.size(), B.size());
    return 0;
  } else {
    rep(i, A.size()) {
      if (A[i] != B[i]) {
        solve(A[i], B[i]);
        return 0;
      }
    }
  }
  cout << "EQUAL" << endl;
}