#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct card
{
    string pattern;
    string num;
};
int convert_num(const card& a)
{
    if(a.num=="A")
        return 1;
    else if(a.num=="J")
        return 11;
    else if(a.num=="Q")
        return 12;
    else if(a.num=="K")
        return 13;
    else
        return stoi(a.num);
}
bool compare_cards(const card& a, const card& b)
{
    return convert_num(a)<convert_num(b);
}
vector<card> extract_card(vector<card>& cards, string color)
{
    vector<card> newcards;
    vector<card> remaining;
    for(const card& a : cards)
    {
        if(a.pattern==color)
        {
            newcards.push_back(a);
        }
        else
        {
            remaining.push_back(a);
        }
    }
    sort(newcards.begin(), newcards.end(), compare_cards);
    for(const card& c : remaining)
    {
        newcards.push_back(c);
    }
    return newcards;
}
int main()
{
    int n;
    while(cin>>n)
    {
        string command;
        vector<card> cards;
        while(n--)
        {
            cin>>command;
            if(command=="Append")
            {
                card nc;
                cin>>nc.pattern>>nc.num;
                cards.push_back(nc);
            }
            else if(command=="Extract")
            {
                string color;
                cin>>color;
                cards=extract_card(cards, color);
            }
            else if(command=="Revert")
            {
                reverse(cards.begin(), cards.end());
            }
            else if(command=="Pop")
            {
                if(cards.empty())
                    cout<<"NULL\n";
                else
                {
                    cout<<cards.front().pattern<<' '<<cards.front().num<<'\n';
                    cards.erase(cards.begin());
                }
            }
        }
        if(cards.empty())
            {
                cout<<"NULL\n";
            }
            else
            {
                for(const card& a : cards)
                {
                    cout<<a.pattern<<" "<<a.num<<endl;
                }
            }
    }
    return 0;
}