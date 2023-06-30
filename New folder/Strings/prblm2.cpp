#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

int main(){
    string s , temp , str[1000];
    int len = 0, i;
    getline(cin , s);
    stringstream x(s);
    while(getline(x,temp,' '))
        str[len++] = temp;

    for(i=0 ; i<len-1 ; i++){
        if(str[i][str[i].length()-1] != str[i+1][0])
            cout << str[i] << endl;
        else
            str[i+1] = str[i+1]+str[i];
    }

    for(; i<len ; i++)
        cout << str[i];
}
