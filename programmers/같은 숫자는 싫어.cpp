//
//  같은 숫자는 싫어.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    
    answer.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++){
        if(arr[i - 1] == arr[i]) continue;
        else {
            answer.push_back(arr[i]);
        }
    }
    return answer;
}
