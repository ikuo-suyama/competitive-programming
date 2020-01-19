#include <bits/stdc++.h>
using namespace std;

int main() {
  // input.txt から cin
  ifstream in("abc152/c.txt");
  cin.rdbuf(in.rdbuf());

  // N個の変数を配列に格納
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  int cnt = 0;
  int min = INT_MAX;
  for (size_t i = 0; i < N; i++) {
    if (a.at(i) <= min) {
      min = a.at(i);
      cnt++;
    }
  }

  cout << cnt;
}