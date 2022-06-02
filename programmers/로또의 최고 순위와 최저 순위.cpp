//
//  로또의 최고 순위와 최저 순위.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/06/02.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2 * sizeof(int));
    answer[0] = answer[1] = 0;
    for(int i = 0; i < lottos_len; i++){
        if(lottos[i] == 0) {
            answer[0]++;
            continue;
        }
        for(int j = 0; j < win_nums_len; j++){
            if(lottos[i] == win_nums[j]) {
                answer[0]++;
                answer[1]++;
                break;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        if(answer[i] < 2){
            answer[i] = 6;
        }
        else {
            answer[i] = 7 - answer[i];
        }
    }
    return answer;
}
