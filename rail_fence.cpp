#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string str;
    cout << "Enter the message you want to encrypt: " << endl;
    getline(cin, str);

    //Encryption with Rail fence Cipher
    int n = str.length();
    if(n % 2 != 0){
        str = str + 'x';
        n += 1;
    }
    int m = n/2;
    char mat[2][m]; // depth is 2 : i is 2
    int k = 0;
    int i = 0;
    while(i < 2){
        if(i == 0) k = 0;
        else k = 1;
        for(int j=0; j<m; j++){
            mat[i][j] = str[k];
            k = k + 2;
        }
        i++;
    }
    string en_str = "";
    for(int i=0; i<2; i++){
        for(int j=0; j<m; j++){
            en_str = en_str + mat[i][j];
        }
    }
    cout << "The encrypted message is : ";
    cout << en_str << endl;

    // Decryption of rail fence cipher
    string de_str = "";
    for(int j=0; j<m; j++){
        for(int i=0; i<2; i++){
            de_str = de_str + mat[i][j];
        }
    }
    cout << "The decrypted message is : ";
    cout << de_str << endl;
    return 0;
}