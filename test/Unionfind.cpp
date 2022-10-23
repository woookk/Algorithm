//
//  Unionfind.cpp
//  DS
//
//  Created by 민병욱 on 2022/06/06.
//

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int n;

int A[1000];

int Find(int a){
    int r, p, q;
    p = a;
    while(A[p] != 0){
        p = A[p];
    }
    r = p; p = a;
    while(A[p] != 0){
        q = p;
        p = A[p];
        A[q] = r;
    }
    return p;
}

void Union(int a, int b){
    int p, q;
    p = Find(a); q = Find(b);
    if(p != q)
        A[q] = p;
    return;
}

void Print(){
    for(int i = 1; i <= n; i++){
        cout << setw(4) << A[i];
    }
    cout << "\n";
    return;
}

int main(){
    
    char cmd;
    int a, b;
    cout << "Size? ";
    cin >> n;
    
    while(true){
        Print();
        cin >> cmd;
        if (cmd == 'u') {
            cin >> a >> b;
            Union(a, b);
        }
        else if (cmd == 'f') {
            cin >> a;
            cout << a << " belongs to group " << Find(a) << "\n";
        }
        else if (cmd == 'q') {
            
        }
        else {
            cout << "???\n";
        }
    }
    return 0;
}
