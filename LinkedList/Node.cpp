#include<bits/stdc++.h>
class node{
    
    public :
    int data;
    node(int x)
    {
        this->data=x;
        this->next=NULL;
    }
    node * next;
};