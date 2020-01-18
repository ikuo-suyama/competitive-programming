#include <bits/stdc++.h>
using namespace std;

int main()
{
  ifstream in("abc/abc087_b.txt");
  cin.rdbuf(in.rdbuf());

  // N個の変数を配列に格納
  int A, B, C, X;
  cin >> A >> B >> C >> X;

  int p = 0, x = X;
  int a = A, b = B, c = C;
  int sum = -1;
  while (x == X)
  {
    a = min(x / 500, a);
    x -= 500 * a;
    b = min(x / 100, b);
    x -= 100 * b;
    c = min(x / 50, c);
    x -= 50 * c;

    cout << x << endl;
    cout << a << "," << b << "," << c << endl;

    if (x == 0 && sum != a + b + c)
    {
      p++;
      x = X;
      sum = a + b + c;
      if (a != 0)
      {
        a--;
        b = B;
        c = C;
      }
      else if (b != 0)
      {
        b--;
        c = C;
      }
    }
  }

  cout << p;
}
