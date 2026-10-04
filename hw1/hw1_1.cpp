#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};
int main()
{
    int n, k;
    while(cin>>n>>k)
    {
        if(k>=n)
        {
            k%=n;
        }
        int head, val;
        cin>>head;
        ListNode* hd=new ListNode(head);
        ListNode* cur=hd;
        ListNode* start=hd;
        for(int i=1; i<n; i++)
        {
            cin>>val;
            ListNode* newhead=new ListNode(val);
            if(i==n-k)
            {
                start=newhead;
            }
            cur->next=newhead;
            cur=newhead;
        }
        cur->next=hd;
        for(int k=0; k<n; k++)
        {
            cout<<start->val<<" ";
            start=start->next; 
        }
        cout<<endl;
        cur=hd;
        for(int i=0; i<n; i++)
        {
            ListNode* nextnode=cur->next;
            delete cur;
            cur=nextnode;
        }
    }
    return 0;
}