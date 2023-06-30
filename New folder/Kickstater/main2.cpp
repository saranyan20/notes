
#include <iostream>

using namespace std;

int main2()
{
    int r,c,f=1;
    cin >> r >> c;
    string s[r][c];
    for(int i=0 ; i<r ; i++){
        for(int j=0 ; j<c ; j++)
            cin >> s[i][j];
    }

    int row,col = 0;
    int num_check = 3;
    int star_check_1 = 1;
    int star_check_2 = 5;
    int space_count = 0;

    for(int i=1 ; i<=4 ; i++){

        for(int j=1 ; j<=4*c-1 ; j++){
            cout << "*";
            if(j%4 == 0)
                cout << " ";
        }

        cout << endl;

        for(int j=1 ; j<=4*c-1 ; j++){
            if(star_check_1 == j){
                cout << "*";
                star_check_1++;
            }
            else if(star_check_2 == j){
                cout << "*";
                star_check_2++;
            }
            else {
                cout << s[row][col];
                row++;
            }
        }
        col++;

        cout << endl;

        for(int j=1 ; j<=4*c-1 ; j++){
            cout << "*";
            if(j%4 == 0)
                cout << " ";
        }

        cout << endl << endl;

    }
    return 0;
}
