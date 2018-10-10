#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
vector<string> split(string& A)
{
    vector<string> tmp;
    int pos=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==' ')
        {
            tmp.push_back(A.substr(pos,i-pos));
            pos=i+1;
        }
    }
    return tmp;
}

vector<string> uncommonFromSentences(string A, string B)
{
    vector<string> res;
    unordered_map<string,int> dict;
    vector<string> A_split=split(A);
    vector<string> B_split=split(B);
    for(auto a:A_split)
    {
        dict[a]++;
    }
    for(auto b:B_split)
    {
        dict[b]++;
    }
    for(auto c:dict)
    {
        if(c.second==1)
        {
            res.push_back(c.first);
        }
    }
    return res;
}

int main()
{
    string a="this apple is sweet";
    string b="this apple is sour";
    vector<string> res=uncommonFromSentences(a,b);
    for(auto re:res)
    {
        cout<<re<<endl;
    }
}