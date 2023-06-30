#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char s1[1000], s2[1000];
    int c1 = 0 ,c2 = 0 ,h ,l ,i ,j;
    cout << "Enter the string: ";
    cin >> s1 >> s2;
    for(i=0 ; s1[i]!='\0' ; i++){ c1++; }
    for(i=0 ; s2[i]!='\0' ; i++){ c2++; }

    if(c1 > c2)
        l = c2;
    else
        l = c1;

    for(i=0,j=0 ; i<l,j<l ; i++,j++)
        cout << s1[i] << s2[j];

    for(; i<c1 ; i++)
        cout << toupper(s1[i]);

    for(; j<c2 ; j++)
        cout << toupper(s2[j]);





}
