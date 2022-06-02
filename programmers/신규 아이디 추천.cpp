//
//  신규 아이디 추천.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/02.
//

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i = 0; i < new_id.length(); i++){
        if(new_id[i] >= 'A' && new_id[i] <= 'Z') new_id[i] -= ('A' - 'a');
        // tolower() 사용 가능.
    }
    
    for(auto c : new_id){
        if(c >= 'a' && c <= 'z') answer += c;
        // push_back 사용 가능.
        else if (c >= '0' && c <= '9') answer += c;
        else if (c == '-' || c == '_') answer += c;
        else if (c == '.') answer += c;
    }
    int idx = 1;
    while(idx < answer.length()){
        if(answer[idx - 1] == '.' && answer[idx] == '.'){
            answer.erase(answer.begin() + idx);
            continue;
        }
        else idx++;
    }
    if(answer[0] == '.')
        answer.erase(answer.begin());
    if(answer[answer.length() - 1] == '.')
        answer.erase(answer.end() - 1);
    if(answer == ""){
        answer += 'a';
    }
    if(answer.length() >= 16){
        answer.erase(answer.begin() + 15, answer.end());
        if(answer[answer.length() - 1] == '.')
        answer.erase(answer.end() - 1);
    }
    
    while(answer.length() <= 2){
        answer += answer[answer.length() - 1];
    }
    
    return answer;
}
