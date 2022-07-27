//
//  Merge_sort_test.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/04.
//

#include <iostream>
#include <cstdlib>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define SIZE 25

int arr[1000001];
int tmp[1000001];

void merge(int st, int end){
    int mid = (st + end) / 2;
    int lidx = st;
    int ridx = mid;
    for(int i = st; i < end; i++){
        if(ridx == end) tmp[i] = arr[lidx++];
        else if(lidx == mid) tmp[i] = arr[ridx++];
        else if(arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else tmp[i] = arr[ridx++];
    }
    for(int i = st; i < end; i++) arr[i] = tmp[i];
}

void merge_sort(int st, int end){
    if(end == st + 1) return;
    int mid = (st + end) / 2;
    merge_sort(st, mid);
    merge_sort(mid, end);
    merge(st, end);
}

void print(int *a, int N){
    for(int i = 0; i < N; i++){
        cout << *(a + i) << " ";
    }
    cout << "\n";
}

int main(){
    FASTIO;
    srand((unsigned int)time(NULL));
    for(int i = 0; i < SIZE; i++){
        *(arr + i) = rand() % 100 + 1;
    }
    
    print(arr, SIZE);
    merge_sort(0, SIZE);
    print(arr, SIZE);
}
