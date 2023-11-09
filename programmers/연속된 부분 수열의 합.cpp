//
//  연속된 부분 수열의 합.cpp
//  cpp
//
//  Created by 민병욱 on 2023/11/09.
//

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int st = 0, en = 0;
    int sum = sequence[0];
    int subLength = sequence.size() + 1;
    pair<int, int> ans;
    
    while (st <= en && en < sequence.size()) {
        if (sum < k) sum += sequence[++en];
        else if (sum == k) {
            if (en - st + 1 < subLength) {
                subLength = en - st + 1;
                ans = {st, en};
            }
            else if (en - st + 1 == subLength) {
                if (st < ans.first) {
                    ans = {st, en};
                }
            }
            sum -= sequence[st++];
        }
        else {
            sum -= sequence[st++];
        }
    }
    return {ans.first, ans.second};
}

/*
비내림차순으로 정렬된 수열
- 기존 수열에서 임의의 두 인덱스의 원소와 그 사이의 원소를 모두 포함하는 부분 수열
- 부분 수열의 합은 k
- 합이 k인 부분 수열이 여러 개인 경우 길이가 짧은 수열
- 길이가 짧은 수열이 여러 개인 경우 앞쪽(시작 인덱스가 작은)에 나오는 수열
조건을 만족하는 부분 수열의 시작 인덱스와 마지막 인덱스를 배열에 담아 return하는 solution 함수 완성

prefixSum 이용해서 풀이 진행하려고했으나 결국에는 i, j를 정해야하는 문제 발생
투 포인터 이용해서 풀이 진행
*/
