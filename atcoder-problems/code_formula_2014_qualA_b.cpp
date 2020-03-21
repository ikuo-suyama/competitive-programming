#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                                               \
  ifstream in("atcoder-problems/code_formula_2014_qualA_b.txt"); \
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

  int a, b;
  cin >> a >> b;

  vector<char> d(10, 'x');
  rep(i, a) {
    int p;
    cin >> p;
    d[p] = '.';
  }
  rep(i, b) {
    int q;
    cin >> q;
    d[q] = 'o';
  }

  printf("%c %c %c %c\n", d[7], d[8], d[9], d[0]);
  printf(" %c %c %c \n", d[4], d[5], d[6]);
  printf("  %c %c  \n", d[2], d[3]);
  printf("   %c   \n", d[1]);
}