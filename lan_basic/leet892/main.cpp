#include <iostream>
#include <vector>

using namespace std;

int surfaceArea(vector<vector<int>>& grid)
{
    int cnt=0;
    int minus=0;
    vector<vector<int>> tmp(grid.size()+2,vector<int>(grid[0].size()+2,0));
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            cnt+=grid[i][j];
            tmp[i+1][j+1]=grid[i][j];
            cout<<cnt<<endl;
        }
    }
    int total=cnt*6;
    for(int i=0;i<tmp.size();i++)
    {
        for(int j=0;j<tmp[0].size();j++)
        {
            cout<<tmp[i][j]<<"\t";
        }
        cout<<endl;
    }
    for(int i=1;i<grid.size()+1;i++)
    {
        for(int j=1;j<grid[0].size()+1;j++)
        {
            minus+=tmp[i][j]>tmp[i-1][j]?tmp[i-1][j]:tmp[i][j];
            minus+=tmp[i][j]>tmp[i+1][j]?tmp[i+1][j]:tmp[i][j];
            minus+=tmp[i][j]>tmp[i][j-1]?tmp[i][j-1]:tmp[i][j];
            minus+=tmp[i][j]>tmp[i][j+1]?tmp[i][j+1]:tmp[i][j];
            minus+=(tmp[i][j]-1)*2;
            cout<<"minus:"<<minus<<endl;
        }
    }
    return total-minus;

}
int main() {
    vector<vector<int>> a(2,vector<int>(2,0));
    a[0][0]=1;
    a[1][1]=2;
    cout<<surfaceArea(a)<<endl;
    return 0;
}