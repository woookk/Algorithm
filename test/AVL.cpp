//
//  AVL.cpp
//  DS
//
//  Created by 민병욱 on 2022/05/27.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

class Node {
public:
    int a;
    int LLen, RLen;
    Node *left, *right;
};

class AVL {
public:
    AVL();
    Node *Search(int x);
    Node *SearchP(Node *N, int x);
    void Insert(int x);
    int InsertP(Node *N, int x, Node **RP);
    void Print();
    void PrintP(Node *N, int d, int LR);
    Node *Root;
};

AVL::AVL(){
    Root = new Node;
    Root->a = 999;
    Root->LLen = 0;
    Root->RLen = 0;
    Root->left = NULL;
    Root->right = NULL;
}

Node *AVL::Search(int x){
    return SearchP(Root->left, x);
}

Node *AVL::SearchP(Node *N, int x){
    if (N == NULL) return NULL;
    else {
        if (N->a < x) {
            return SearchP(N->right, x);
        }
        else if (N->a > x) {
            return SearchP(N->left, x);
        }
        else {
            printf("Found!!\n");
            return N;
        }
    }
}

void AVL::Insert(int x){
    int Len;
    Len = InsertP(Root->left, x, &(Root->left));
    Root->LLen = Len + 1;
}

int AVL::InsertP(Node *N, int x, Node **RP){
    Node *NN, *A, *B, *C, *tmp1, *tmp2;
    int Len;
    if (N == NULL){
        NN = new Node;
        NN->a = x;
        NN->LLen = 0;
        NN->RLen = 0;
        NN->left = NN->right = NULL;
        *RP = NN;
        return 0;
    }
    else {
        if (N->a < x) {
            Len = InsertP(N->right, x, &(N->right));
            N->RLen = Len + 1;
        }
        else if (N->a > x) {
            Len = InsertP(N->left, x, &(N->left));
            N->LLen = Len + 1;
        }
        else ;
    }
    if (N->LLen > N->RLen + 1 || N->RLen > N->LLen + 1){
        if (N->a > x && N->left->a > x) { // case LL
            A = N; B = N->left;
            tmp1 = B->right; B->right = A; A->left = tmp1;
            if (A->left == NULL) A->LLen = 0;
            else A->LLen = max(A->left->LLen, A->left->RLen) + 1;
            B->LLen = max(B->left->LLen, B->left->RLen) + 1;
            B->RLen = max(B->right->LLen, B->right->RLen) + 1;
            *RP = B;
            return max(B->LLen, B->RLen);
        }
        else if (N->a > x && N->left->a < x){ // case LR
            A = N; B = N->left; C = B->right;
            tmp1 = C->left; tmp2 = C->right; C->left = B; C->right = A;
            B->right = tmp1; A->left = tmp2;
            if (B->right == NULL) B->RLen = 0;
            else B->RLen = max(B->right->LLen, B->right->RLen) + 1;
            if (A->left == NULL) A->LLen = 0;
            else A->LLen = max(A->left->LLen, A->left->RLen) + 1;
            C->LLen = max(C->left->LLen, C->left->RLen) + 1;
            C->RLen = max(C->right->LLen, C->right->RLen) + 1;
            *RP = C;
            return max(C->LLen, C->RLen);
        }
        else if (N->a < x && N->right->a < x) { // case RR
            A = N; B = N->right;
            tmp1 = B->left; B->left = A; A->right = tmp1;
            if (A->right == NULL) A->RLen = 0;
            else A->RLen = max(A->right->LLen, A->right->RLen) + 1;
            B->LLen = max(B->left->LLen, B->left->RLen) + 1;
            B->RLen = max(B->right->LLen, B->right->RLen) + 1;
            *RP = B;
            return max(B->LLen, B->RLen);
        }
        else if (N->a < x && N->right->a > x){ // case RL
            A = N; B = N->right; C = B->left;
            tmp1 = C->left; tmp2 = C->right; C->left = A; C->right = B;
            A->right = tmp1; B->left = tmp2;
            if (A->right == NULL) A->RLen = 0;
            else A->RLen = max(A->right->LLen, A->right->RLen) + 1;
            if (B->left == NULL) B->LLen = 0;
            else B->LLen = max(B->left->LLen, B->left->RLen) + 1;
            C->LLen = max(C->left->LLen, C->left->RLen) + 1;
            C->RLen = max(C->right->LLen, C->right->RLen) + 1;
            *RP = C;
            return max(C->LLen, C->RLen);
        }


    }
    return max(N->LLen, N->RLen);
}

void AVL::Print(){
    PrintP(Root, 0, 0);
}

void AVL::PrintP(Node * N, int d, int LR){
    if(LR == 1)
        for(int i = 0; i < d; i++){
            printf("              ");
        }
    printf(" [%2d|%4d|%2d] ", N->LLen, N->a, N->RLen);
    if(N->left == NULL) printf("\n");
    else PrintP(N->left, d + 1, 0);
    if(N->right == NULL) ;
    else PrintP(N->right, d + 1, 1);
}

int main(){
    char c;
    int x, i;
    AVL T;
    Node *RR;
    while (true) {
        T.Print();
        scanf(" %c", &c);
        if (c == 's'){
            scanf("%d", &x);
            if ((RR = T.Search(x)) == NULL)
                printf("%d Not Found.\n", x);
            else
                printf("%d Found at Address %d\n", x, RR);
        }
        else if (c == 'i'){
            scanf("%d", &x);
            T.Insert(x);
        }
        else if (c == 'q'){
            break;
        }
        else {
            cout << "???\n";
        }
    }
}

