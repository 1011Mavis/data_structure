#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
struct node{
    int depth;
    int child;
};
int main()
{
    string str;
    int id=0;
    while(cin>>str)
    {
        if(!str.empty() && str=="#")
        {
            break;
        }
        id++;
        int h1=0, h2=0;
        stack<node> st;
        node root;
        root.depth=0;
        root.child=0;
        st.push(root);
        for(char c : str)
        {
            if(c=='d')
            {
                node& parent=st.top();
                node newnode;
                parent.child++;
                newnode.depth=parent.depth+parent.child;
                newnode.child=0;
                st.push(newnode);
                int len=st.size()-1;
                h1=max(h1, len);
                h2=max(h2, newnode.depth);
            }
            else if(c=='u')
            {
               st.pop();
            }
        }
        cout<<"Tree "<<id<<": "<<h1<<" => "<<h2<<'\n';
    }
}