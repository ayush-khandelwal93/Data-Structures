//Illustration video from:-
//https://www.youtube.com/watch?v=Q4bIYkTSu5c

#include<iostream>
using namespace std;
#define push_back pb
template<class T>
class vector
{
private:
    int size; // size of vector
    int count; // no of elements in vector
public:
    //T arr[1];
    T* arr;
    //typedef T* iterator;// now iterator word can be used as a replacement for T*
    vector()
    {
        arr = new T[1];
        size = 1;
        count = 0;
    }
    class iterator
    {
        private:
            T* pointer;
        public:
        iterator(){}
        iterator(T* temp)
        {
            pointer = temp;
        }
        T operator *()
        {
            return *(this->pointer);
        }
        T* operator ++()                  /* Prefix ++ */
        {
            return(this->pointer)++;
        }
        T* operator ++(int unused_param) /* Postfix ++*/
        {
            return(this->pointer)++;
        }
        bool operator != (iterator obj)
        {
            if(this->pointer == obj.pointer)
                return false;
            else
            {
                return true;
            }
            
        }
    };
    iterator begin()
    {
        return iterator(arr); //return arr
    }
    iterator end()
    {
        return iterator(arr+count); //return arr+count
    }
    void resize(int x)
    {
        //T ar[x];
        T* ar = new T[x]; //Dynamically allocated array //Heap memory //Frees only when program is stopped
        int i;
        for(i=0;i<count;i++)
            ar[i] = arr[i];
        arr = ar;
    }
    void push_back(T i)
    {
        if(count == size)
        {
            size*=2;
            resize(size);
        }
        arr[count++] = i;
    }
    void pop_back()
    {
        count--;
    }
    int get_count()
    {
        return count;
    }
    T operator[] (int index)
    {
        return arr[index];
    }

};
int main()
{
    vector<string> v;
    vector<string> :: iterator it,it1,it2;
    v.pb("1");
    v.pb("2");
    v.pb("3");
    v.pb("4");
    v.pb("5");
    cout<<v.get_count()<<endl;
    v.pb("1");
    v.pb("2");
    v.pb("3");
    v.pb("4");
    v.pb("5");
    cout<<v.get_count()<<endl;
    cout<<v[5]<<endl;
    it1=v.begin();
    it2=v.end();
    cout<<*it1<<endl;
    //cout<<*(--it2)<<endl;
    for(it=v.begin();it!=v.end();it++)
        cout<<*it;
    cout<<endl;
    v.pb("ayush");
    v.pb("mumbai");
    v.pb("chennai");
    for(it=v.begin();it!=v.end();it++)
        cout<<*it;
    v.pop_back();
    cout<<endl;
    for(it=v.begin();it!=v.end();it++)
        cout<<*it;
}