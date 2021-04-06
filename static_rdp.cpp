#include<bits/stdc++.h>

using namespace std;

int E();
int E1();
int match(char t);

char cur;
int pos = 0 ;
string line;
int main()
{
    // E is a start symbol.
    cin>>line;
    cur= line[pos];
    E();
    // if lookahead = $, it represents the end of the string
    // Here l is lookahead.
    if (cur == '$')
        printf("Parsing Done");
}
  
// Definition of E, as per the given production
int E()
{
    if (cur == 'i') {
        match('i');
        E1();
    }else if(cur=='$') return 0;
    return 1;
}
  
// Definition of E' as per the given production
int E1()   
{
    if (cur == '+') {
        match('+');
        match('i');
        E1();
    }else if(cur=='$') return 0;
        return 1;
}
  
// Match function
int match(char t)
{
    if (cur == t) {
        pos ++;
        cur =line[pos]; 
    }
    else
        printf("Error at pos %d",pos);
    return 0;
}
