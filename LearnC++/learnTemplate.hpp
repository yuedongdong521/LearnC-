//
//  learnTemplate.hpp
//  LearnC++
//
//  Created by lwj on 2018/5/2.
//  Copyright © 2018年 ydd. All rights reserved.
//

#ifndef learnTemplate_hpp
#define learnTemplate_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

template <class T>
class Stack {
private:
    std::vector<T> elems; // 元素
    
public:
    void push(T const&); // 入栈
    void pop(); //出栈
    T top() const; // 返回栈顶元素
    bool empty() const {  // 如果为空则返回真
        return elems.empty();
    }
};





#endif /* learnTemplate_hpp */
