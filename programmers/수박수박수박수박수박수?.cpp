//
//  수박수박수박수박수박수?.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/25.
//

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            answer += "수";
        }
        else {
            answer += "박";
        }
    }
    return answer;
}
