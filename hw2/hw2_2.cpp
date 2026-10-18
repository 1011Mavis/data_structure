#include <iostream>
#include <stack>
#include <string>
using namespace std;
void caculation(stack<char>& operators, stack<char>& operands)
{
    if(operators.top()=='&')
    {
        char op1=operands.top();
        operands.pop();
        char op2=operands.top();
        operands.pop();
        if(op1=='F'||op2=='F')
        {
            operands.push('F');
        }
        else{
            operands.push('V');
        }
    }
    else if(operators.top()=='|')
    {
        char op1=operands.top();
        operands.pop();
        char op2=operands.top();
        operands.pop();
        if(op1=='V'||op2=='V')
        {
            operands.push('V');
        }
        else{
            operands.push('F');
        }
    }
    else if(operators.top()=='!')
    {
        if(operands.top()=='F')
        {
            operands.pop();
            operands.push('V');
        }
        else
        {
            operands.pop();
            operands.push('F');
        }
    }
    operators.pop();
}
int main()
{
    string str;
    int id=1;
    while(getline(cin, str))
    {
        stack<char> operands;
        stack<char> operators;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]==' ')
            {
                continue;
            }
            else if(str[i]=='F'||str[i]=='V')
            {
                operands.push(str[i]);
            }
            else if(str[i]==')')
            {
                while(operators.top()!='(')
                {
                    caculation(operators, operands);
                }
                operators.pop();
            }
           else if(str[i]=='('||str[i]=='!')
           {
                operators.push(str[i]);
           } 
           else if(str[i]=='&')
           {
                while(!operators.empty()&&operators.top()=='!')
                {
                    caculation(operators, operands);
                }
                operators.push(str[i]);
           }
           else
           {
                while(!operators.empty()&&(operators.top()=='!'||operators.top()=='&'))
                {
                    caculation(operators, operands);
                }
                operators.push(str[i]);
           }
        }
        while(!operators.empty())
        {
            caculation(operators, operands);
        }
        if(!operands.empty())
        {
            cout<<"Expression "<<id<<": "<<operands.top()<<endl;
            id++;
        } 
    }
}