#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;
const int INF = 100100100;
const int MOD = 1e9 + 7;

int main() {
  ifstream in("ac-ans-b/arc022_2.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  vector<int> c(N);
  rep(i, N) { cin >> c[i]; }

  int l = 0, r = 1;
  int ans = 1;
  vector<int> buf;
  buf.push_back(c[0]);
  auto i = buf.begin();

  while (l < N) {
    // 同じ数字が見つかるまで進める
    while (r < N && (i = find(buf.begin(), buf.end(), c[r])) == buf.end()) {
      buf.push_back(c[r]);
      ans = max(ans, (int)buf.size());
      r++;
    }
    if (r == N) break;
    l += distance(buf.begin(), i) + 1;
    if (i != buf.end()) {
      buf = vector<int>(i + 1, buf.end());
    }
  }

  cout << ans << endl;
}