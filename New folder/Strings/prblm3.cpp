#include <bits/stdc++.h>
using namespace std;

int main(){
//    string temp, str1[1000], t, str2[1000] = NULL;
//    int len, j=0, c=0, n=0, k=0;
//    getline(cin,temp);
//    stringstream x(temp);
//    while(getline(x,t,' '))
//        str1[len++] = t;
//
//    for(int i=0 ; i<len ; i++){
//        int l = str1[i].length();
//        for(int j=0 ; j<l ; j++){
//            str2[k] += temp[n];
//            n = n+len-1;
//            k++;
//        }
//
//    }
//
//    for(int i=0 ; i<c ; i++)
//        cout << str2[i] << endl;


    string s;
    int len[1000], j=0, str_len = 0, str[1000];
    getline(cin,s);

    for(int i=0 ; s[i]!='\0' ; i++){
        if(s[i] == ' ')
            str_len++;
    }

    for(int i=0 ; i<=str_len ; i++){
        int c = 0;
        for(; s[j]!=' ' ; j++){
            c++;
        }
        len[i] = c;
        j++;
    }

    for(int i=0 ; i<=str_len ; i++){
        cout << len[i] << " ";
    }


    for(int i=0, j=str_len+1 ; s[i]!='\0'; i++){
        str[] = s[i];
        c++;
        if(c < len[]){
            str[] += s[j];
            j++;
            c++;
        }
    }





















}
