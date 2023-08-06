//
//  2180 - 소방서의 고민.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/04.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

const int MX_INCLINE = 40000;

int n;
long long t;
vector<tuple<double, int, int>> fire;

int main() {
    FASTIO
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0) {
            fire.push_back({MX_INCLINE, a, b});
        }
        else {
            fire.push_back({(double)b / a, a, b});
        }
    }
    sort(fire.begin(), fire.end());
    
    for (int i = 0; i < n; i++) {
        double incline;
        int a, b;
        tie(incline, a, b) = fire[i];
        t += a * t + b;
        t %= 40000;
    }
    cout << t;
    return 0;
}

/*
 여러 건의 화재가 동시에 발생. 한 대의 소방차를 이용하여 어떤 순서로 화재를 진압하는 것이 모든 화재를 진압하는데 걸리는 시간을 최소화하는지.
 한 화재 사건에 소방차 도착이 늦으면 늦을 수록 화재를 진압하는데 걸리는 시간이 같거나 길어진다. 화재의 종류에 따라서, 화재 발생 후 소방차가 t초 후에 도착하면 화재를 진압하는데 걸리는 시간은 at + b와 같이 1차 함수의 형태로 나타나게 된다. (a, b 음수 X)
 모든 화재 사건은 시각 0에서 발생. 모든 화재를 진압하는데 걸리는 최소 시간이 얼마인지? (소방차의 이동 시간은 고려하지 않고 0으로 가정, 한 화재 진압이 완전히 끝나기 전에는 소방차가 다른 화재 현장으로 이동할 수 없다.)
 
 a = 0일 때, 시간 상관없이 화재를 진압하는데 b만큼 시간 소요 (우선 순위 가장 뒤)
 a != 0일 때,  A = a1t + b1, B = a2t + b2라고 가정하면
    A -> B
    B -> A 의 수식 비교를 통해서 두 화재간의 우선순위를 결정할 수 있다.
 b / a가 작은 것부터 화재를 진압하는 방식으로 풀이.
 */
