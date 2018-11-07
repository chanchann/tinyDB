#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

int main()
{
    int cnt=1;
    while(pow(3,cnt)<INT_MAX)
    {
        cnt++;
    }
    cout<<pow(3,cnt-1)<<endl;
    return 0;
}