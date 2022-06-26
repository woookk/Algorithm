//
//  완주하지 못한 선수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/26.
//

#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i = 0; i < completion.size(); i++){
        if(participant[i] != completion[i]){
            return participant[i];
        }
    }
    return participant.back();
}
