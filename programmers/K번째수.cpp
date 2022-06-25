//
//  K번째수.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> tmp;
    for(int i = 0; i < commands.size(); i++){
        for(int idx = commands[i][0] - 1; idx < commands[i][1]; idx++){
            tmp.push_back(array[idx]);
        }
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[i][2] - 1]);
        tmp.clear();
    }
    return answer;
}
