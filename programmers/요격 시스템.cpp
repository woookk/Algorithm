//
//  요격 시스템.cpp
//  cpp
//
//  Created by 민병욱 on 2023/08/28.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    if (a[1] < b[1]) return true;
    return false;
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), cmp);
    int start = 0, end = 0;
    for (auto target: targets) {
        if (target[0] >= end) {
            answer++;
            end = target[1];
        }
    }
    return answer;
}

/*
A나라의 공격에 대항하여 아이기스 군사 기지에서는 무수히 쏟아지는 폭격 미사일들을 요격
백발백중을 자랑하는 요격 시스템이 잇지만 운용 비용이 상당하기 때문에 미사일을 최소로 사용해서 모든 폭격 미사일을 요격

2차원 공간으로 이루어져 있고 A나라가 발사한 폭격 미사일 x축에 평행한 직선 형태의 모양이며 개구간을 나타내는 정수 쌍 (s, e) 형태로 표현
B나라는 y축에 수평이 되도록 미사일을 발사하며, 발사된 미사일은 해당 x좌표에 걸쳐있는 모든 폭격 미사일을 관통하여 한 번에 요격

targets의 끝점을 오름차순으로 정렬한 후 시작점이 이전 미사일보다 같거나 큰 경우에는 같이 요격할 수 없다.
*/
