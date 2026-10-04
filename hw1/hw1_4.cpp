#include <iostream>
#include <vector>
using namespace std;
vector<int> add(vector<int>& a, vector<int>& b)
{
    vector<int> res;
    int carry=0;
    int sum;
    for(int i=0; i<a.size()||i<b.size(); i++)
    {
        sum=0;
        if(i<a.size())
        {
            sum+=a[i];
        }
        if(i<b.size())
        {
            sum+=b[i];
        }
        sum+=carry;
        res.push_back(sum%10);
        carry=sum/10;
    }
    if(carry>0)
    {
        res.push_back(carry);
    }
    return res;
}
vector<int> multiply(vector<int>& a, int num)
{
    if(num==0)
    {
        return vector<int>{0};
    }
    vector<int> res;
    int carry=0;
    for(int n : a)
    {
        int sum=n*num+carry;
        res.push_back(sum%10);
        carry=sum/10;
    }
    while(carry>0)
    {
        res.push_back(carry%10);
        carry/=10;
    }
    return res;
}
void display(const vector<int>& res)
{
    for(int i=res.size()-1; i>=0;i--)
    {
        cout<<res[i];
    }
    cout<<endl;
}
int main()
{
    int n, a;
    while(cin>>n>>a)
    {
        vector<int> res{0};
        vector<int> term{1};
        for(int i=1; i<=n; i++)
        {
            term=multiply(term, a);
            vector<int> ele=multiply(term, i);
            res=add(res, ele);
        }
        display(res);
    }
    return 0;
}
