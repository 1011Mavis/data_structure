#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==-1)
            break;
        else
        {
            long long fm_bees=1;
            long long m_bees=0;
            while(n--)
            {
                fm_bees-=1;
                long long n_fm_bees=m_bees;
                long long n_m_bees=fm_bees+m_bees;
                fm_bees=n_fm_bees+1;
                m_bees=n_m_bees+1;
            }
            cout<<m_bees<<' '<<m_bees+fm_bees<<endl;  
        }
    }
    return 0;
}