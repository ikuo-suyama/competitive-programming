#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                          \
  ifstream in("atcoder-problems/test.txt"); \
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

int main() {
  INPUT_FILE CIN_OPTIMIZE;
    string word;
    cin >> word;
    cout << word << endl;

    set<char> wordChars;
    for (int i = 0; i < word.size(); i++) {
        wordChars.insert(word[i]);
    }

    vector<string> l(0);
    string tmp;
    while(cin >> tmp) {
        l.push_back(tmp);
    }
    
    int ans = 0;
    for (int i = 0; i < l.size(); i++) {
        string w = l[i];
        cout << w << endl;
        set<char> chars;
        for (int j = 0; j < w.size(); j++) {
            chars.insert(w[j]);
        }
        if (wordChars == chars) ans++;
        // if (isSimilar(wordChars, target)) ans++;
    }

    cout << ans << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}