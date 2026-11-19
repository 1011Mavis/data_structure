#include <iostream>
#include <string>
using namespace std;
bool build_post(const string& pre, const string& in, int prestart, int instart, int len, string& post)
{
    if(len==0)
    {
        return true;
    }
    char root=pre[prestart];
    int id=instart;
    int end=instart+len;
    while(id<end && in[id]!=root)
    {
        ++id;
    }
    if(id==end)
    {
        return false;
    }
    int leftlen=id-instart;
    int rightlen=len-leftlen-1;
    if(!build_post(pre, in, prestart+1, instart, leftlen, post))
    {
        return false;
    }
    if(!build_post(pre, in, prestart+leftlen+1, id+1, rightlen, post))
    {
        return false;
    }
    post.push_back(root);
    return true;
}
int main()
{
    string pre, in;
    while(cin>>pre>>in)
    {
        if(pre.size()!=in.size())
        {
            cout<<"Error\n";
            continue;
        }
        string post;
        int length=in.size();
        if(build_post(pre, in, 0, 0, length, post))
        {
            cout<<post<<'\n';
        }
        else
        {
            cout<<"Error\n";
        }
    }
}