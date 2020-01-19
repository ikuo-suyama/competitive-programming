#include <bits/stdc++.h>
using namespace std;

int main() {
  // input.txt から cin
  ifstream in("abc/abc083_b.txt");
  cin.rdbuf(in.rdbuf());

  // N個の変数を配列に格納
  int N, A, B;
  cin >> N >> A >> B;

  string s;
  int c = 0;
  int ret = 0;
  for (int i = A; i <= N; i++) {
    s = to_string(i);
    for (int j = 0; j < s.size(); j++) {
      c += (int)(s[j] - '0');
    }
    if (A <= c && c <= B) {
      ret += i;
    };
    c = 0;
  }
  cout << ret;
}