//
//  main.cpp
//  lab3
//
//  Created by Sriyuth Sagi on 3/3/19.
//  Copyright © 2019 Sriyuth Sagi. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace chrono;



int alg1(vector<int> A, int k) {
    srand((int)time(nullptr));
    int v = A[rand()%A.size()];
    vector<int> left;
    vector<int> center;
    vector<int> right;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == v) {
            center.push_back(A[i]);
        } else if (A[i] < v) {
            left.push_back(A[i]);
        } else {
            right.push_back(A[i]);
        }
    }
    
    if (k <= left.size()) {
        return alg1(left, k);
    } else if (k <= left.size() + center.size()) {
        return v;
    } else {
        return alg1(right, k - (int)left.size() - (int)center.size());
    }
    
}




int alg2(vector<int> A, int k) {
    
    if (A.size() <= 10) {
        sort(A.begin(), A.end());
        
        return A[k-1];
    }
    
    vector<int> small;
    for (int i = 0; i < A.size()/5; i++) {
        vector<int> temp;
        temp.push_back(A[(i*5)]);
        temp.push_back(A[(i*5)+1]);
        temp.push_back(A[(i*5)+2]);
        temp.push_back(A[(i*5)+3]);
        temp.push_back(A[(i*5)+4]);
        small.push_back(alg2(temp, 3));
    }
    
    
    
    int v = alg2(small, (int)small.size()/2);
    vector<int> left;
    vector<int> center;
    vector<int> right;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == v) {
            center.push_back(A[i]);
        } else if (A[i] < v) {
            left.push_back(A[i]);
        } else {
            right.push_back(A[i]);
        }
    }
    
    if (k <= left.size()) {
        return alg2(left, k);
    } else if (k <= left.size() + center.size()) {
        return v;
    } else {
        return alg2(right, k - (int)left.size() - (int)center.size());
    }
}


void quicksort(vector<int>& A, int lower, int upper) {
    
    if (lower < upper) {
        
        int mid = (lower - 1);
        for (int i = lower; i < upper; i++) {
            if (A[i] <= A[upper]) {
                mid++;
                int j = A[mid];
                A[mid] = A[i];
                A[i] = j;
            }
        }
        int j = A[mid+1];
        A[mid+1] = A[upper];
        A[upper] = j;
        
        
        
        quicksort(A, lower, mid);
        quicksort(A, mid + 2, upper);
    }
}


int alg3(vector<int> A, int k) {
    
    
    quicksort(A, 0, (int)A.size()-1);
    
    
    return A[k-1];
}


int main(int argc, const char * argv[]) {
    
    vector<int> A = {7, 2, 4, 6, 9, 11, 2, 6, 10, 6, 15, 6, 14, 2, 7, 5, 13, 9, 12, 15};
    int k = 10;
    
    cout << alg1(A, k) << endl;
    cout << alg2(A, k) << endl;
    cout << alg3(A, k) << endl;
    cout << endl;
    
    vector<int> longlist;
    
    srand((int)time(nullptr));
    for (int i = 0; i < 10000000; i++) {
        longlist.push_back(rand()%100000);
    }
    
    
    auto start = high_resolution_clock::now();
    cout << alg1(longlist, 5000000) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    
    
    
    start = high_resolution_clock::now();
    cout << alg2(longlist, 5000000) << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    
    
    
    start = high_resolution_clock::now();
    cout << alg3(longlist, 5000000) << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;
    
    return 0;
}
