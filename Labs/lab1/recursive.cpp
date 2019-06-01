//
//  recursive.cpp
//  lab1
//
//  Created by Sriyuth Sagi on 1/10/19.
//  Copyright © 2019 Sriyuth Sagi. All rights reserved.
//

#include <iostream>

int fib(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main(int argc, const char * argv[]) {
    
    int result = fib(atoi(argv[1]));
    std::cout << result << std::endl;
    return 0;
}
