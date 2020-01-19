#include <bits/stdc++.h>
using namespace std;

int main() {
  // input.txt から cin
  ifstream in("abc/abc088_b.txt");
  cin.rdbuf(in.rdbuf());

  // N個の変数を配列に格納
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  sort(a.begin(), a.end(), greater<int>());
  int A = 0, B = 0;
  for (size_t i = 0; i < N; i++) {
    if (i % 2 == 0) {
      A += a.at(i);
    } else {
      B += a.at(i);
    }
  }
  cout << A - B;
}
