#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int findLHS(vector<int>& nums)
{
    unordered_map<int,int> record;
    for(auto& num:nums)
    {
        record[num]++;
    }
    int res=0;
    for(auto& re:record)
    {
        if(record.count(re.first+1) && res<(re.second+record[re.first+1]))
        {
            res=re.second+record[re.first+1];
        }
    }
    return res;
}
int main() {
    vector<int> nums={1,3,2,2,5,2,3,7};
    cout<<findLHS(nums)<<endl;
    return 0;
}