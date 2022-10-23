//
//  EquivalenceList.cpp
//  DS
//
//  Created by 민병욱 on 2022/04/23.
//

#include <iostream>
#include <vector>
using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

int n, m;

class Node {
public:
    int a;
    Node *n;
};

class List {
public:
    List();
    void Insert(int x);
    int Search(int x, Node **p, Node **l);
    int NextForward();
    int Delete(int x, Node **d);
    Node *head;
    Node *LastForward;
};

List::List() {
    head = NULL;
    LastForward = NULL;
}

void List::Insert(int x){
    Node *c;
    c = new Node;
    c->n = head;
    c ->a = x;
    head = c;
}

int List::Search(int x, Node **p, Node **l){
    *p = NULL; *l = head;
    while (*l != NULL){
        if ((*l)->a == x) return 1;
        else if((*l)->a) return 0;
        else {
            *p = *l;
            *l = (*l)->n;
        }
    }
    return 0;
}

int List::Delete(int x, Node **d){
    Node *P, *L;
    if ( Search(x, &P, &L) == 1) {
        *d = L;
        if(P == NULL) head = L->n;
        else P->n = L->n;
        delete d;
        return 1;
    }
    return 0;
}

int List::NextForward(){
    if(head == NULL)
        return -1;
    if (LastForward == NULL)
        LastForward = head;
    else
        LastForward = LastForward->n;
    if (LastForward == NULL)
        return -1;
    else
        return LastForward->a;
}

List Map[1000];

int Stack[10000];
int SP;

void Push(int x){ //Overflow 예외처리 X
    Stack[SP++] = x;
    return;
}

int Pop(){
    return Stack[--SP];
}

int IsEmpty(){
    return (SP == 0);
}

void SetLink(int x, int y){
    Map[x].Insert(y);
    return;
}

int Vis[1000];

int LastStart;

int IsMarked(int x){
    return Vis[x];
}

int NextStart(){
    LastStart++;
    while (LastStart <= n){
        if (IsMarked(LastStart) == 0)
            return LastStart;
        else
            LastStart++;
    }
    return -1;
}

void Mark(int x){
    Vis[x] = 1;
}

int main(){
    FASTIO;
    int i, x, y, cur, s;
    cin >> n >> m;
    for (i = 0; i < m; i++){
        cin >> x >> y;
        SetLink(x, y);
        SetLink(y, x);
    }
    while ((cur = NextStart()) != -1) {
        cout << cur << " ";
        Mark(cur);
        while(1) {
            if ((s = Map[cur].NextForward()) != -1){
                if(IsMarked(s) == 0){
                    cout << s << " ";
                    Mark(s);
                    Push(cur);
                    cur = s;
                }
                else {
                    ;
                }
            }
            else {
                if (IsEmpty() == 1){
                    break;
                }
                else {
                    cur = Pop();
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
