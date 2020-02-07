#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/abc091_b.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  map<string, int> m;
  rep(i, N) {
    string s;
    cin >> s;

    decltype(m)::iterator it = m.find(s);
    if (it != m.end()) {
      int cnt = it->second;
      m.erase(s);
      m.emplace(s, cnt + 1);
    } else {
      m.emplace(s, 1);
    }
  }

  int M;
  cin >> M;
  rep(i, M) {
    string s;
    cin >> s;

    decltype(m)::iterator it = m.find(s);
    if (it != m.end()) {
      int cnt = it->second;
      m.erase(s);
      m.emplace(s, cnt - 1);
    } else {
      m.emplace(s, 1);
    }
  }

  int ret = accumulate(
      m.begin(), m.end(), 0,
      [](int acc, std::pair<string, int> p) { return max(acc, p.second); });

  ret = max(0, ret);
  cout << ret << endl;
}