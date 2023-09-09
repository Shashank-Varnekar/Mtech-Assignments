#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string str;
    cout << "Enter the message you want to encrypt: " << endl;
    getline(cin, str);

    //Encryption with columnar transposition Cipher
    int n = str.length();
    while(n % 5 != 0){
        str = str + 'x';
        n += 1;
    }
    char mat[5][5]; 
    int x = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            mat[i][j] = str[x];
            x++;
        }
    }
    string en_str = "";
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            en_str = en_str + mat[j][i];
        }
    }
    cout << "The encrypted message is : ";
    int itr = 0;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << en_str[itr];
            itr++;
        }
        cout << " ";
    }
    cout << endl;

    // Decryption
    string de_str = "";
    for(int j=0; j<5; j++){
        for(int i=0; i<5; i++){
            de_str = de_str + mat[j][i];
        }
    }
    cout << "The decrypted message is : ";
    cout << de_str << endl;
    return 0;
}