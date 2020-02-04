#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
typedef pair<int, int> P;
typedef long long ll;

int main() {
  ifstream in("ac-ans-a/arc074_b.txt");
  cin.rdbuf(in.rdbuf());

  int N;
  cin >> N;

  priority_queue<int, vector<int>, greater<int>> a;
  priority_queue<int> b;
  vector<int> c(N, 0);
  ll a_sum = 0, b_sum = 0;

  rep(i, 3 * N) {
    int _c;
    cin >> _c;
    c[i] = _c;
    if (i < N) {
      a.push(_c);
      a_sum += _c;
    } else {
      b.push(_c);
      b_sum += _c;
      if (i >= 2 * N) {
        int _b = b.top();
        b.pop();
        b_sum -= _b;
      }
    }
  }

  ll sum = 0;
  repi(k, N, 2 * N) {
    int _c = c[k];
    a.push(_c);
    b.push(_c);

    a_sum += _c;
    b_sum += _c;

    int _a = a.top();
    a_sum -= _a;
    a.pop();

    int _b = b.top();
    b_sum -= _b;
    b.pop();

    sum = max(sum, a_sum - b_sum);
  }

  cout << sum << endl;
}