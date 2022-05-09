//
//  11931 - 수 정렬하기 4.cpp
//  Cpp
//
//  Created by 민병욱 on 2022/05/09.
//

#include <iostream>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int N, num;
int arr[1000001];
int tmp[1000001];

void merge(int st, int end){
    int mid = (st + end) / 2;
    int lidx = st;
    int ridx = mid;
    for(int i = st; i < end; i++){
        if(ridx == end) tmp[i] = arr[lidx++];
        else if(lidx == mid) tmp[i] = arr[ridx++];
        else if(arr[lidx] > arr[ridx]) tmp[i] = arr[lidx++];
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
        cout << *(a + i) << "\n";
    }
}

int main(void) {
    FASTIO;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    merge_sort(0, N);
    print(arr, N);
    return 0;
}
