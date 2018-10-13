#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int longestPalindrome(string s)
    {
        map<char,int> record;
        int cnt=0;
        int flag=0;
        int odd=0;
        for(auto ch:s)
        {
            record[ch]++;
        }
        for(auto re:record)
        {
            cout<<re.first<<"\t"<<re.second<<endl;
        }
        for(auto& re:record)
        {
            if(re.second%2!=0)
            {
                flag=1;
                if(re.second>odd)
                    odd=re.second;
            }
            else
            {
                cnt+=re.second;
                cout<<"cnt"<<cnt<<endl;
            }
        }
        if(flag)
        {
            cnt+=odd;
            cout<<"odd:"<<odd<<endl;
        }

        return cnt;
    }

int main()
{
    string a="civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    cout<<longestPalindrome(a)<<endl;
    return 0;
}