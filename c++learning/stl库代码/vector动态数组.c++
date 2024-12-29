#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v;
    v.resize(4);
    cout<<sizeof(v)<<endl;//固定大小是24
    cout << v.size() << endl;
    v.push_back(6);
    for (auto p = v.begin();p!=v.end();p++)
    {
        cout << *p << " ";
    }
    cout << v.size() << endl;
    return 0;
}