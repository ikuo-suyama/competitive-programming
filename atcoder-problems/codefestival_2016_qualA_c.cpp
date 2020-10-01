#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                               \
  ifstream in("atcoder-problems/codefestival_2016_qualA_c.txt"); \
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

  string S;
  ll K;
  cin >> S >> K;
  int N = S.size();

  rep(i, N) {
    if (S[i] == 'a') continue;
    int n = 26 - (S[i] - 'a');
    if (n <= K) {
      S[i] = 'a';
      K -= n;
    }
  }
  if (K > 0) {
    K = K % 26;
    S[N - 1] += K;
  }

  cout << S << endl;
}