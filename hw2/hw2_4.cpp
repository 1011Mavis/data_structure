#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
bool checkedge(int i, int k, int n, int m)
{
    if(i==0||k==0||i==n-1||k==m-1)
    {
        return true;
    }
    return false;
}
bool check(int i, int k, int n, int m)
{
    return (i<=n-1 && i>=0 && k>=0 && k<=m-1);
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0; i<n; i++)
    {
        for(int k=0; k<m; k++)
        {
            cin>>matrix[i][k];
        }
    }
    int res=0;
    for(int i=0; i<n; i++)
    {
        for(int k=0; k<m; k++)
        {
            if(matrix[i][k]==1)
            {
                bool isedge=true;
                queue<pair<int, int>> checklist;
                matrix[i][k]=0;
                isedge=isedge&&checkedge(i, k, n, m);
                checklist.push({i,k});
                while(!checklist.empty())
                {
                    int x=checklist.front().first;
                    int y=checklist.front().second;
                    checklist.pop();
                    if(check(x-1, y, n, m))
                    {
                        if(matrix[x-1][y]==1)
                        {
                            isedge=isedge&&checkedge(x-1, y, n, m);
                            checklist.push({x-1, y});
                            matrix[x-1][y]=0;
                        }
                    }
                    if(check(x+1, y, n, m))
                    {
                        if(matrix[x+1][y]==1)
                        {
                            isedge=isedge&&checkedge(x+1, y, n, m);
                            checklist.push({x+1, y});
                            matrix[x+1][y]=0; 
                        }
                    }
                    if(check(x, y-1, n, m))
                    {
                        if(matrix[x][y-1]==1)
                        {
                            isedge=isedge&&checkedge(x, y-1, n, m);
                            checklist.push({x, y-1});
                            matrix[x][y-1]=0;
                        } 
                    }
                    if(check(x, y+1, n, m))
                    {
                        if(matrix[x][y+1]==1)
                        {
                            isedge=isedge&&checkedge(x, y+1, n, m);
                            checklist.push({x, y+1});
                            matrix[x][y+1]=0;
                        }
                    }
                }
                if(!isedge)
                {
                    res+=1;
                }
            }
        }
    }
    cout<<res<<endl;
}