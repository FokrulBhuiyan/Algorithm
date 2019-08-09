#include <iostream>
using namespace std;

void Insertionsort (int array[], int low, int mid, int high) {

    for (int i = mid; i < high; i++) {
            int temp = array[i];
            int j = i-1;
        for ( ; j >= 0&&temp<array[j]; j--) {
                array[j+1]=array[j];
            }
        array[j+1]=temp;
        }
    }

void merge(int array[], int pivot, int mid, int high){
    int arr[high+1];
    int i = pivot, k = pivot, j = mid+1;

    while(i<=mid && j<=high){
        if(array[i] <= array[j]){
            arr[k] = array[i];
            i++;
        }
        else{
            arr[k] = array[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        arr[k] = array[i];
            k++;
            i++;
    }
    while(j<=high){
        arr[k] = array[j];
            k++;
            j++;
    }
    for(i = pivot; i<k;i++){
        array[i] = arr[i];
    }
}
void split (int array[], int low, int high) {
    if (low < high) {
        int mid = low+(high - low) / 2;
        split(array, low, mid);
        split(array,  mid+1, high);
        if ((high - low) > 10){
            merge(array, low, mid, high);
        } else {
            Insertionsort(array, low, mid, high);
        }

    }
}

int main()
{

    int num;
    cin >> num;

    int * array = new int [num];

    for (int i = 0; i < num; i++) {
        cin >> array[i];
    }
    split(array, 0, num-1);
    cout << "Your sorted numbers are: ";
    for (int i = 0; i < num; i++) {
        cout << array[i]<<" ";
    }
    delete[] array;

    return 0;

}
