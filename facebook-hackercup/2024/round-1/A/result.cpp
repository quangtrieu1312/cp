#include <iostream>
using namespace std;

double solve() {
  int N;
  cin >> N;
  long long a, b;
  long long minSpeedNum = 0, minSpeedDen = 1;
  long long maxSpeedNum = 1000000, maxSpeedDen = 1;
  for (int i = 1; i <= N; i++) {
    cin >> a >> b;
    // Must go at least as fast as i/B and no faster than i/A.
    if (i * minSpeedDen > minSpeedNum * b) {
      minSpeedNum = i;
      minSpeedDen = b;
    }
    if (i * maxSpeedDen < maxSpeedNum * a) {
      maxSpeedNum = i;
      maxSpeedDen = a;
    }
  }
  if (minSpeedNum * maxSpeedDen > maxSpeedNum * minSpeedDen) {
    return -1;
  }
  return (double)minSpeedNum / minSpeedDen;
}


int main() {
  freopen("subsonic_subway_input.txt", "r", stdin);
  freopen("result_output.txt", "w", stdout);
  int T;
  cin >> T;
  cout.precision(10);
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << fixed << solve() << endl;
  }
  return 0;
}
