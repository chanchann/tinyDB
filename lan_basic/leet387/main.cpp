#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;
int firstUniqChar(string s)
    {
        unordered_map<char,int> record;
        char res;
        int flag=0;
        for(int i=0;i<s.size();i++)
        {
            record[s[i]]++;
        }
        for(auto re:record)
        {
            if(re.second==1)
            {
                res=re.first;
                flag=1;
                break;
            }
        }
        if(flag)
        {
            for(int i=0;i<s.size();i++)
            {
                if(res==s[i])
                {
                    cout << res << endl;
                    return i;

                }
            }
        }
        else
            return -1;
    }
int main()
{
    string a="leetcode";
    int b=firstUniqChar(a);
    cout<<b<<endl;
    return 0;
}