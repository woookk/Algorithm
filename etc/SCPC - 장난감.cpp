//
//  SCPC - 장난감.cpp
//  cpp
//
//  Created by 민병욱 on 2023/07/28.
//

#include <iostream>
#include <set>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int Answer;

int main(int argc, char** argv) {
    FASTIO
    setbuf(stdout, NULL);
    int T, test_case;
    /*
       The freopen function below opens input.txt file in read only mode, and afterward,
       the program will read from input.txt file instead of standard(keyboard) input.
       To test your program, you may save input data in input.txt file,
       and use freopen function to read from the file when using cin function.
       You may remove the comment symbols(//) in the below statement and use it.
       Use #include<cstdio> or #include <stdio.h> to use the function in your program.
       But before submission, you must remove the freopen function or rewrite comment symbols(//).
     */

    // freopen("input.txt", "r", stdin);

    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////
        /*
           Implement your algorithm here.
           The answer to the case will be stored in variable Answer.
         */
        int N;
        cin >> N;
        int A[500005];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        string str = "";
        for (int i = 0; i < N; i++) {
            str += ('0' + A[i]);
        }
        
        set<string> s;
        s.insert(str);
        for (int i = 0; i < N; i++) {
            string temp = "";
            temp += str[N - 1];
            str.insert(0, temp);
            str.erase(N);
            
            if (!s.empty() && s.find(str) != s.end()) {
                Answer = s.size();
            }
            s.insert(str);
        }
        /////////////////////////////////////////////////////////////////////////////////////////////
        
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;//Your program should return 0 on normal termination.
}

/*
 쇠구슬들이 돌아다니는 장난감은 원형으로 배치된 N개의 칸들로 구성되어 있다.
 각 칸은 원의 꼭대기에 있는 칸부터 시계 방향으로 1번부터 ~ N번까지 번호가 붙어 있다.
 
 i번 칸에 있는 쇠구슬의 개수를 Ai라고 하자. 각 칸에는 간단한 장치가 있어 쇠구슬을 하나씩 시계방향으로 인접한 칸으로 보낸다.
 매 초마다 각 i번 칸의 장치는, 해당 칸의 쇠구슬이 1개 이상 있을 경우, 그 중 1개를 i + 1번 칸으로 보낸다.
 
 */
