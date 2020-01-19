#include <bits/stdc++.h>
using namespace std;

int main() {
  // input.txt から cin
  ifstream in("abc152/b.txt");
  cin.rdbuf(in.rdbuf());

  int a, b;
  cin >> a >> b;

  int I, N = 0;
  if (a < b) {
    I = a;
    N = b;
  } else {
    I = b;
    N = a;
  }
  for (size_t i = 0; i < N; i++) {
    cout << I;
  }
}
