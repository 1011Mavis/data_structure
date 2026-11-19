#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct node{
    char c;
    int left;
    int right;
};
int create_tree(vector<node> &tree, int n)
{
    string num1, num2;
    vector<bool> isroot(n, true);
    for(int i=0; i<n; i++)
    {
        cin>>tree[i].c>>num1>>num2;
        tree[i].left= (num1=="-" ? -1 :stoi(num1));
        tree[i].right= (num2=="-" ? -1 :stoi(num2));
        if(tree[i].left>=0)
        {
            isroot[tree[i].left]=false;
        }
        if(tree[i].right>=0)
        {
            isroot[tree[i].right]=false;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(isroot[i])
        {
            return i;
        }
    }
    return -1;
}
bool is_leaf(const node& n)
{
    if(n.left==-1&&n.right==-1)
    {
        return true;
    }
    return false;
}
bool compare_tree(vector<node>& tree1, vector<node>& tree2, int id1, int id2)
{
    if(id1==-1 || id2==-1)
    {
        return id1==id2;
    }
    const node& a=tree1[id1];
    const node& b=tree2[id2];
    if(a.c!=b.c)
    {
        return false;
    }
    return (compare_tree(tree1, tree2, a.left, b.left) &&
            compare_tree(tree1, tree2, a.right, b.right)) ||
           (compare_tree(tree1, tree2, a.left, b.right) &&
            compare_tree(tree1, tree2, a.right, b.left));
}
int calculate_depth(const vector<node>& tree, int root)
{
    if(root==-1)
    {
        return 0;
    }
    int left_depth=calculate_depth(tree, tree[root].left);
    int right_depth=calculate_depth(tree, tree[root].right);
    return 1+max(left_depth, right_depth);
}
int main()
{
    int n1, n2;
    cin>>n1;
    vector<node> tree1(n1);
    int root1=create_tree(tree1, n1);

    cin>>n2;
    vector<node> tree2(n2);
    int root2=create_tree(tree2, n2);
    if(compare_tree(tree1, tree2, root1, root2))
    {
        cout<<"Yes"<<'\n';
    }
    else
    {
        cout<<"No"<<'\n';
    }
    cout<<calculate_depth(tree1, root1)<<'\n'<<calculate_depth(tree2, root2)<<'\n';
}
