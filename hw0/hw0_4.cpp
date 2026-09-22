#include <iostream>
using namespace std;
int main()
{
    int n, m;
    while(cin>>n>>m)
    {
        int res=0;
        for(int people=2; people<=n;++people)
        {
            res=(res+m)%people;
        }
        cout<<res<<endl;
    }
    return 0;
}