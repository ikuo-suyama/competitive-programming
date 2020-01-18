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
  int a, b, c = 0;

  for (int i = 0; i <= A; i++)
  {
    a = i * 500;
    // if (a > X) break;
    for (int j = 0; j <= B; j++)
    {
      b = j * 100;
      // if (a + b > X) break;
      for (int k = 0; k <= C; k++)
      {
        c = k * 50;
        if (a + b + c == X)
        {
          p++;
        }
      }
    }
  }

  cout << p;
}
