//
//  폰켓몬.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/26.
//

#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 1;
    sort(nums.begin(), nums.end());
    for(int i = 1; i < nums.size(); i++){
        if(nums[i - 1] == nums[i]) continue;
        answer++;
    }
    if(answer >= nums.size() / 2)
        return nums.size() / 2;
    else
        return answer;
}
