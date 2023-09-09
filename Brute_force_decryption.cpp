#include<iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter message you want to decrypt: " << endl;
    getline(cin, str);
    //cout << str << endl;
    int n = str.length();
    for(int i=0; i<n; i++){
        if(str[i] == ' ')
            str[i] = ' ';
        else
            str[i] = tolower(str[i]);
    }
    int key = 1;
    char decrypt[n];
    while(key < 27){
        for(int i=0; i<n; i++){
            if(isalpha(str[i])){
                decrypt[i] = char(int(str[i] + key - 97) % 26 + 97);
            }
            else{
                decrypt[i] = str[i];
            }
        }
        cout << "For key: "<< key << " Decryption is: ";
        for(int i=0; i<n; i++){
            cout << decrypt[i];
        }
        cout << endl;
        key++;
    }
    return 0;
}