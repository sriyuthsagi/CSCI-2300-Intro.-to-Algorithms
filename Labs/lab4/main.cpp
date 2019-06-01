//
//  main.cpp
//  lab4
//
//  Created by Sriyuth Sagi on 4/2/19.
//  Copyright © 2019 Sriyuth Sagi. All rights reserved.
//

#include<iostream>
#include<vector>
#include <stdlib.h>
#include <time.h>
using namespace std;


vector<int> longestPalSubseq(vector<int> &in) {
    
    vector<int> rev = in;
    reverse(rev.begin(), rev.end());
    
    vector<vector<int> > L(in.size()+1, vector<int>(rev.size()+1));
    
    for (int i=1; i<=in.size(); i++) {
        for (int j=1; j<=rev.size(); j++) {
            if (in[i-1] == rev[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
            } else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
            }
        }
    }
    
    int index = L[in.size()][rev.size()];
    
    vector<int> lcs(index);
    
    int i = (int)in.size();
    int j = (int)rev.size();
    while (i > 0 && j > 0) {
        if (in[i-1] == rev[j-1]) {
            lcs[index-1] = in[i-1];
            i--;
            j--;
            index--;
        }
        else if (L[i-1][j] > L[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    lcs.push_back(L[in.size()][rev.size()]);
    return lcs;
}





int knapSack1(vector<pair<int, int>> A, int W) {
    
    vector<float> ratio;
    vector<int> weight;
    vector<int> value;
    for (int i = 0; i < A.size(); i++) {
        ratio.push_back(A[i].second / A[i].first);
        weight.push_back(A[i].first);
        value.push_back(A[i].second);
    }
    float min_idx;
    for (int i = 0; i < ratio.size()-1; i++) {
        min_idx = i;
        for (int j = i+1; j < ratio.size(); j++) {
            if (ratio[j] < ratio[min_idx]) {
                min_idx = j;
            }
        }
        
        swap(ratio[i], ratio[min_idx]);
        swap(weight[i], weight[min_idx]);
        swap(value[i], value[min_idx]);
    }
    
    int knap = 0;
    int i = 0;
    while (W > 0 && i < ratio.size()) {
        if (weight[i] < W) {
            knap += value[i];
            W -= weight[i];
        }
        i++;
        
    }
    return knap;
}


int knapSack2(vector<pair<int, int>> A, int W) {
    
    vector<vector<int> > K(W+1, vector<int>(A.size()+1));
    
    for (int j = 1; j <= A.size(); j++) {
        for (int w = 1; w <= W; w++) {
            if (A[j-1].first > w) {
                K[w][j] = K[w][j-1];
            } else {
                K[w][j] = max(A[j-1].second + K[w-A[j-1].first][j-1],  K[w][j-1]);
            }
        }
    }
    
    return K[W][A.size()];
}








int main() {
    vector<int> test1 = {7, 2, 4, 6, 9, 11, 2, 6, 10, 6, 15, 6, 14, 2, 7, 5, 13, 9, 12, 15};
    vector<int> res1 =  longestPalSubseq(test1);
    for (int i = 0; i < res1.size(); i++) {
        cout << res1[i] << ' ';
    }
    cout << endl << endl;
    
    vector<int> test2;
    srand ((unsigned int)time(NULL));
    for (int i = 0; i < 1000; i++) {
        test2.push_back(rand() % 100 + 1);
    }
    vector<int> res2 =  longestPalSubseq(test2);
    for (int i = 0; i < res2.size(); i++) {
        cout << res2[i] << ' ';
    }
    cout << endl << endl;
    
    
    
    
    
    vector<pair<int, int>> test3 = {{96,91}, {96, 92}, {96, 92}, {97, 94}, {98, 95}, {100, 94}, {100, 96}, {102, 97}, {103, 97}, {104, 99}, {106, 101}, {107, 101}, {106, 102}, {107, 102}, {109, 104}, {109, 106}, {110, 107}, {111, 108}, {113, 107}, {114, 110}};
    cout << knapSack1(test3, 100) << endl;
    cout << knapSack1(test3, 200) << endl;
    cout << knapSack1(test3, 300) << endl << endl;
    
    cout << knapSack2(test3, 100) << endl;
    cout << knapSack2(test3, 200) << endl;
    cout << knapSack2(test3, 300) << endl << endl;
    
    
    
    
    
    return 0;
}
