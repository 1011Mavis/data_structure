#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct student{
    string id;
    string name;
};
class StudentTable
{
public:
    vector<student> table;
    void loadStudents(int n)
    {
        student s;
        for(int i=0; i<n; i++)
        {
            cin>>s.id>>s.name;
            table.push_back(s);
        }
    }
    int input_insert(int i)
    {
        student s;
        cin>>s.id>>s.name;
        if(i<1||i>table.size()+1)
        {
            return -1;
        }
        table.push_back(student());
        int k;
        for(k=table.size()-1; k>=i; k--)
        {
            table[k]=table[k-1];
        }
        table[k]=s;
        return 0;
    }
    int input_remove(int j)
    {
        if(j<1||j>table.size())
        {
            return -1;
        }
        for(int i=j-1; i<table.size()-1; i++)
        {
            table[i]=table[i+1];
        }
        table.pop_back();
        return 0;
    }
    void input_check(string y, string y_type)
    {
        if(y_type=="name")
        {
            for(int i=0; i<table.size(); i++)
            {
                if(table[i].name==y)
                {
                    cout<<i+1<<" "<<table[i].id<<" "<<table[i].name<<endl;
                    return ;
                }
            }
            cout<<-1<<endl;
            return ;
        }
        else
        {
            for(int i=0; i<table.size(); i++)
            {
                if(table[i].id==y)
                {
                    cout<<i+1<<" "<<table[i].id<<" "<<table[i].name<<endl;
                    return ;
                }
            }
            cout<<-1<<endl;
            return ;
        }
    } 
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n)
    {
        StudentTable students;
        students.loadStudents(n);
        string command;
        while(cin>>command)
        {
            if(command=="insert")
            {
                int pos;
                cin>>pos;
                cout<<students.input_insert(pos)<<endl;
            }
            else if(command=="remove")
            {
                int pos;
                cin>>pos;
                cout<<students.input_remove(pos)<<endl;
            }
            else if(command=="check")
            {
                string check_type, check_item;
                cin>>check_type>>check_item;
                students.input_check(check_item, check_type);
            }
            else if(command=="end")
            {
                cout<<students.table.size()<<endl;
                break;
            }
        }
    }
    return 0;
}