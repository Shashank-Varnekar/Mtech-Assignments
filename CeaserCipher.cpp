#include<iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter the message you want to encrypt: " << endl;
    cin >> str;
    int key = 3;
    int n = str.length();
    //encryption with Ceaser Cipher
    string encrypt = "";
    for(int i = 0; i<n; i++){
        int z = str[i] - 'a';
        int x = (z + key) % 26;
        encrypt[i] = x + 'a';
    }

    cout << "Encrypted Message: " << endl;
    for(int i = 0; i<n; i++){
        cout << encrypt[i];
    }
    cout << endl;

    //decryption of Ceaser Cipher
    string decrypt = "";
    for(int i = 0; i<n; i++){
        int z = encrypt[i] - 'a';
        int x = (z - key) % 26;
        decrypt[i] = x + 'a';
    }

    cout << "decrypted Message: " << endl;
    for(int i = 0; i<n; i++){
        cout << decrypt[i];
    }
    cout << endl;

    return 0;
}