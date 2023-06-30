#include <bits/stdc++.h>
using namespace std;

void str_upper(string s){
    for(int i=0 ; s[i]!='\0' ; i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            cout << s[i];
    }
}

void str_lower(string s){
    for(int i=0 ; s[i]!='\0' ; i++){
        if(s[i] >= 'a' && s[i] <= 'z')
            cout << s[i];
    }
}

int main(){
    string s;
    int upper_count=0, lower_count=0;
    cin >> s;
    for(int i=0 ; s[i]!='\0' ; i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            upper_count++;
        else
            lower_count++;
    }

    if(upper_count > lower_count){
        str_lower(s);
        str_upper(s);
    } else {
        str_upper(s);
        str_lower(s);
    }

}
