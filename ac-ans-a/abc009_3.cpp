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

  // 理想の辞書順
  string c(S);
  sort(c.begin(), c.end(), less<char>());

  string ret(S);

  rep(i, N) {
    string pre = c.substr(0, i);
    string r = c.substr(i);
    vector<char> rest(N - i);
    rep(j, N - i) { rest[j] = r[j]; }

    string test = S.substr(i);

    rep(j, N - i) {
      int len = rest.size();
      rep(k, len) {
        // 同じ文字があった
        if(test[j] == rest[k]) {
          rest.erase(rest.begin() + k);
          break;
        }
      }
      // 同じ文字がなかった
      if (len == rest.size()) {
        test[j] = rest[0];
        rest.erase(rest.begin());
      }
    }

    int k = 0;
    rep(j, i) {
      if (S[j] != pre[j]) k++;
    }
    for (int j = i; j < N; j++) {
      if (S[j] != test[j - i]) k++;
    }
    if (k <= K) {
      ret = pre + test;
    } else {
      break;
    }
  }

  cout << ret << endl;
}