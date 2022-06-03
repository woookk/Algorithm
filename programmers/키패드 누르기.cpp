//
//  키패드 누르기.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/03.
//

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int Lcur = 10, Rcur = 12;
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer.push_back('L');
            Lcur = numbers[i];
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer.push_back('R');
            Rcur = numbers[i];
        }
        else {
            if(numbers[i] == 0) numbers[i] = 11;
            int diffL = abs(numbers[i] / 3 - Lcur / 3) + abs(numbers[i] % 3 - Lcur % 3);
            int diffR = abs(numbers[i] / 3 - (Rcur - 1) / 3) + abs((numbers[i] - 1) % 3 - (Rcur - 1) % 3);
            if(diffL == diffR){
                if(hand == "left"){
                    answer.push_back('L');
                    Lcur = numbers[i];
                }
                else {
                    answer.push_back('R');
                    Rcur = numbers[i];
                }
            }
            else if(diffL < diffR){
                answer.push_back('L');
                Lcur = numbers[i];
            }
            else if(diffL > diffR) {
                answer.push_back('R');
                Rcur = numbers[i];
            }
        }
    }
    return answer;
}
