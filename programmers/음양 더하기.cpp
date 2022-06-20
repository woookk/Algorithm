//
//  음양 더하기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/03.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int ans = 0;
    int len = signs.size();
    for(int i = 0; i < len; i++){
        if(signs[i]) ans += absolutes[i];
        else ans -= absolutes[i];
    }
    return ans;
}
