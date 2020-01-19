#include <bits/stdc++.h>
using namespace std;

int main() {
  // input.txt から cin
  ifstream in("abc152/d.txt");
  cin.rdbuf(in.rdbuf());

  // N個の変数を配列に格納
  int N;
  cin >> N;

  int cnt = 0;
  string I, J;
  char Istart, Iend, Jstart, Jend;
  for (size_t i = 1; i <= N; i++) {
    I = to_string(i);
    Istart = I[0];
    Iend = I[I.size() - 1];

    for (size_t j = 1; j <= N; j++) {
      J = to_string(j);
      Jstart = J[0];
      Jend = J[J.size() - 1];
      if (Iend == Jstart && Istart == Jend) cnt++;
    }
  }
  cout << cnt;
}
