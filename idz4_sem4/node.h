#ifndef IDZ4_SEM4_NODE_H
#define IDZ4_SEM4_NODE_H
struct node{
    node*next;
    node*prev;
    int data;
    node(node* smth,node* smth1,int smth_data): next(smth),prev(smth1),data(smth_data){}
    node():next(nullptr),prev(nullptr),data(-1){}
};
#endif //IDZ4_SEM4_NODE_H