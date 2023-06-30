
#include<iostream>
using namespace std;

int main(){
    char s[100] = "madamn";
    int count;
    for(count=0 ; s[count]!='\0' ; count++){
    }
    for(int i=0,j=count-1 ; s[i] != '\0' ; i++,j--){
        if(s[i] != s[j]){
            cout << "Not A Palindrome!!";
            return 0;
        }
    }
    cout << "Palindrome";
    return 0;
}
