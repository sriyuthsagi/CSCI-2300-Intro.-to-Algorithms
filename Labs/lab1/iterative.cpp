//
//  main.cpp
//  lab1
//
//  Created by Sriyuth Sagi on 1/10/19.
//  Copyright © 2019 Sriyuth Sagi. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int n = atoi(argv[1]);
    int result = 0;
    
    for (int i = 0; i < 1000000; i++) {
        if (n == 0) {
            result = 0;
        }
        int arr[n];
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        result = arr[n];
    }
    
    std::cout << result << std::endl;
    return 0;
}
