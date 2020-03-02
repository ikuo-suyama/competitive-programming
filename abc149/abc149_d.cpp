#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc149/abc149_d.txt"); \
  cin.rdbuf(in.rdbuf());
#else
#define INPUT_FILE
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, K, R, S, P;
  cin >> N >> K >> R >> S >> P;
  map<char, int> points;
  points.emplace('r', R);
  points.emplace('s', S);
  points.emplace('p', P);

  string t;
  cin >> t;

  string a;
  ll ans = 0;
  rep(i, N) {
    char x = t[i];
    char y = '';
    if (x == 'r') {
      y = 'p';
    } else if (x == 's') {
      y = 'r';
    } else {
      y = 's';
    }

    if (i >= K && t[i - K]) {
      char bef = ;
      
    }
    a;
  }

  ll cnt = 0;

  cout << cnt << endl;
}