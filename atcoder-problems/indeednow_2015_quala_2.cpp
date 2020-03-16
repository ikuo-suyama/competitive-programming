#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                   \
  ifstream in("atcoder-problems/indeednow_2015_quala_2.txt"); \
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
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  vector<string> s(N);
  rep(i, N) { cin >> s[i]; }

  map<char, int> im;
  string indeed = "indeednow";
  rep(i, indeed.size()) {
    char key = indeed[i];
    im[key] += 1;
  }

  rep(i, N) {
    map<char, int> tmp;
    rep(j, s[i].size()) { tmp[s[i][j]] += 1; }
    if (im == tmp) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}