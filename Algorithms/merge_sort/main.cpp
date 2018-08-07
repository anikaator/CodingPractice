#include <iostream>
#include <random>

using namespace std;

void merge_half(int arr[], int start, int mid, int end) {
    int fin_arr[10];
    int tmp_mid = mid + 1;
    int cnt = start;
    int init = start;
    printf("\nMerge start : %d Mid : %d End : %d\n",start, tmp_mid, end);
    for (int i = start; i <= end; ++i) {
        cout << "-->" << arr[i];
    }
    while(start <= mid && tmp_mid <= end){
        if (arr[start] <= arr[tmp_mid])
            fin_arr[cnt++] = arr[start++];
        else if (arr[start] > arr[tmp_mid])
            fin_arr[cnt++] = arr[tmp_mid++];
    }

    while(start <= mid)
        fin_arr[cnt++] = arr[start++];
    while(tmp_mid <= end)
        fin_arr[cnt++] = arr[tmp_mid++];

    cout << "\nAfter merging looks like :\n";
    for (int i = init; i < cnt; ++i) {
        cout << "-->" << fin_arr[i];
        arr[i] = fin_arr[i];
    }
    cin.get();
}

void merge_sort(int arr[], int start, int end) {

    int mid = (end + start)/2;
    printf("\nStart : %d Mid : %d End : %d\n",start, mid, end);
    if(start >= end) {
        return;
    }

    for (int i = start; i <= end; ++i) {
        cout << "-->" << arr[i];
    }
    cin.get();
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge_half(arr, start,mid, end);
}

int main() {

    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = (rand()%100);
    }
    merge_sort(arr, 0, 9);
    cout << "\n Final result :\n";
    for (int i = 0; i < 10; ++i) {
        cout << "-->" << arr[i];
    }
    return 0;
}

