#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("abc156/abc156_a.txt");
  cin.rdbuf(in.rdbuf());

  int N, R;
  cin >> N >> R;

  int r = R;
  if (N < 10) {
    r += 100 * (10 - N);
  }

  cout << r << endl;
}