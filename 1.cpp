#include<bits/stdc++.h>
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
        //cout << value << " ";
        
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
    clock_t begin = clock();
    float time_spent = 0.0;
   
    srand(time(nullptr));
    for(int i=0; i<mi; i++){
        arr.push_back(rand());
    }
    //arr = {1,2,3,4,5,5,5,5,5,5};

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
    //cout << n << endl;
    
    roundOffDups(new_arr, n);
    cout << endl;
    /*for(int i=0; i<mi; i++){
        cout << arr[i] << " ";
    }
    cout << endl;*/
    int count2 = 0;
    for(int i=0; i<mi; i++){
        if(isDuplicate(arr[i], i)){
            count2++;
        }
    }
    cout << "Count after rounding : " << count2 << endl;

    clock_t end = clock();
    time_spent += (float)(end - begin) / CLOCKS_PER_SEC;
    cout << "The execution time taken by program is : " << time_spent << " seconds." << endl;
    return 0;
}