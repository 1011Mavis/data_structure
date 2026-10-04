#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct element
{
    long long coef;
    long long exp;
};
void print_res(const map<long long, long long>& res)
{
    bool isfirst=true;
    for(const auto& item : res)
    {
        if(item.second==0)
            continue;
        if(!isfirst)
            cout<<" ";
        cout<<item.second<<" "<<item.first;
        isfirst=false;
    }
    cout<<'\n';
}
int main()
{
    int m, n;
    while(cin>>m)
    {
        vector<element> term1(m);
        for(int i=0; i<m; i++)
        {
            cin>>term1[i].coef>>term1[i].exp;
        }
        cin>>n;
        vector<element> term2(n);
        for (int i=0; i<n; i++)
        {
            cin>>term2[i].coef>>term2[i].exp;
        }
        int command;
        cin>>command;
        if(command==0||command==2)
        {
            map<long long, long long> res;
            for(auto ele1 : term1)
            {
                res[ele1.exp]+=ele1.coef;
            }
            for(auto ele2 : term2)
            {
                res[ele2.exp]+=ele2.coef;
            }
            print_res(res);
        }
        if(command==1||command==2)
        {
            map<long long, long long> res;
            for(auto ele1 : term1)
            {
                for(auto ele2 : term2)
                {
                    res[ele1.exp+ele2.exp]+=ele1.coef*ele2.coef;
                }
            }
            print_res(res);
        }
    }
    return 0;
}
