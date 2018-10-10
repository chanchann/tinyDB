#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

int clustering(int i,int j,vector<vector<int>>& tmp)
{
    int cnt=0;
    if(tmp[i-1][j]==0) cnt++;
    if(tmp[i+1][j]==0) cnt++;
    if(tmp[i][j-1]==0) cnt++;
    if(tmp[i][j+1]==0) cnt++;
    cout<<i<<"   "<<j<<"   "<<cnt<<endl;
    return cnt;
}

int islandPerimeter(vector<vector<int>>& grid)
{
    int res=0;
    unordered_map<int,int> record;
    vector<vector<int>> tmp(grid.size()+2,vector<int>(grid[0].size()+2));
    for(int i=1;i<grid.size()+1;i++)
    {
        for(int j=1;j<grid[0].size()+1;j++)
        {
            tmp[i][j]=grid[i-1][j-1];
        }
    }
    for(int i=1;i<grid.size()+1;i++)
    {
        for(int j=1;j<grid[0].size()+1;j++)
        {
            if(tmp[i][j])
            {
                cout<<"--"<<i<<"  "<<j<<endl;
                record[clustering(i,j,tmp)]+=;
            }
        }
    }
    for(auto re:record)
    {
        res+=re.second;
    }
    return res;

}

int main()
{
    vector<vector<int>> a={
            {0,1,0,0},
            {1,1,1,0},
            {0,1,0,0},
            {1,1,0,0},
    };
    int total=islandPerimeter(a);
    cout<<total<<endl;

    return 0;
}