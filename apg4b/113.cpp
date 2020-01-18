#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }

  int ave = accumulate(a.begin(), a.end(), 0.0) / a.size();
  for (int i = 0; i < N; i++) {
    cout << abs(a.at(i) - ave) << endl;
  }
}