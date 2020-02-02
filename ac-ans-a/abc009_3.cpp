#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int N, K;
string S;
bool check(string t) {
  int k = 0;
  rep(i, N) {
    if (t[i] != S[i]) k++;
  }
  return k <= K;
}

int main() {
  ifstream in("ac-ans-a/abc009_3.txt");
  cin.rdbuf(in.rdbuf());

  cin >> N >> K >> S;

  string ret = S;
  rep(i, N) {
    int cur = i;
    for (int j = i + 1; j < N; j++) {
      if(ret[j] < ret[cur]) {
        string test = ret;
        swap(test[i], test[j]);
        if (check(test)) cur = j;
      }
    }
    swap(ret[i], ret[cur]);
  }

  cout << ret << endl;
}