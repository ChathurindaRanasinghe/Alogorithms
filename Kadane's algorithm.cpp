#include <bits/stdc++.h>
using namespace std;

int64_t a[300005] = {0};


//Kadane’s Algorithm:
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int64_t sum = 0,presum = INT64_MIN;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }


    for(int i=0;i<n;i++){
        sum += a[i];
        presum = max(presum,sum);
        if(sum < 0)
            sum = 0;
    }

    cout << presum << endl;


}
