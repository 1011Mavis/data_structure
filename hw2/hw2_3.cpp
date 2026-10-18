#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);  //注意输入可能有空行，必须用getline, cin会跳过空行
    int start=0;
    int max_len=0;
    int len;
    stack<int> st;
    st.push(-1);
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                len=i-st.top();
                if(len>max_len)
                {
                    max_len=len;
                    start=st.top()+1;
                }
            }
        }
    }
    cout<<max_len<<" "<<start<<endl;
}