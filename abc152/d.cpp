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
  string A;
  int B = 0, bs = 0, bn = 0;
  char Astart, Aend, Bstart, Bend;
  for (size_t i = 1; i <= N; i++) {
    A = to_string(i);
    Astart = A[0];
    Aend = A[A.size() - 1];

    if (Astart == Aend) {
      if (Astart + '0' < N) cnt++;
    }
    // for (size_t j = 1; j <= log10(N) + 1; j++) {
    //   Bstart = Aend;
    //   Bend = Astart;
    //   bs = (Bstart - '0') * pow(10, j) + (Bend - '0');
    //   bn = ((Bstart - '0') + 1) * pow(10, j) + (Bend - '0');
    //   for (size_t k = bs; k < bn; k += 10) {
    //     if (k <= N) cnt++;
    //   }
    // }
  }
  cout << cnt;
}
