//
//  크레인 인형뽑기 게임.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/27.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int N = board.size();
    int idx;
    vector<int> s;
    for(int i = 0; i < moves.size(); i++){
        idx = 0;
        while(idx < N && board[idx][moves[i] - 1] == 0){
            idx++;
        }
        if(idx == N) continue;
        if(!s.empty()){
            if(s.back() == board[idx][moves[i] - 1]){
                answer += 2;
                s.pop_back();
            }
            else {
                s.push_back(board[idx][moves[i] - 1]);
            }
        }
        else {
            s.push_back(board[idx][moves[i] - 1]);
        }
        board[idx][moves[i] - 1] = 0;
    }
    return answer;
}
