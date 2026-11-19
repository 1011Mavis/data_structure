#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int left;
    int right;
    int parent=-1;
    bool infected =false;
};
void create_tree(vector<node> &tree, const int& size)
{
    for(int i=0; i<size; i++)
    {
        cin>>tree[i].left>>tree[i].right;
        if(tree[i].left!=-1)
        {
            tree[tree[i].left].parent=i;
        }
        if(tree[i].right!=-1)
        {
           tree[tree[i].right].parent=i;   
        }     
    }
}
int main()
{
    int n, start;
    cin>>n>>start;
    queue<int> st;
    st.push(start);
    int count=0, minutes=-1;
    vector<node> tree(n);
    create_tree(tree, n);
    while(count<n)
    {
        int len=st.size();
        while(len--)
        {
            start=st.front();
            tree[start].infected=true;
            count++;
            st.pop();
            if(tree[start].parent>=0 && !tree[tree[start].parent].infected)
            {
                st.push(tree[start].parent);
            }
            if(tree[start].left>=0 && !tree[tree[start].left].infected)
            {
                st.push(tree[start].left);
            }
            if(tree[start].right>=0 && !tree[tree[start].right].infected)
            {
                st.push(tree[start].right);
            }
        }
        minutes+=1;
    }
    cout<<minutes<<'\n';
}