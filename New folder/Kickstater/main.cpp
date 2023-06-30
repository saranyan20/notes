
#include <iostream>

using namespace std;

int main()
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
            if(j%4 == 0)
                cout << " ";
            else
                cout << "*";
        }

        cout << endl;

        row=0;
        for(int j=1 ; j<=4*c-1 ; j++){
            if(j%4 == 0)
                cout << " ";
            else if(j%2 == 0)
                cout << s[row++][col];
            else
                cout << "*";
        }
        col++;

        cout << "\n";

        for(int j=1 ; j<=4*c-1 ; j++){
            if(j%4 == 0)
                cout << " ";
            else
                cout << "*";
        }

        cout << endl << endl << endl;

    }
    return 0;
}
