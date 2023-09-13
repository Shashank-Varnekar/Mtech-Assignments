#include<bits/stdc++.h>
#include<sys/time.h>
#include<ctime>
#include<unistd.h>
#include <iostream>
#include <fstream>
#define mi 10000

using namespace std;

vector<int> arr;
vector<int> new_arr;

//funcion to check duplicates O(n)
bool isDuplicate(int value, int endIndex) {
    for (int j = 0; j < endIndex; ++j) {
        if (arr[j] == value) {
            return true;
        }
    }
    return false;
}

//function to round off duplicate element to its nearest free value
void roundOffDups(vector<int> new_arr, int n){
    for(int i=0; i<n; i++){
        int value = arr[new_arr[i]];

        int left = value - 1;
        int right = value;

        while(isDuplicate(left, mi)) left--;
        while(isDuplicate(right, mi)) right++;

        if(left > 0){
            if(abs(value - left) <= abs(value - right)){
                arr[new_arr[i]] = left;
            }
            else{
                arr[new_arr[i]] = right;
            }
        }
        else{
            arr[new_arr[i]] = right;
        }
    }
}




int main()
{
    struct timeval starttime, endtime;
    long sec, micro;
    gettimeofday(&starttime, NULL);

    srand(time(nullptr));
    for(int i=0; i<mi; i++){
        arr.push_back(rand());
    }
    
   
    int count = 0;
    // finding no of duplicates in O(n * n)    
    for (int i = 0; i < mi; ++i) { //O(n)
        if (isDuplicate(arr[i], i)) { // function call to check is no is already present in array of not; O(n)
            new_arr.push_back(i); 
            count++;
        }
    }
    cout << "The total number of duplicates present in dataset is : " << count << endl;


    int n = new_arr.size();
       
    roundOffDups(new_arr, n);
    cout << endl;
    
    int count2 = 0;
    for(int i=0; i<mi; i++){
        if(isDuplicate(arr[i], i)){
            count2++;
        }
    }
    cout << "Count after rounding : " << count2 << endl;
    gettimeofday(&endtime, NULL);

    sec = endtime.tv_sec - starttime.tv_sec;
    micro = sec * 1000000 + endtime.tv_usec - starttime.tv_usec;

    cout << "Time taken : " << sec << " seconds, " << micro << " microseconds" << endl; 

    fstream file;
    file.open("data.txt",ios_base::out);
 
    for(int i=0;i<mi;i++)
    {
        file<<arr[i]<<endl;
    }
 
    file.close();

    return 0;
}