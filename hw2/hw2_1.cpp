#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string str;
    cin>>str;
    string seq;
    while(cin>>seq)
    {
        if(seq.size()!=str.size())
        {
            cout<<"no"<<endl;
            continue;
        }
        stack<char> station;
        int i=0;
        int j=0;
        while(i<seq.size())
        {
            if(!station.empty()&&station.top()==seq[i])
            {
                station.pop();
                i++;
            }
            else if(j<str.size())
            {
                if(seq[i]!=str[j])
                {
                    station.push(str[j++]);
                }
                else
                {
                    j++;
                    i++;
                }
            }
            else
            {
                break;
            }
        }
        if(i==seq.size())
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
    return 0;
}