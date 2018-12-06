//
//  lenarn1.cpp
//  LearnC++
//
//  Created by lwj on 2018/4/26.
//  Copyright © 2018年 ydd. All rights reserved.
//

#include "lenarn1.hpp"

Delay::Delay(int time)
{
    std::clock_t now = clock();
    while (((clock() - now)) / 1000.0 < time) {
//        std::cout << clock() - now << std::endl;
    }
}

Delay::~Delay()
{
    std::cout << "~Delay" << std::endl;
}

void Delay::delaySec(int time)
{
    std::clock_t now = clock();
    while (clock() - now < time * 1000) {
        
    }
}
