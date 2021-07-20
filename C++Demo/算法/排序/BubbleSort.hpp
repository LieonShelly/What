//
//  BubbleSort.hpp
//  C++Demo
//
//  Created by lieon on 2021/7/19.
//  Copyright © 2021 lieon. All rights reserved.
//

#ifndef BubbleSort_hpp
#define BubbleSort_hpp

#include <stdio.h>
#include <iostream>

struct BubbleSort {
    
    static void soort() {
        int arrayLen = 8;
        int array[8] = {1, 2, 3, 4, 5 ,6, 7, 8};
        for (int end = arrayLen - 1; end > 0; end--) {
            bool sorted = true;
            for (int begain = 1; begain <= end; begain++) {
                if (array[begain] < array[begain-1]) {
                    int temp = array[begain];
                    
                    array[begain] = array[begain - 1];
                    array[begain - 1] = temp;
                    sorted = false;
                }
            }
            // 完全有序，直接跳出
            if (sorted) {
                break;
            }
        }
        for (int index = 0; index < arrayLen; index++) {
            std::cout << array[index] << std::endl;
        }
        
    }
};

#endif /* BubbleSort_hpp */
