#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode
{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c): val(c), left(nullptr), right(nullptr) {}
};
void print_postorder(TreeNode* root)
{
    vector<char> res;
    stack<TreeNode*> st;
    if(!root)
    {
        return;
    }
    st.push(root);
    while(!st.empty())
    {
        TreeNode* cur=st.top();
        res.push_back(cur->val);
        st.pop();
        if(cur->left)
        {
            st.push(cur->left);
        }
        if(cur->right)
        {
            st.push(cur->right);
        }
    }
    reverse(res.begin(), res.end());
    for(char c : res)
    {
        cout<<c;
    }
    cout<<'\n';
}
int main()
{
    int n;
    string command;
    TreeNode* cur=nullptr;
    TreeNode* root=nullptr;
    stack<TreeNode*> st;
    cin>>n;
    for(int i=0; i<2*n; i++)
    {
        cin>>command;
        if(command=="push")
        {
            char cap;
            cin>>cap;
            TreeNode* node=new TreeNode(cap);
            st.push(node);
            if(i==0)
            {
                root=node;
                cur=node;
            }
            else
            {
                if(!cur->left)
                {
                    cur->left=node;
                    cur=cur->left;
                }
                else
                {
                    cur->right=node;
                    cur=cur->right;
                }
            }
        }
        else if(command=="pop")
        {
            cur=st.top();
            st.pop();
        }
    }
    print_postorder(root);
}