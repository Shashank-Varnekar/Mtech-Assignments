#include<iostream>
using namespace std;

int main()
{
    string str = "for msg in english there are twenty six keys, if you apply one after another on encrypted msg and observe txt one of the transformed txt is readable.";
    int arr[26] = {0};
    int n = str.length();
    for(int i=0; i<n; i++){
        arr[str[i] - 'a']++;
    }
    int k = 0;
    while(k<3){
        int max = arr[0];
        int pos = 0;
        char ch;
        for(int i=0; i<26; i++){
            if(max <= arr[i]){
                max = arr[i];
                pos = i;
            }
        }
        ch = pos + 'a';
        cout << ch << " occurs " << max << " times";
        arr[pos] = 0;
        k++;
        cout << endl;
    }
    return 0;
}