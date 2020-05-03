#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int diff(int a, int b)
{
  return abs(a - b);
}

int affected_dist(int *x, int a, int b, int l)
{
  if (b < l)
  {
    if (diff(x[a], x[b]) <= 2)
    {
      return affected_dist(x, b, b + 1, l);
    }
    else
    {
      return a;
    }
  }
  else
  {
    return a;
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
#endif
  int t, length;
  cin >> t;
  for (int i = 1; i <= t; i++)
  {
    cin >> length;
    int x[length];
    for (int m = 0; m < length; m++)
    {
      cin >> x[m];
    }
    int k = 0;
    int j = 0;
    int index = 0;
    int *affected = new int[length];
    while ((j + 1) < length)
    {
      index = affected_dist(x, j, j + 1, length);
      affected[k] = index - j + 1;
      j = index + 1;
      k++;
    }

    auto it_min = min_element(affected, affected + k) - affected;
    int min = affected[it_min];
    auto it_max = max_element(affected, affected + k) - affected;
    int max = affected[it_max];
    cout << min << " " << max << endl;
  }
}
