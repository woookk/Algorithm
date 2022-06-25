//
//  체육복.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/26.
//

#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(31);
    for(int i = 0; i < reserve.size(); i++){
        student[reserve[i]]++;
    }
    for(int i = 0; i < lost.size(); i++){
        student[lost[i]]--;
    }
    for(int i = 1; i <= n; i++){
        if(student[i] < 0){
            if(student[i - 1] == 1) {
                student[i]++;
                student[i - 1]--;
            }
            else if(student[i + 1] == 1){
                student[i + 1]--;
                student[i]++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(student[i] != -1)
            answer++;
    }
    return answer;
}
