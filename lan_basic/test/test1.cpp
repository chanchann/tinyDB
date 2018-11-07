#include<iostream>
using namespace std;
bool isUgly(int num) 
{
    while(num%2==0)
    {
        num/=2;
        cout<<num<<endl;
    }
    while(num%3==0)
    {
        num/=3;
        cout<<num<<endl;
    }
    while(num%5==0)
    {
        num/=5;
        cout<<num<<endl;
    }
    cout<<num<<endl;
    if(num==1)
        return true;
    else
        return false;
}
int main()
{
    cout<<isUgly(6)<<endl;
}