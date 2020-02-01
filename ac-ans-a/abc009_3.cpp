#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

bool cmp(pair<int, char> i, pair<int, char> j) { return i.second < j.second; }

int main() {
  ifstream in("ac-ans-a/abc009_3.txt");
  cin.rdbuf(in.rdbuf());

  int N, K;
  string S;
  cin >> N >> K >> S;

  string ret(S);

  rep(i, N) {
    string t = ret.substr(i);

    // i以上で最小の文字を見つける
    vector<pair<int, char>> c(N - i);
    rep(j, N - i) { c[j] = make_pair(j, t[j]); }
    sort(c.begin(), c.end(), cmp);

    string test(ret);
    // swap
    char tmp = test[i];
    test[i] = c[0].second;
    test[c[0].first + i] = tmp;

    int k = 0;
    rep(j, N) {
      if (S[j] != test[j]) k++;
    }
    if (k <= K) {
      ret = test;
    }
  }

  cout << ret << endl;
}