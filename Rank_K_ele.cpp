//to find rank k element of an array
//used randomized partition and partition function of randomized quick sort so tc=> O(n)

#include <bits/stdc++.h>
using namespace std;

int Partition(int arr[], int p, int r){
    int x = arr[r];
    int i = p;
    
    for(int j = p; j < r; ++j){
        if(arr[j] <= x){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[r], arr[i]);
    return i;
}

int Randomized_Partition(int arr[], int p, int r){
    int i = p + rand() % (r - p + 1);
    //cout << "i = " << i << endl ;
    swap(arr[i], arr[r]);

    return Partition(arr, p, r);
}

int Kth_Rank_ele(int arr[], int p, int r, int k){
    int q = Randomized_Partition(arr, p, r);
    //cout << "q = " << q << endl;

    if(q == k){
        return arr[k];
    }
    else{
        if(k < q){
            //cout << "<" << p << "_" << q - 1 << "_" << k << endl;
            Kth_Rank_ele(arr, p, q - 1, k);
        }
        else{
            //cout << ">" << q + 1 << "_" << r << "_" << k - q << endl;
            Kth_Rank_ele(arr, q + 1, r, k - q);
        }
    }
}

int main(){
    int n;
    cout << "Enter size of an array:";
    cin >> n;

    int arr[n];
    cout << "Enter elements of an array:";
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int k;
    cout << "Enter which rank element you want: ";
    cin >> k;

    srand(time(NULL));

    int element = Kth_Rank_ele(arr, 0, n - 1, k);

    cout << "Rank " << k << " element is : " << element << endl;
    return 0;

}

