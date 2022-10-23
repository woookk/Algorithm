//
//  Array (Unpacked, Sorted).cpp
//  DS
//
//  Created by 민병욱 on 2022/04/01.
//

#include <iostream>
#include <cstdio>
using namespace std;

int A[100], B[100];
int S, lef, rig;

int srch(int x){
    int  s, e, m;
    s = 0; e = S - 1;
    while(s <= e) {
        m = (s + e) / 2;
        if (A[m] == x){
            lef = rig = m;
            if (B[m] == 1) // 찾았을 때 B[m] == 1이면 값이 존재.
                return 1;
            else
                return -1;
        }
        else if (A[m] > x){
            e = m - 1;
        }
        else { //A[m] < x
            s = m + 1;
        }
    }
    lef = e; rig = s;
    return -1;
}

void insrt(int x){
    int i, j;
    if (lef == rig) {
        B[lef] = 1;
    }
    else if (lef == -1){
        i = rig;
        while (B[i] == 1 && i < S)
            i++;
        if(i == S) { // 오른쪽 끝까지 갔다. 오른쪽에 빈 자리가 없다.
            for (j = S - 1; j >= rig; j--){
                A[j + 1] = A[j]; B[j + 1] = B[j];
            }
            A[rig] = x; B[rig] = 1;
            S++;
        }
        else { // 오른쪽에 빈자리 존재.
            for (j = i - 1; j >= rig; j--){
                A[j + 1] = A[j]; B[j + 1] = B[j];
            }
            A[rig] = x; B[rig] = 1;
        }
    }
    else if (rig == S) {
        i = lef;
        while (B[i] == 1 && i >= 0)
            i--;
        if(i == -1){
            A[S] = x; B[S] = 1;
            S++;
        }
        else {
            for (j = i; j < rig; j++){
                A[j] = A[j + 1]; B[j] = B[j + 1];
            }
            A[rig - 1] = x; B[rig - 1] = 1;
        }
    }
    else {
        i = lef;
        while (B[i] == 1 && i >= 0)
            i--;
        if (i != -1){ // 왼쪽에 자리 존재.
            for (j = i; j < lef; j++){
                A[j] = A[j + 1]; B[j] = B[j + 1];
            }
            A[lef] = x; B[lef] = 1;
        }
        else {
            i = rig;
            while (B[i] == 1 && i < S)
                i++;
            if(i == S) {
                for (j = S - 1; j >= rig; j--){
                    A[j + 1] = A[j]; B[j + 1] = B[j];
                }
                A[rig] = x; B[rig] = 1;
                S++;
            }
            else {
                for (j = i - 1; j >= rig; j--){
                    A[j + 1] = A[j]; B[j + 1] = B[j];
                }
                A[rig] = x; B[rig] = 1;
            }
        }
    }
}

void del(int x){
    B[lef] = 0;
}

int main(){
    char c;
    int x, i;
    S = 0;
    while (true) {
        printf("S = %d\n", S);
        for(i = 0; i < S; i++){
            printf("%3d    ", i);
        }
        printf("\n");
        for(i = 0; i < S; i++){
            printf("%3d    ", A[i]);
        }
        printf("\n");
        for(i = 0; i < S; i++){
            printf("%3d    ", B[i]);
        }
        printf("\n");
        scanf(" %c", &c);
        if (c == 's'){
            scanf("%d", &x);
            if (srch(x) == -1 && lef != rig) // lef, rig 사이에 있어야 한다.
                printf("%d Not Found. Should be between %d and %d\n", x, lef, rig);
            else if (srch(x) == -1 && lef == rig) // 지워진 값으로 있다.
                printf("%d Not Found. Stored as deleted value at %d\n", x, lef);
            else
                printf("%d Found at Index %d\n", x, lef);
        }
        else if (c == 'i'){
            scanf("%d", &x);
            if (srch(x) == -1){
                insrt(x);
            }
        }
        else if (c == 'd'){
            scanf("%d", &x);
            if (srch(x) == 1){
                del(x);
            }
        }
        else if (c == 'q'){
            break;
        }
        else {
            cout << "???\n";
        }
    }
    return 0;
}
