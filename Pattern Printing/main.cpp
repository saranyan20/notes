#include <iostream>
#include <math.h>
using namespace std;
int main() {
    long long int n, i=0, rev=0, len=0;
    cin >> n;
    while(n!=0){
        int rem = n%10;
        rev = rev*10 + rem;
        len++;
        n/=10;
    }
    int m = rev, l = len;
    for(int i=1 ; i<=l*l ; i++){
        int rem = rev%10;
        cout << rem*pow(10,len-1) << " ";
        rev /= 10;
        if(i%l == 0) {
            rev = m;
            len--;
            cout << endl;
        }
    }
    return 0;
}


//#include <iostream>
//using namespace std;
//
//
//int main(){
//    int n, j;
//    char ch;
//    cin >> n >> ch;
//
//    for(int i=n, ct=1 ; i>=1 ; i--,ct++){
//        for(int j=n ; j>i ; j--)
//            cout << " ";
//        if(ct%2 == 1){
//            for(int j=1 ; j<=i ; j++){
//                cout << j << " ";
//                if(j != i) cout << ch << " ";
//            }
//        }
//        else {
//            for(int j=i ; j>=1 ; j--){
//                cout << j << " ";
//                if(j!=1) cout << ch << " ";
//            }
//        }
//        cout << endl;
//    }
//    return 0;
//}
