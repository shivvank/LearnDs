#include "CircularLinkedList.cpp"
using namespace std;
int main()
{
    node * head=NULL;
    char ch='y';
    int x;
    while(ch=='y')
    {
        cout<<"Enter the value : ";
        cin>>x;
        head=InsertLastCircular(head,x);
        cout<<"Want to enter more elements? (y/n)"<<endl;
        cin>>ch;
    }
    DisplayCircular(head);
    node *second =SplitInTwo(head);
    cout<<"First : "<<endl;
    DisplayCircular(head);
    cout<<"Second : "<<endl;
    DisplayCircular(second);
    return 0;
}