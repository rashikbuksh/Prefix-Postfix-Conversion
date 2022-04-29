#include<iostream>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;
string POSTFIX(string);
string PREFIX(string);
double CPOSTFIX(string);
double CPREFIX(string);


int main()
{
    string infix,prefix,postfix;
    cout<<"Input the INFIX Expression: ";
    cin>>infix;
    prefix=PREFIX(infix);
    postfix=POSTFIX(infix);
    cout<<endl<<endl<<"The PREFIX Expression is: "<<prefix;
    cout<<endl<<endl<<"The POSTFIX Expression is: "<<postfix;
    cout<<endl<<endl<<"The PREFIX conversion result is: "<<CPREFIX(prefix);
    cout<<endl<<endl<<"The POSTFIX conversion result is: "<<CPOSTFIX(postfix)<<endl<<endl;
}


double CPREFIX(string prefix)
{
    reverse(prefix.begin(),prefix.end());
    double result,a,b;
    stack<double> r;
    for(int i=0;i<prefix.length();i++)
    {
        switch(prefix[i])
        {
        case '+':
            a=r.top();
            r.pop();
            b=r.top();
            r.pop();
            result=a+b;
            r.push(result);
            break;
        case '-':
            a=r.top();
            r.pop();
            b=r.top();
            r.pop();
            result=a-b;
            r.push(result);
            break;
        case '*':
            a=r.top();
            r.pop();
            b=r.top();
            r.pop();
            result=a*b;
            r.push(result);
            break;
        case '/':
            a=r.top();
            r.pop();
            b=r.top();
            r.pop();
            result=a/b;
            r.push(result);
            break;
        case '^':
            a=r.top();
            r.pop();
            b=r.top();
            r.pop();
            result=pow(a,b);
            r.push(result);
            break;
        default:
            r.push(prefix[i]-'0');
            break;
        }
    }
    return r.top();
}

double CPOSTFIX(string postfix)
{
    double result,a,b;
    stack<double> r;
    for(int i=0;i<postfix.length();i++)
    {
        switch(postfix[i])
        {
        case '+':
            b=r.top();
            r.pop();
            a=r.top();
            r.pop();
            result=a+b;
            r.push(result);
            break;
        case '-':
            b=r.top();
            r.pop();
            a=r.top();
            r.pop();
            result=a-b;
            r.push(result);
            break;
        case '*':
            b=r.top();
            r.pop();
            a=r.top();
            r.pop();
            result=a*b;
            r.push(result);
            break;
        case '/':
            b=r.top();
            r.pop();
            a=r.top();
            r.pop();
            result=a/b;
            r.push(result);
            break;
        case '^':
            b=r.top();
            r.pop();
            a=r.top();
            r.pop();
            result=pow(a,b);
            r.push(result);
            break;
        default:
            r.push(postfix[i]-'0');
            break;
        }
    }
    return r.top();
}


string PREFIX(string prefix)
{
    string p,postfix;
    for(int i=prefix.length()-1;i>=0;i--)
    {
        if(prefix[i]==')')
            p+='(';
        else if(prefix[i]=='(')
            p+=')';
        else
            p+=prefix[i];
    }
    postfix=POSTFIX(p);
    reverse(postfix.begin(),postfix.end());
    return postfix;
}


string POSTFIX(string infix)
{
    string postfix;
    stack<char> s;
    int p=0;
    for(int i=0;i<infix.length();i++)
    {
        switch(infix[i])
        {
        case '+':
            if(p>=1)
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
            p=1;
            break;
        case '-':
            if(p>=1)
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
            p=1;
            break;
        case '*':
            if(p>=2)
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
            p=2;
            break;
        case '/':
            if(p>=2)
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
            p=2;
            break;
        case '^':
            s.push(infix[i]);
            p=3;
            break;
        case '(':
            s.push(infix[i]);
            p=0;
            break;
        case ')':
            while(s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
            if(s.empty())
                p=0;
            else if(s.top()=='+'||s.top()=='-')
                p=1;
            else if(s.top()=='*'||s.top()=='/')
                p=2;
            else if(s.top()=='^')
                p=3;
            break;
        default:
            postfix+=infix[i];
            break;
        }
    }
    while(!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }
    return postfix;
}
