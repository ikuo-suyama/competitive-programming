#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                              \
  ifstream in("atcoder-problems/agc034_a.txt"); \
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

  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  A--;
  B--;
  C--;
  D--;

  string S;
  cin >> S;

  repi(i, A, N - 1) {
    if (S[i] == '#' && S[i + 1] == '#') {
      cout << "No";
      return 0;
    }
  }

  if (C > D) {
    repi(i, A, C - 2) {
      if (S[i] == '.' && S[i + 1] == '.' && S[i + 2] == '.') {
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}