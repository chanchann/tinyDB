#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
string shortestCompletingWord(string licensePlate, vector<string>& words)
{
    string res=words[0];
    unordered_map<char,int> lrecord;
    unordered_map<char,int> wrecord;
    for(int i=0;i<licensePlate.size();i++)
    {
        if(isalpha(licensePlate[i]))
        {
            lrecord[tolower(licensePlate[i])]++;
        }
    }
    for(auto word:words)
    {
        if(word==words[0])
            continue;
        int flag=1;
        for(int i=0;i<word.size();i++)
        {
            wrecord[tolower(word[i])]++;
        }
        for(auto l:lrecord)
        {
            if(l.second!=wrecord[l.first])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            if(res.size()>word.size())
                res=word;
        }
        wrecord.clear();
    }
    return res;
}

int main() {
    string a="1s3345";
    vector<string> b={"step","steps","stripe","stepple"};
    vector<string> c={"looks","pest","stew","show"};
    string res=shortestCompletingWord(a,c);
    cout<<res<<endl;
    return 0;
}