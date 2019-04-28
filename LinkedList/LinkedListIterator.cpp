#include<iostream>
using namespace std;
#define push_back pb
template<class T>
class LinkedList{
private:
    class node
    {
    public:
        T val;
        node* next;
    };
    node* head;
    node* last;
public:
    class iterator{
    public:
        node* curr;
        iterator(){}
        iterator(node* temp)
        {
            curr = temp;
        }
        bool operator != (iterator s)
        {
            if(this->curr == s.curr)
                return false;
            else
            {
                return true;
            }
            
        }
        void operator ++(int t) // This can have void return type, also correct for vector implementation
        {
            curr = curr->next;
        }
        T operator *()
        {
            return curr->val;
        }
    };
    iterator begin()
    {
        return(iterator(head));
    }
    iterator end()
    {
        return(iterator(last));
    }
    LinkedList()
    {
        head = NULL;
    }
    void pb(T data)
    {
        node* temp = new node(); //dynamically allocate class object
        temp->val = data;
        temp->next = head;
        if(head==NULL)
            last=temp;
        head = temp;
    }
};
int main()
{
    LinkedList<int> ptr;
    ptr.pb(1);
    ptr.pb(2);
    ptr.pb(3);
    ptr.pb(4);
    ptr.pb(5);
    LinkedList<int> :: iterator it;
    for(it=ptr.begin();it!=NULL;it++)
    {
        cout<<*(it);
    }
    cout<<endl;
    LinkedList<string> ptr1;
    ptr1.pb("1");
    ptr1.pb("2");
    ptr1.pb("3");
    ptr1.pb("4");
    ptr1.pb("5");
    LinkedList<string> :: iterator it1;
    for(it1=ptr1.begin();it1!=NULL;it1++)
    {
        cout<<*(it1);
    }
}