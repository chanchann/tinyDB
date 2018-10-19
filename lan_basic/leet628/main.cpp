#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a={1,2,3,4};
    int res=1;
    int res2=1;
    for(auto it=a.rbegin();it<a.rbegin()+3;it++)
    {
        res*=*it;
        cout<<"res:"<<res<<endl;
    }
    for(auto it=a.begin();it<a.begin()+2;it++)
    {
        res2*=*it;
        cout<<"res2:"<<res2<<endl;
    }
    res2*=*(a.end()-1);
    cout<<res2<<endl;


    return 0;
}