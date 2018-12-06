//
//  learnTemplate.cpp
//  LearnC++
//
//  Created by lwj on 2018/5/2.
//  Copyright © 2018年 ydd. All rights reserved.
//

#include "learnTemplate.hpp"

template <class T>
void Stack<T>::push(T const & elem)
{
    // 追加转入元素的副本
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::pop():empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::top():empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();
}



