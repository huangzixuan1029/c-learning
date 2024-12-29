#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
class Phone{
    private:
        string pname;
        string jname;

    public:
    
        Phone(string j,string k): pname(j),jname(k) {}
        string getPname() const
        {
            return pname;
        }
        string getJname() const
        {
            return jname;
        }
};
class Person{
    private:
        string name;
        Phone myphone;

    public:
    Person(string ji,string lo,string mn):name(ji),myphone(lo,mn){}
    void showtime()
    {
        cout << name<<" use "<<myphone.getPname()<<myphone.getJname() << endl;
    }
};

int main()
{
    Person h{"huangzixuan","oneplus","12"};
    h.showtime();

    return 0;
}