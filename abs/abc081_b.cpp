#include <bits/stdc++.h>
using namespace std;

int divide(vector<int> &v, int cnt) {
  for (int i = 0; i < v.size(); i++) {
    if (v.at(i) % 2 == 1) {
      return cnt;
    } else {
      v.at(i) = v.at(i) / 2;
    }
  }
  return divide(v, ++cnt);
}

int main() {
  // input.txt から cin
  ifstream in("abc/abc081_b.txt");
  cin.rdbuf(in.rdbuf());

  // N個の変数を配列に格納
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  cout << divide(a, 0);
}
