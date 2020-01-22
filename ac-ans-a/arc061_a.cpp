#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/arc061_a.txt");
  cin.rdbuf(in.rdbuf());

  string S;
  cin >> S;

  ll sum = 0;

  int bitsize = S.size() - 1;
  rep(i, pow(2, bitsize)) {
    ll buf = S[0] - '0';
    rep(j, bitsize) {
      if (i & (1 << j)) {
        sum += buf;
        buf = S[j + 1] - '0';
      } else {
        buf *= 10;
        buf += S[j + 1] - '0';
      }
    }
    sum += buf;
  }

  cout << sum << endl;
}