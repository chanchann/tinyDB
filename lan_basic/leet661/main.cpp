#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& M)
{
    for(int i=0;i<M.size();i++)
    {
        for(int j=0;j<M[0].size();j++)
        {
            int sum=0,cnt=0;
            for(int k=i-1;k<i+2;k++)
            {
                for(int p=j-1;p<j+2;p++)
                {
                    if(k>=0&&p>=0)
                    {
                        cout<<k<<" "<<p<<endl;
                        sum+=M[k][p];
                        cnt++;
                    }
                }
            }
            M[i][j]=floor(sum/cnt);
        }
    }
    return M;
}

int main() {
    vector<vector<int>> test(3,vector<int>(3));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            test[i][j] = 1;
            cout<<test[i][j]<<endl;
        }
    }
    test[1][1]=0;
    vector<vector<int>> res=imageSmoother(test);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<res[i][j]<<endl;
        }
    }
    return 0;
}