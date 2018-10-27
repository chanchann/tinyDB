#include <iostream>
#include <vector>

using namespace std;
int dominantIndex(vector<int>& nums)
    {
        if(nums.size()==1)
            return 0;
        int max=nums[0],max_index=0,max_low=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(max<nums[i])
            {
                max=nums[i];
                max_index=i;
            }
        }
        for(int i=1;i<nums.size();i++)
        {
            if(max_low<nums[i] && max_low<max)
            {
                max_low=nums[i];
                cout<<"max_low:"<<max_low<<endl;
            }
        }
        cout<<max<<endl;
        cout<<max_low<<endl;
        if( max_low==0 || max/max_low>=2)
            return max_index;
        else
            return -1;
    }
int main()
{
    vector<int> a(4);
    a[3]=1;
    cout<<dominantIndex(a)<<endl;
    return 0;
}