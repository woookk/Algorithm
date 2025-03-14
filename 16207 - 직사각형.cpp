//
//  16207 - 직사각형.cpp
//  cpp
//
//  Created by 병욱 민 on 3/14/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int N;
ll ans;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    FASTIO;
    cin >> N;
    vector<int> candidate(N + 1, 0);
    
    for (int i = 0; i < N; i++) {
        cin >> candidate[i];
    }
    sort(candidate.begin(), candidate.end(), cmp);
    
    vector<ll> selected;
    int idx = 1;
    while (idx < N) {
        if (candidate[idx - 1] - candidate[idx] <= 1) {
            selected.push_back(candidate[idx]);
            idx += 2;
            continue;
        }
        idx++;
    }
    
    for (int i = 0; i < selected.size() / 2; i++) {
        ans += (selected[2 * i] * selected[2 * i + 1]);
    }
    cout << ans;
    return 0;
}

/*
 막대 N개가 있다. 막대의 길이는 A1, A2, ... AN이며, 모두 2보다 크거나 같은 자연수이다.
 이 막대를 이용해서 직사각형을 만들려고 한다. 각 막대는 최대 한 번 사용할 수 있고, 여러 개의 막대를 이용해서 직사각형의 한 변을 만드는 것을 불가능하다.
 일부 막대는 직사각형을 만들 때 사용하지 않아도 된다. 직사각형은 하나 이상을 만들어도 된다.
 
 막대의 길이를 1만큼만 줄일 수 있는 기계를 하나 만들었다. 기계를 사용하는 횟수에는 제한이 없지만, 길이를 줄인 막대를 또 줄일 수는 없다.
 직사각형의 넓이의 합이 최대가 되게 직사각형을 만들려고 한다. 이 때, 그 넓이를 구하자.
 
 위에서부터 큰 거 2개씩 만들어주는 방식으로 풀이
 */
