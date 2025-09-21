#include <iostream>

int* hourglass_sum(int arr[][6], int n, int &size) {
    size = (n-2) * (n-2);
    int *hourglass = new int[size];
    int k = 0;
    for(int i=0;i<=n-3;i++) {
        for(int j=0;j<=n-3;j++) {
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] +
                arr[i+1][j+1] + 
                arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            hourglass[k++] = sum;
        }
    }
    return hourglass;
}

int find_max(int arr[], int n) {
    int max = arr[0];
    for(int i=0;i<n;i++) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

int main() {
    const int n = 6;
    int arr[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            std::cin>>arr[i][j];
        }
    }
    int s;
    int* hourglass_array = hourglass_sum(arr,n,s);
    std::cout<<"Sum of hourglasses: "<<'\n';
    for(int i=0;i<s;i++) {
        std::cout<<hourglass_array[i]<<" ";
    }
    std::cout<<'\n';
    int max_sum = find_max(hourglass_array,s);
    std::cout<<"Max hourglass: "<<max_sum<<'\n';
    delete[] hourglass_array;
    return 0;
}