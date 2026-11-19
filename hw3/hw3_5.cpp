#include <iostream>
#include <vector>
using namespace std;
int shared_parent(const vector<int> &tree, const int &x, const int &y)
{
    int p1=x, p2=y;
    while(p1!=p2)
    {
        p1= (p1>=0 ? tree[p1] : y);
        p2= (p2>=0 ? tree[p2] : x);
    }
    return p1;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n, m;
        cin>>n>>m;
        vector<int> tree(n, -1);
        while(--n)
        {
            int parent, child;
            cin>>parent>>child;
            tree[child-1]=parent-1;
        }
        while(m--)
        {
            int x, y;
            cin>>x>>y;
            cout<<shared_parent(tree, x-1, y-1)+1<<'\n';
        }
    }
}