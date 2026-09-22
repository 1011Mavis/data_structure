#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int sum;
    while(getline(cin, str))
    {
        sum=0;
        if(!str.empty()&&str.back()=='\r')
            str.pop_back();
        if(str=="#")
            break;
        int len=str.size();
        for(int i=1;i<=len;i++)
        {
            if(str[i-1]>='A'&&str[i-1]<='Z')
                sum+=(str[i-1]-'A'+1)*i;
        } 
        cout<<sum<<endl;     
    }
    return 0;
}