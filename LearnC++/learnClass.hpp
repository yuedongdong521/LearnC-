//
//  learnClass.hpp
//  LearnC++
//
//  Created by lwj on 2018/4/28.
//  Copyright © 2018年 ydd. All rights reserved.
//

#ifndef learnClass_hpp
#define learnClass_hpp

#include <stdio.h>
#include <iostream>
#include <string>

class Box {
    double length;  // 长
    double breadth; // 宽
    double height;  // 高
    std::string *ptrName;
protected:
    std::string boxName;
public:
    
    Box(std::string name); // 简单构造函数
    Box(const Box &obj);   // 拷贝构造函数
    ~Box();                // 析构函数
    // 成员函数
    double getVolume(void);
    std::string getBoxName();
    void setBoxPropertyValue(double l, double b, double h);
    // 友元函数 类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。
    // 使用关键字 friend 定义友元函数
    friend void printWidth(Box &box);
    
    int compare(Box &box);
    
//    我们可以使用 static 关键字来把类成员定义为静态的。当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。
//    静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。我们不能把静态成员放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化
//    如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。静态成员函数即使在类对象不存在的情况下也能被调用，静态函数只要使用类名加范围解析运算符 :: 就可以访问。
//    静态成员函数只能访问静态数据成员，不能访问其他静态成员函数和类外部的其他函数。
//    静态成员函数有一个类范围，他们不能访问类的 this 指针。您可以使用静态成员函数来判断类的某些对象是否已被创建。
    static int boxCount;
    static int getBoxCount();
    
    Box operator+(const Box& b);
};

// 继承
class Shape {
    
public:
    void setWidth(int w);
    void setHeight(int h);
    int area();
protected:
    int widht;
    int height;
};

class PainCost {
    
public:
    int getCost(int area);
};


class Rectangle : public Shape, public PainCost {

public:
    int getArea();
    
};

#endif /* learnClass_hpp */
