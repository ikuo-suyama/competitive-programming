#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

static bool endsWith(string& str, string& suffix) {
  return str.size() >= suffix.size() &&
         0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}
static bool startsWith(string& str, string& prefix) {
  return str.size() >= prefix.size() &&
         0 == str.compare(0, prefix.size(), prefix);
}

int main() {
  ifstream in("abs/abc049_c.txt");
  cin.rdbuf(in.rdbuf());

  string S;
  cin >> S;

  ll cnt = 0;
  string t[4] = {"dream", "dreamer", "erase", "eraser"};

  while (true) {
    string s = S;
    rep(i, 4) {
      if (endsWith(S, t[i])) {
        S = S.erase(S.size() - t[i].size());
        break;
      }
    }
    if (s == S) {
      cout << "NO" << endl;
      return 0;
    } else if (S.size() == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
}