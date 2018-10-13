#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    vector<string> a={"a","banana","app","appl","ap","apply","apple"};
    sort(a.begin(),a.end());
    for(auto it=a.begin();it!=a.end();it++)
    {
        cout<<*it<<endl;
    }

}