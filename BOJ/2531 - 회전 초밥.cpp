//
//  2531 - 회전 초밥.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/07/18.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, d, k, c;
int dishes[30001 * 2];
int ateCount[3001];
int ateKindCount;
int ans;

void eat(int sushi) {
  if (ateCount[sushi] == 0) {
    ateKindCount++;
    ans = max(ans, ateKindCount);
  }
  ateCount[sushi]++;
}

void overeat(int sushi) {
  ateCount[sushi]--;
  if (ateCount[sushi] == 0) ateKindCount--;
}

int main() {
  FASTIO
  cin >> N >> d >> k >> c;
  ateCount[c]++;
  ateKindCount = 1;
  ans = 1;

  for (int i = 0; i < N; ++i) {
    cin >> dishes[i];
    dishes[N + i] = dishes[i];
  }

  for (int i = 0; i < N * 2; ++i) {
    if (i >= k) overeat(dishes[i - k]);
    eat(dishes[i]);
  }
  cout << ans;

  return 0;
}
