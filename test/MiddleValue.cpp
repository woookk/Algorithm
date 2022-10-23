//
//  MiddleValue.cpp
//  DS
//
//  Created by 민병욱 on 2022/05/27.
//

#include <iostream>
#include <cstdio>

using namespace std;

class PQMin {
public:
    PQMin();
    int Size();
    int Top();
    void Insert(int x);
    void Delete();
    int a[1000];
    int n; // data 개수
};

PQMin::PQMin(){
    n = 0;
}

int PQMin::Size(){
    return n;
}

int PQMin::Top(){
    return a[1];
}

void PQMin::Insert(int x){
    int i;
    n++;
    a[n] = x;
    i = n;
    while(i != 1){
        if (a[i / 2] <= a[i]) {
            break;
        }
        swap(a[i / 2], a[i]);
        i = i / 2;
    }
}

void PQMin::Delete(){
    int i, j;
    a[1] = a[n];
    n--;
    i = 1;
    while(1){
        if (i * 2 > n) { //child X
            break;
        }
        if (i * 2 == n) { //left child만 존재.
            if(a[i] <= a[i * 2])
                break;
            else {
                swap(a[i], a[i * 2]);
                i = i * 2;
            }
        }
        else { // child 2개.
            if( a[i * 2] < a[i * 2 + 1]) j = i * 2; // child 중 작은 것이 j
            else j = i * 2 + 1;
            if(a[i] <= a[j])
                break;
            else {
                swap(a[i], a[j]);
                i = j;
            }
        }
    }
}

class PQMax {
public:
    PQMax();
    int Size();
    int Top();
    void Insert(int x);
    void Delete();
    int a[1000];
    int n; // data 개수
};

PQMax::PQMax(){
    n = 0;
}

int PQMax::Size(){
    return n;
}

int PQMax::Top(){
    return a[1];
}

void PQMax::Insert(int x){
    int i;
    n++;
    a[n] = x;
    i = n;
    while(i != 1){
        if (a[i / 2] >= a[i]) { // 큰 게 위로.
            break;
        }
        swap(a[i / 2], a[i]);
        i = i / 2;
    }
}

void PQMax::Delete(){
    int i, j;
    a[1] = a[n];
    n--;
    i = 1;
    while(1){
        if (i * 2 > n) { //child X
            break;
        }
        if (i * 2 == n) { //left child만 존재.
            if(a[i] >= a[i * 2])
                break;
            else {
                swap(a[i], a[i * 2]);
                i = i * 2;
            }
        }
        else { // child 2개.
            if( a[i * 2] > a[i * 2 + 1]) j = i * 2; // child 중 큰 것이 j
            else j = i * 2 + 1;
            if(a[i] >= a[j])
                break;
            else {
                swap(a[i], a[j]);
                i = j;
            }
        }
    }
}

int main(){
    char c;
    int x, y, lcnt, rcnt;
    PQMax Left;
    PQMin Right;
    lcnt = rcnt = 0; // 홀수면, lcnt가 하나 더 많게.
    while (true) {
        scanf(" %c", &c);
        if (c == 'p') { // Middle Value print
            if (Left.Size() == 0)
                printf("No entry.\n");
            else
                printf("Middle member = %d\n", Left.Top());
        }
        else if (c == 'i'){ // insert
            scanf("%d", &x);
            if (lcnt == 0){
                Left.Insert(x);
                lcnt = 1;
            }
            else if (lcnt == rcnt){
                if (x <= Right.Top()) {
                    Left.Insert(x);
                }
                else {
                    y = Right.Top();
                    Right.Delete();
                    Left.Insert(y);
                    Right.Insert(x);
                }
                lcnt++;
            }
            else { // lcnt = rcnt + 1;
                if(rcnt == 0){ // rcnt == 0 일 때 예외 처리.
                    if(Left.Top() < x)
                        Right.Insert(x);
                    else {
                        y = Left.Top();
                        Right.Insert(y);
                        Left.Delete();
                        Left.Insert(x);
                    }
                }
                else if (x <= Right.Top()) {
                    y = Left.Top();
                    Left.Delete();
                    Right.Insert(y);
                    Left.Insert(x);
                }
                else {
                    Right.Insert(x);
                }
                rcnt++;
            }
        }
        else if (c == 'd'){ // Middle Value delete
            if (Left.Size() == 0)
                printf("No entry to delete.\n");
            else{
                y = Left.Top(); Left.Delete();
                if (lcnt == rcnt) {
                    x = Right.Top();
                    Right.Delete();
                    Left.Insert(x);
                    rcnt--;
                }
                else {
                    lcnt--;
                }
                printf("Middle member = %d, has been deleted\n", y);
            }
        }
        else if (c == 'q'){
            break;
        }
        else {
            cout << "???\n";
        }
    }
}
