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
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N, K;
  cin >> N >> K;

  vector<ll> p(0);
  vector<ll> m(0);
  int zeroCnt = 0;
  rep(i, N) {
    ll d;
    cin >> d;
    if (d > 0) {
      p.push_back(d);
    } else if (d < 0) {
      m.push_back(-1 * d);
    } else {
      zeroCnt++;
    }
  }

  mint ans = 1;
  if (p.size() == 0 && K % 2 == 1) {
    // マイナスにしかできない
    if (zeroCnt > 0) {
      ans = 0;
    } else {
      sort(m.begin(), m.end());
      rep(i, K) {
        ans *= -m[i];
      }
    }
  } else if (p.size() + m.size() < K) {
    // かならず０を含む
    ans = 0;
  } else if (p.size() >= K) {
      rep(i, K) {
        ans *= p[i];
      }
  } else {
    bool minus = false;
    // プラスにできる
    int pi = 0;
    int mi = 0;
    rep(i, K) {
      if (p[pi] > m[mi]) {
        pi++;
      } else {
        mi++;
      }
    }
    if (mi % 2 == 1) {
      // マイナスになるのでプラスに戻す
      if (p.size() == pi && m.size() == mi) {
        // 数が足りない
        if (zeroCnt > 0) {
          cout << 0 << endl;
          return 0;
        }
        // そのまま(N = Kのケース, マイナス)
        minus = true;
      }
      if (mi + 1 < m.size() && m[mi + 1] > p[pi]) {
        mi++;
        pi--;
      } else {
        pi++;
        mi--;
      }
    }
    rep(i, pi) {
      ans *= p[i];
    }
    rep(i, mi) {
      ans *= m[i];
    }
    if (minus) ans *= -1;
  }

  cout << ans << endl;
}