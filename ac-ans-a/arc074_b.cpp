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

  priority_queue<ll, vector<ll>, greater<ll>> a;
  priority_queue<ll> b;
  vector<ll> c(3 * N, 0);
  ll a_sum = 0, b_sum = 0;

  rep(i, 3 * N) {
    int _c;
    cin >> _c;
    c[i] = _c;
    if (i < N) {
      a.push(_c);
      a_sum += _c;
    } else if (i >= 2 * N) {
      b.push(_c);
      b_sum += _c;
    }
  }

  vector<ll> a_sum_k(N + 1, 0);
  a_sum_k[0] = a_sum;
  for (int k = 1; k <= N; k++) {
    ll _c = c[k + N - 1];
    a.push(_c);
    a_sum += _c;
    ll _a = a.top();
    a_sum -= _a;
    a.pop();
    a_sum_k[k] = a_sum;
  }

  vector<ll> b_sum_k(N + 1, 0);
  b_sum_k[N] = b_sum;
  for (int k = N - 1; k >= 0; k--) {
    ll _c = c[N + k];
    b.push(_c);
    b_sum += _c;
    ll _b = b.top();
    b_sum -= _b;
    b.pop();
    b_sum_k[k] = b_sum;
  }

  ll sum = LLONG_MIN;
  rep(k, N) { sum = max(sum, a_sum_k[k] - b_sum_k[k]); }

  cout << sum << endl;
}