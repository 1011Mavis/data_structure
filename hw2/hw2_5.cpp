#include <iostream>
#include <deque>
#include <queue>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string str;
    queue<int> res;
    deque<int> seq;
    while(cin>>str)
    {
        if(str=="dequeue")
        {
            if(res.empty())
            {
                cout<<"Queue is Empty"<<endl;
            }
            else
            {
                if(!seq.empty()&&seq.front()==res.front())
                {
                    seq.pop_front();
                }
                cout<<res.front()<<endl;
                res.pop();
            }
        }
        else if(str=="enqueue")
        {
            int el;
            cin>>el;
            if(res.size()==n)
            {
                cout<<"Queue is Full"<<endl;
            }
            else
            {
                while(!seq.empty()&&seq.back()<el)
                {
                    seq.pop_back();
                }
                seq.push_back(el);
                res.push(el);
            }
        }
        else if(str=="max")
        {
            if(res.empty())
            {
                cout<<"Queue is Empty"<<endl;
            }
            else
            {
                cout<<seq.front()<<endl;
            }
        }
        else if(str=="quit")
        {
            bool first=true;
            while(!res.empty())
            {
                if(!first)
                {
                    cout<<" ";
                }
                first=false;
                cout<<res.front();
                res.pop();
            }
            cout<<endl;
            break;
        }
    }
}
