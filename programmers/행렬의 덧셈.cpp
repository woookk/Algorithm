//
//  행렬의 덧셈.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/20.
//

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i = 0; i < arr1.size(); i++){
        vector<int> temp;
        for(int j = 0; j < arr1[0].size(); j++){
            temp.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(temp);
    }
    return answer;
}
