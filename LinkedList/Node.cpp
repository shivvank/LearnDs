#include<bits/stdc++.h>
#include<unordered_set>
class node
{
    public :
    int data;
    node(int x)
    {
        this->data=x;
        this->next=NULL;
    }
    node * next;
};
