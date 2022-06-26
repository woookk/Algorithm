//
//  모의고사.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/26.
//

#include <string>
#include <vector>

using namespace std;

int stu[3][10] = {
    {1, 2, 3, 4, 5, 1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5, 2, 1},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
};

int num[3] = {5, 8, 10};
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score(3);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < answers.size(); j++){
            if(answers[j] == stu[i][j % num[i]]) score[i]++;
        }
    }
    int MX = score[0];
    answer.push_back(1);
    for(int i = 1; i < 3; i++){
        if(MX < score[i]){
            answer.clear();
            answer.push_back(i + 1);
            MX = score[i];
        }
        else if(MX == score[i]){
            answer.push_back(i + 1);
        }
    }
    return answer;
}
