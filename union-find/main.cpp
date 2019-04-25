#include<iostream>
#include"union-find.h"
using namespace std;
int main()
{
    union_find n(5);
    n.union_(0,1);
    n.union_(2,3);
    n.union_(2,4);
    n.union_(3,4);
    cout<<n.isconnected(0,1)<<endl;
    cout<<n.isconnected(2,3)<<endl;
    cout<<n.isconnected(0,3)<<endl;
    n.union_(0,3);
    cout<<n.isconnected(0,4)<<endl;
}