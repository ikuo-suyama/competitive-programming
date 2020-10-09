#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                    \
  ifstream in("abc173/abc173_e.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v)                        \
  rep(l, v.size()) { cout << v[l] << " "; } \
  cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18 + 100;
const int MOD = 1e9 + 7;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
// const int mod = 998244353;
struct mint {
  ll x;  // typedef long long ll;
  mint(ll x = 0) : x((x % mod + mod) % mod) {}
  mint operator-() const { return mint(-x); }
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const { return mint(*this) += a; }
  mint operator-(const mint a) const { return mint(*this) -= a; }
  mint operator*(const mint a) const { return mint(*this) *= a; }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return *this *= a.inv(); }
  mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, K;
  cin >> N >> K;

  vector<ll> p(0);
  vector<ll> m(0);
  vector<ll> c(0);
  rep(i, N) {
    ll d;
    cin >> d;
    if (d >= 0) {
      p.push_back(d);
    } else if (d < 0) {
      m.push_back(d);
    }
    c.push_back(d);
  }

  mint ans = 1;
  bool ok = true;
  int P = p.size();
  int M = m.size();
  if (P > 0) {
    if (N == K) {
      ok = M % 2 == 0;
    } else {
      ok = true;
    }
  } else {
    ok = K % 2 == 0;
  }

  if (!ok) {
    sort(c.begin(), c.end(), [](ll x, ll y) { return abs(x) < abs(y); });
    rep(i, K) { ans *= c[i]; }
  } else {
    sort(p.begin(), p.end());
    sort(m.rbegin(), m.rend());
    if(K % 2 == 1) {
      // 奇数のときは、予め正の数を１つとっておく
      ans *= p.back();
      p.pop_back();
    }

    // ペアを作る
    vector<ll> pair(0);
    while(p.size() >= 2) {
      ll x = p.back();
      p.pop_back();
      x *= p.back();
      p.pop_back();
      pair.push_back(x);
    }
    while(m.size() >= 2) {
      ll x = m.back();
      m.pop_back();
      x *= m.back();
      m.pop_back();
      pair.push_back(x);
    }

    sort(pair.rbegin(), pair.rend());
    rep(i, K/2) { ans *= pair[i]; }
  }

  cout << ans << endl;
}