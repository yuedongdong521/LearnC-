//
//  learnClass.cpp
//  LearnC++
//
//  Created by lwj on 2018/4/28.
//  Copyright © 2018年 ydd. All rights reserved.
//

#include "learnClass.hpp"
using namespace std;

Box::Box(std::string name)
{
    cout << "Normal constructor allocating ptr" << endl;
    ptrName = new string;
    *ptrName = name;

    boxName = name;
    std::cout << "create name is "<< boxName <<" a Box" << std::endl;
    boxCount++;
}

Box::Box(const Box &obj) {
    boxCount++;
    // 为指针分配内存
    ptrName = new string;
    *ptrName = *obj.ptrName; // copy the value
    boxName = obj.boxName;
}

Box::~Box()
{
    std::cout << "name is "<< boxName<<" Box did delete"<< std::endl;
    delete ptrName;
}

double Box::getVolume()
{
    return length * breadth * height;
}

string Box::getBoxName()
{
    cout << "当前 boxName : "<< boxName <<" " << endl;
    return boxName;
}


void Box::setBoxPropertyValue(double l, double b, double h) {
    length = l;
    breadth = b;
    height = h;
}

int Box::compare(Box &box) {
//    在 C++ 中，每一个对象都能通过 this 指针来访问自己的地址。this 指针是所有成员函数的隐含参数。因此，在成员函数内部，它可以用来指向调用对象。
//    友元函数没有 this 指针，因为友元不是类的成员。只有成员函数才有 this 指针。
    return this->getVolume() > box.getVolume();
}

int Box::getBoxCount()
{
    return boxCount;
}

Box Box::operator+(const Box &b) {
    Box box("new");
    box.length = this->length + b.length;
    box.breadth = this->breadth + b.breadth;
    box.height = this->height + b.height;
    return box;
}


int Shape::area()
{
    cout << "parent class area" << endl;
    return 0;
}

void Shape::setWidth(int w) {
    widht = w;
}

void Shape::setHeight(int h) {
    height = h;
}

int PainCost::getCost(int area) {
    return area * 70;
}

int Rectangle::getArea()
{
    return widht * height;
}


