#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

bool cmp(P i, P j) {
  return i.first / (double)i.second > j.first / (double)j.second;
}

int main() {
  ifstream in("abc153/e.txt");
  cin.rdbuf(in.rdbuf());

  int H, N;
  cin >> H >> N;

  vector<int> A(N);
  vector<int> B(N);
  rep(i, N) { cin >> A[i] >> B[i]; }

  vector<ll> dp(H + 1, INT_MAX);
  dp[0] = 0;

  rep(i, N) {
    int a = A[i];
    int b = B[i];

    rep(h, H) {
      int nh = min(h + a, H);
      dp[nh] = min(dp[nh], dp[h] + b);
    }
  }

  cout << dp[H] << endl;
}