//to find rank k element of an array
//used whole randomized quick sort so tc=> O(n log n)

#include <bits/stdc++.h>
using namespace std;


int Partition(int arr[], int p, int r){
    int x = arr[r];
    int i = p - 1;
    int j;

    for(j = p; j <= r - 1; ++j){
        
        if(arr[j] <= x){
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}



int Randomized_Partition(int arr[], int p, int r){
    srand(time(NULL));
    int i = p + rand() % (r - p + 1);
    
    swap(arr[i], arr[r]);

    return Partition(arr, p, r);

}

void QS(int arr[], int p, int r){
    
    if(p < r){
        int q = Randomized_Partition(arr, p, r);
        QS(arr, p, q - 1);
        QS(arr, q + 1, r);
    }
}

int main(){

    int n;
    cout << "Enter no. of element in a array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array's elements: ";
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int k;
    cout << "Enter k = ";
    cin >> k;

    QS(arr, 0, n - 1);

    cout << "Sorted array: ";

    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    
    cout << "\nRank " << k << " element = " << arr[k];


    return 0;
}
