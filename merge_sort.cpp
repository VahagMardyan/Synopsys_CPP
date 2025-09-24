#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int l = mid - left + 1;
    int r = right - mid;
    
    std::vector<int> L(l), R(r);

    for(size_t i = 0;i < l; i++) {
        L[i] = arr[left + i];
    }

    for(size_t j = 0; j<r; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while(i < l && j < r) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < l) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < r) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(std::vector<int>& arr, int start, int end) {
    if(start >= end) {
        return;
    }   
    int mid = (start + end) / 2;
    merge_sort(arr,start,mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main() {
    std::vector<int>x = {1,2,3,8,9};
    int n = x.size();
    merge_sort(x, 0, n-1);
    for(size_t i=0;i<n;i++) {
        std::cout<<x[i]<<" ";
    }
    std::cout<<'\n';
    return 0;
}