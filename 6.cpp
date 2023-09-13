#include<iostream>
#include <sys/time.h>
#define ll long long
#define N 1000000007

using namespace std;

ll exponent(ll base, ll n){
    ll ans = 1;
    for(ll i=0; i<n; i++){
        ans *= base;
    }
    return ans;
}

ll bin_exponent(ll base, ll n){
    ll ans = 1;
    ll q , r;
    do{
        q = n / 2;
        r = n % 2;

        if(r == 1){
            ans = ans * base;
        }

        n = q;
        base = base*base;
    }while(q != 0);
     
    return ans;
}

ll sq_exponent(ll base, ll n){
    if (n == 0)
        return 1;
 
    if (n == 1)
        return base % N;
    
    ll temp = sq_exponent(base, n/2);
    temp = (temp * temp) % N;

    if (n % 2 == 0)
        return temp;
    else
        return ((base % N) * temp) % N;
}

int main()
{
    ll base, n;
    cout << "Enter base value and power value:" << endl; 
    cin >> base >> n;
    
    struct timeval starttime, endtime;
    long timedif, micro;

    // normal exponent with time 
    gettimeofday(&starttime, NULL);

    ll ans_1 = exponent(base, n); 
    cout << "Result is : " << ans_1 << endl;
    
    gettimeofday(&endtime, NULL);

    timedif = endtime.tv_sec - starttime.tv_sec;
    micro = timedif * 1000000 + endtime.tv_usec - starttime.tv_usec;
    cout << "Time taken : " << micro << " microseconds" << endl;

    gettimeofday(&starttime, NULL);

    ll ans_2 = bin_exponent(base, n); 
    cout << "Result is : " << ans_2 << endl;
    
    gettimeofday(&endtime, NULL);

    timedif = endtime.tv_sec - starttime.tv_sec;
    micro = timedif * 1000000 + endtime.tv_usec - starttime.tv_usec;
    cout << "Time taken : " << micro << " microseconds" << endl;

    gettimeofday(&starttime, NULL);

    ll ans_3 = sq_exponent(base, n); 
    cout << "Result is : " << ans_3 << endl;
    
    gettimeofday(&endtime, NULL);

    timedif = endtime.tv_sec - starttime.tv_sec;
    micro = timedif * 1000000 + endtime.tv_usec - starttime.tv_usec;
    cout << "Time taken : " << micro << " microseconds" << endl;

    return 0;
}