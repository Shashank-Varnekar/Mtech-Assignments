#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include <sys/time.h>
#define ll long long
using namespace std;

ll insertionSort(vector<int>arr, int n){
    int i, j, temp;
    ll count = 0;

    for (i = 1; i < n; ++i)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            count++;
            j--;
        }
        arr[j + 1] = temp;
    }
    return count;
}

int main()
{
    vector<int> arr;

    ifstream in;
    in.open("data.txt");
    if (!in)
    {
        cerr << "File can not open.";
        exit(1);
    }

    string line;
    while (getline(in, line))
        arr.push_back(stoi(line));
    
    cout << "Total numbers in dataset are : " << endl;
    cout << arr.size() << endl;
    int n = arr.size();
    /*for(int i=0; i<10; i++){
        cout << arr[i] << endl;
    }*/
    struct timeval starttime, endtime;
    long timedif, micro;

    // normal exponent with time 
    gettimeofday(&starttime, NULL);

    ll swaps = insertionSort(arr, n);
    cout << "Total swaps required to sort data using insertion sort are : " << endl;
    cout << swaps << endl;
    
    gettimeofday(&endtime, NULL);
    timedif = endtime.tv_sec - starttime.tv_sec;
    micro = timedif * 1000000 + endtime.tv_usec - starttime.tv_usec;
    cout << "Time taken : " << micro << " microseconds" << endl;
    return 0;
}