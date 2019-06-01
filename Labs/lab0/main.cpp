//
//  main.cpp
//  lab0
//
//  Created by Sriyuth Sagi on 1/10/19.
//  Copyright © 2019 Sriyuth Sagi. All rights reserved.
//

#include <iostream>

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        } else {
            return binarySearch(arr, mid + 1, r, x);
        }
    }
    
    return -1;
}

int findMissing(int arr[], int n) {
    
    int remainder = (n * (n + 1)) / 2;
    
    for (int i = 0; i < n - 1; i++) {
        remainder-= arr[i];
    }
    
    return remainder;
}

int main(int argc, const char * argv[]) {
    
    // binary search
    int arr1[] = { 2, 3, 4, 10, 40 };
    int arr1_size = 5;
    
    int result1 = binarySearch(arr1, 0, arr1_size - 1, 10);
    
    if (result1 == -1) {
        std::cout << "element not present" << std::endl;
    } else {
        std::cout << "element present at " << result1 << std::endl;
    }
    
    // find missing number
    int arr2[] = { 3, 7, 6, 5, 2, 1};
    int arr2_size = 6;
    int n = arr2_size + 1;
    
    int result2 = findMissing(arr2, n);
    
    std::cout << "element missing is " << result2 << std::endl;
    
    
    return 0;
}
