//
//  BST.cpp
//  DS
//
//  Created by 민병욱 on 2022/04/29.
//

#include <iostream>
#include <cstdio>

using namespace std;

class Node {
public:
    int a;
    Node *left, *right;
};

class BST {
public:
    BST();
    Node *Search(int x);
    Node *SearchP(Node *N, int x);
    void Insert(int x);
    void InsertP(Node *N, int x, Node **RP);
    void Delete(int x);
    void Print();
    void PrintP(Node *N, int d, int LR);
    Node *Root;
    Node *Prt;
};

BST::BST(){
    Root = new Node;
    Root->a = 999;
    Root->left = NULL;
    Root->right = NULL;
}

Node *BST::Search(int x){
    Prt = Root;
    return SearchP(Root->left, x);
}

Node *BST::SearchP(Node *N, int x){
    if (N == NULL) return NULL;
    else {
        if (N->a < x) {
            Prt = N;
            return SearchP(N->right, x);
        }
        else if (N->a > x) {
            Prt = N;
            return SearchP(N->left, x);
        }
        else {
            printf("Found!!\n");
            return N;
        }
    }
}

void BST::Insert(int x){
    InsertP(Root->left, x, &(Root->left));
}

void BST::InsertP(Node *N, int x, Node **RP){
    Node *NN;
    if (N == NULL){
        NN = new Node;
        NN->a = x;
        NN->left = NN->right = NULL;
        *RP = NN;
    }
    else {
        if (N->a < x) InsertP(N->right, x, &(N->right));
        else if (N->a > x) InsertP(N->left, x, &(N->left));
        else return;
    }
}

void BST::Print(){
    PrintP(Root, 0, 0);
}

void BST::PrintP(Node * N, int d, int LR){
    if(LR == 1)
        for(int i = 0; i < d; i++){
            printf("        ");
        }
    printf("%8d", N->a);
    if(N->left == NULL) printf("\n");
    else PrintP(N->left, d + 1, 0);
    if(N->right == NULL) ;
    else PrintP(N->right, d + 1, 1);
}

void BST::Delete(int x){
    Node *NN, *PP, *MD, *MDP;
    NN = Search(x);
    PP = Prt;
    if (NN == NULL) return;
    if (NN->left == NULL && NN->right == NULL){
        if(PP->left == NN) PP->left = NULL;
        else PP->right = NULL;
        delete NN;
    }
    else if (NN->left != NULL && NN->right == NULL){
        if(PP->left == NN) PP->left = NN->left;
        else PP->right = NN->left;
        delete NN;
    }
    else if (NN->left == NULL && NN->right != NULL){
        if(PP->left == NN) PP->left = NN->right;
        else PP->right = NN->right;
        delete NN;
    }
    else {
        MD = NN->right;
        MDP = NN;
        while(MD->left != NULL) {
            MDP = MD;
            MD = MD->left;
        }
        NN->a = MD->a;
        
        if (MD->left == NULL && MD->right == NULL){
            if(MDP->left == MD) MDP->left = NULL;
            else MDP->right = NULL;
            delete MD;
        }
        else if (MD->left == NULL && MD->right != NULL){
            if(MDP->left == MD) MDP->left = MD->right;
            else MDP->right = MD->right;
            delete MD;
        }
    }
}

int main(){
    char c;
    int x, i;
    BST T;
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
        else if (c == 'd'){
            scanf("%d", &x);
            T.Delete(x);
        }
        else if (c == 'q'){
            break;
        }
        else {
            cout << "???\n";
        }
    }
}
