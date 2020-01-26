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

  vector<P> m(N);
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    m[i] = make_pair(a, b);
  }

  sort(m.begin(), m.end(), cmp);
  rep(i, N) { cout << m[i].first / (double)m[i].second << endl; }

  ll ret = 0;
  do {
    rep(i, m.size()) {
      P p = m[i];
      int a = p.first;
      int b = p.second;
      if (a <= H) {
        H -= a;
        ret += b;
        break;
      } else if (i == m.size() - 1) {
        H -= a;
        ret += b;
      }
    }
  } while (H > 0);

  cout << ret << endl;
}