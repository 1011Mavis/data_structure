#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
using namespace std;
struct TreeNode
{
    char val;
    TreeNode* left;
    TreeNode* right;
};
int cal_depth(TreeNode* root)
{
    if(!root)
    {
        return 0;
    }
    return 1+max(cal_depth(root->left), cal_depth(root->right));
}
bool compare(const char& op1, const char& op2)
{
    int num1, num2;
    num1= (op1=='+'||op1=='-') ? 1 : 2;
    num2= (op2=='+'||op2=='-') ? 1 : 2;
    return (num1>=num2);
}
void first_output(const string& exp, string& res)
{
    stack<char> st;
    for(char c : exp)
    {
        if((c>='a' && c<='z'))
        {
            res.push_back(c);
        }
        else if(c=='(')
        {
            st.push(c);
        }
        else if(c==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                res.push_back(st.top());
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && st.top()!='(' && compare(st.top(), c))
            {
                res.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    cout<<res<<'\n';
}
TreeNode* build_tree(const string& res)
{
    stack<TreeNode*> st;
    for(char c : res)
    {
        if(c>='a'&&c<='z')
        {
            TreeNode* cur=new TreeNode{c, nullptr, nullptr};
            st.push(cur);
        }
        else
        {
            if(!st.empty())
            {
                TreeNode* righttree=st.top();
                st.pop();  
                TreeNode* lefttree=st.top();
                st.pop();
                TreeNode* cur=new TreeNode{c, lefttree, righttree};
                st.push(cur);
            }
        }
    }
    TreeNode* root=st.top();
    return root;
}
void place_tree(const TreeNode* node, int row, int col, int child_offset,
                vector<map<int, char>>& rows)
{
    rows[row][col] = node->val;
    if (node->left)
    {
        rows[row + 1][col - 1] = '/';
        place_tree(node->left, row + 2, col - child_offset, child_offset / 2, rows);
    }
    if (node->right)
    {
        rows[row + 1][col + 1] = '\\';
        place_tree(node->right, row + 2, col + child_offset, child_offset / 2, rows);
    }
}

void print_tree(TreeNode* root)
{
    if (!root)
    {
        return;
    }

    int depth = cal_depth(root);
    int half_width = 1 << (depth - 1);
    vector<map<int, char>> rows(2 * depth - 1);
    place_tree(root, 0, half_width - 1, half_width / 2, rows);

    for (const auto& row : rows)
    {
        int next_col = 0;
        for (const auto& cell : row)
        {
            cout << string(cell.first - next_col, ' ') << cell.second;
            next_col = cell.first + 1;
        }
        cout << '\n';
    }
}

// Match the generator's 32-bit results without signed overflow in C++.
int32_t wrap_int32(int64_t value)
{
    int64_t low_bits = static_cast<uint32_t>(value);
    if (low_bits > INT32_MAX)
    {
        low_bits -= int64_t{1} << 32;
    }
    return static_cast<int32_t>(low_bits);
}

struct Value
{
    int32_t number;
    bool has_missing_weight;
};

Value cal_sum(const vector<int32_t>& vals, const TreeNode* root)
{
    if (root->val >= 'a' && root->val <= 'z')
    {
        int32_t weight = vals[root->val - 'a'];
        return {weight, weight == 0};
    }
    Value left_value = cal_sum(vals, root->left);
    Value right_value = cal_sum(vals, root->right);
    int64_t left = left_value.number;
    int64_t right = right_value.number;
    bool has_missing_weight = left_value.has_missing_weight || right_value.has_missing_weight;
    switch (root->val)
    {
        case '+': return {wrap_int32(left + right), has_missing_weight};
        case '-': return {wrap_int32(left - right), has_missing_weight};
        case '*': return {wrap_int32(left * right), has_missing_weight};
        case '/':
            // Zero leaf weights come from divisor subtrees skipped by the generator.
            if (right_value.has_missing_weight || right == 0)
            {
                return {0, left_value.has_missing_weight};
            }
            return {wrap_int32(left / right), left_value.has_missing_weight};
    }
    abort();
}
void delete_nodes(TreeNode* root)
{
    if(root)
    {
        delete_nodes(root->left);
        delete_nodes(root->right);
        delete root;
    }
}
int main()
{
    string exp, res;
    cin>>exp;
    first_output(exp, res);
    TreeNode* root=build_tree(res);
    int count;
    vector<int32_t> vals(26);
    cin>>count;
    while(count--)
    {
        char ch;
        cin>>ch;
        cin>>vals[ch-'a'];
    }
    print_tree(root);
    cout<<cal_sum(vals, root).number<<'\n';
    delete_nodes(root);
}
