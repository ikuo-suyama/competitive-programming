#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("abc156/abc156_b.txt");
  cin.rdbuf(in.rdbuf());

  ll N;
  int K;
  cin >> N >> K;

  int cnt = 0;
  while (N > 0) {
    N /= K;
    cnt++;
  }
  cout << cnt << endl;
}