#include<iostream>
using namespace std;
class String
{
private:
    char* str;
    int len;
public:
    String() { }
    String (const char * s)
    {
        len=0;
        for(int i=0;s[i]!='\0';i++)
            len++;


        str = new char[len];
        for(int i=0;s[i]!='\0';i++)
            str[i] = s[i];
    }
    int length()
    {
        return len;
    }
    void print()
    {
        for(int i=0;str[i]!='\0';i++)
            cout<<str[i];
    }
    void uppercase()
    {
        for(int i=0;str[i]!='\0';i++)
        {
            if(str[i]>='A' && str[i]<='Z'){continue;}
            else
            {
                str[i] = str[i]-'a'+'A';
            }
        }
    }
    friend ostream& operator <<(ostream &t, String s) // Declaring this friend is required here 
    //otherwise error
    // If not overloading through friend function, operator overloading must be defined in the 
    // class to the left of the operator , in this case cout
    // But we cant change ostream class, cout is an object of ostream class
    // Hence overloading using friend class (global method)
    // ref:- https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
    {

        for(int i=0;s.str[i]!='\0';i++)
        {
            t<<s.str[i];
        }
        return t;
    }  
    friend istream& operator >>(istream &t, String &s) // Reference with string is required here
    // As the new changed valeue else wont be accessible outside, so pass by reference
    // Friend fn is not a member of any class, it is basically global
    {
        char * c = new char[1000];
        t>>c;
        s= String(c);
    }
    void operator += (String a)
    {
        int s1 =this->len;
        int s2 = a.len;
        char * st = new char[s1+s2];
        int i,j;
        for(i=0;this->str[i]!='\0';i++)
            st[i]=this->str[i];
        j=i;
        for(i=0;a.str[i]!='\0';i++)
        {
            st[j++]=a.str[i];
        }
        this->str = st;
    }
    String operator + (String a)
    {
        int s1 =this->len;
        int s2 = a.len;
        char * st = new char[s1+s2];
        int i,j;
        for(i=0;this->str[i]!='\0';i++)
            st[i]=this->str[i];
        j=i;
        for(i=0;a.str[i]!='\0';i++)
        {
            st[j++]=a.str[i];
        }
        return String(st);
    }
};
int main()
{
    String s = "ayush";
    int i;
    String t;
    t = "mumbai";
    t.uppercase();
    t.print();
    cout<<t;
    //cout<<"bchds hbchjsd ch sd";
    cout<<endl;
    String x;
    //cin>>x;
    //x.print();
    //s+=t;
    //s.print();
    String a;
    a = s+t;
    a.print();
}