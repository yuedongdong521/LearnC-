//
//  main.cpp
//  LearnC++
//
//  Created by lwj on 2018/4/26.
//  Copyright © 2018年 ydd. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

#include "lenarn1.hpp"
#include "lenarnStruct.hpp"
#include "learnClass.hpp"
#include "learnFileAndStream.hpp"
#include "learnTemplate.hpp"
#include "learnPthread.hpp"

#define cLong(content) std::cout << __FILE__ << "line ("<< __LINE__ <<") " << " " << __TIME__ << " " << content << std::endl;
#define myclong(content, pra) std::cout << content << pra << std::endl

using namespace std;

// int 转 字符串
std::string itos(int i) {
    std::stringstream s;
    s << i;
    return s.str();
}

void inputYourName()
{
    std::string strinfo = "Please input your name:";
    std::cout << strinfo;
    std::cin >> strinfo;
    if (strinfo == "winter") {
        std::cout << "you are winter!" << std::endl;
    } else if (strinfo != "wende") {
        std::cout << "you are not wende!" << std::endl;
    } else if (strinfo > "winter") {
        std::cout << "your name should be ahead of winter" << std::endl;
    } else {
        std::cout << "your name should be after of winter"  << std::endl;
        strinfo += ", Welcome to China!";
        std::cout << strinfo << std::endl;
        std::string strtmp = "How are you? " + strinfo;
        for (int i = 0; i < strtmp.size(); i++) {
            std::string stri = itos(i);
            std::cout << stri + strtmp[i];
        }
    }
    
}

int getrandNum(int min, int max)
{
    return rand()%(max - min) + min;
}

void learnChar()
{
    char str1[6] = "hello";
    char str2[10] = "world";
    char str3[10];
    int len;
    
    // 复制 str1到str3
    strcpy(str3, str1);
    std::cout << "strcpy(str3, str1): " << str3 << std::endl;
    
    // 拼接 str1与 str2
    strcat(str1, str2);
    std::cout << "strcat(str1, str2): " << str1 << std::endl;
    
    len = strlen(str1);
    
    std::cout << "strlen(str1): " << len << std::endl;
    std::cout << "strlen(str3): " << strlen(str3) << std::endl;
}

void lenarnString()
{
    std::string str1 = "hello";
    std::string str2 = "world";
    std::string str3;
    
    str3 = str1;
    std::cout << "str3 = str1 : " << str3 << std::endl;
    
    str3 = str1 + str2;
    std::cout << "str1 + str2 : " << str3 << "str1 : " << str1  << std::endl;
    

}

void learnPointer () {
    
    char c[] = "hello";
    char *p;
    p = &c[0];
    
    std::cout << "c[0] : " << c[0] << std::endl;
    std::cout << "var value p : " << p << std::endl;
    std::cout << "var pointer *p :" << *p << std::endl;
    std::cout << "var address &p :" << &p << std::endl;
    std::cout << "var address c[0] :" << &c[0] << std::endl;
    
    
    int i = 20;
    int *pi = &i;
    
    std::cout << "i : " << i << std::endl;
    std::cout << "var value pi : " << pi << std::endl;
    std::cout << "var pointer *pi :" << *pi << std::endl;
    std::cout << "var address &pi :" << &pi << std::endl;
    
    
}

void learnNULL()
{
    int *p1 = NULL;
    if (!p1) {
        std::cout << "*p1 假: " << std::endl;
    }
    std::cout << "*p1 : " << p1 << std::endl;
    
    int *p2 = 0;
    if (!p2) {
       std::cout << "*p2 假: " << std::endl;
    }
    std::cout << "*p2 : " << p2 << std::endl;
    
}

void sum(int a, int b, int *c)
{
    *c = a + b;
    a++;
}

float avg(int *arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum = sum + arr[i];
    }
    return sum * 1.0 / len;
}

void learnPointerArithmetic()
{
    int var[] = {10, 100, 200};
    int *ptr = NULL;

    ptr = var;
    for (int i = 0; i < 3; i++) {
        std::cout << "Address of var[" << i << "] = " << ptr << std::endl;
        std::cout << "value of var[" << i << "] = " << *ptr << std::endl;
        ptr++;
    }
    
    std::cout << "指针递减" << std::endl;
    ptr = &var[2];
    for (int i = 2; i >= 0; i--) {
        std::cout << "Address of var[" << i << "] = " << ptr << std::endl;
        std::cout << "value of var[" << i << "] = " << *ptr << std::endl;
        ptr--;
    }
    
    cLong("指针关系运算");
    int i = 0;
    ptr = var;
    while (*ptr <= var[2]) {
        myclong("Address of var [" << i <<"] = ", ptr);
        myclong("value of var [" << i <<"] = ", *ptr);
        ptr++;
        i++;
    }

    int j = 10000;
    int *jp = &j;
    int **jpp = &jp;
    myclong(" value *jp = ", *jp);
    myclong(" address *jp = ", jp);
    myclong(" value **jpp = ", **jpp);
    myclong(" address *jpp = ", *jpp);
    myclong(" address jpp = ", jpp);
    int a = 100, b = 20;
    int c;
    sum(a, b, &c);
    myclong("sum c = ", c);
    myclong("a = ", a);
    
    float v = avg(var, 3);
    myclong("avg = ", v);
}

int * getRandom ()
{
    static int r[3];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 3; i++) {
        r[i] = rand();
        myclong("r["<<i<<"] = ", r[i]);
    }
    return r;
}


void swap(int& a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

double darr[] = {2.1, 2.3, 4.5};
double& setDarrValue(int i) {
    return darr[i];
}

void learnRerence () {
    int a = 6, b = 9;
    cLong("swap 之前 a = "<<a<<", b = "<<b<<"");
    swap(a, b);
    cLong("swap 之后 a = "<<a<<", b = "<<b<<"");
    
    setDarrValue(0) = 1024.00;
    setDarrValue(2) = 666.6;
    setDarrValue(3) = 3;
    for (int i = 0; i < 4; i++) {
        cLong("darr["<<i<<"] = "<<darr[i]<<"");
    }
}


void printBooks(struct Books& book)
{
    cLong("books title "<<book.title<<"");
    cLong("books author "<<book.author<<"");
    cLong("books subject "<<book.subject<<"");
    cLong("books id "<<book.book_id<<"");
}

void prtBooks(struct Books *book) {
    cLong("books title "<<book->title<<"");
    cLong("books author "<<book->author<<"");
    cLong("books subject "<<book->subject<<"");
    cLong("books id "<<book->book_id<<"");
}

void lenarnStruct()
{
    struct Books books;
    std::strcpy(books.title, "learn c++ Programming");
    std::strcpy(books.author, "ydd");
    strcpy(books.subject, "C++ programing");
    books.book_id = 996;
    printBooks(books);
}

// 初始化类 Box 的静态成员
int Box::boxCount = 0;

// 继承
void textCarryClass ()
{
    Rectangle rec;
    rec.setHeight(4);
    rec.setWidth(3);
    int cost = rec.getCost(rec.getArea());
    cLong("cost = "<< cost <<"");
    
}

void learnClass()
{
    Box box1("ydd");
    box1.setBoxPropertyValue(10.9, 8.8, 12.5);
    double v = box1.getVolume();
    cLong("box1 v = "<< v <<"");
    box1.getBoxName();
    Box box2(box1);
    box2.getBoxName();
    printWidth(box2);
    
    Box box3("wyy");
    box3.setBoxPropertyValue(10.8, 9.9, 11.1);
    int result = box3.compare(box1);
    if (result == 0) {
        cLong(""<< box3.getBoxName() <<" > "<< box1.getBoxName() <<"");
    } else {
        cLong(""<< box3.getBoxName() <<" <= "<< box1.getBoxName() <<"");
    }
    
    // 指向类的指针,通过成员访问运算符(->)来访问成员
    Box *ptrBox;
    ptrBox = &box1;
    ptrBox->getBoxName();
    
    ptrBox = &box3;
    ptrBox->getBoxName();
    cLong(" 类的静态成员 boxCount = "<< Box::boxCount <<"");
    cLong(" 类的静态成员 boxCount = "<< Box::getBoxCount() <<"");
    
    textCarryClass();
    
    Box box4 = box1 + box2;
    cLong(" 重载+运算符 box4 name :"<< box4.getBoxName() <<" v = "<< box4.getVolume() <<"");
}

void learnFrielAndStream ()
{
    FileAndStream file;
    file.testFileAndStream();
}

void printWidth(Box &box)
{
    cLong("Box 友元函数 "<< box.boxName <<"");
}

void testTemplate()
{
    try {
        Stack<int>  intStack;   // int 类型的栈
        Stack<string> stringStack; // string 类型的栈
        
        // 操作 int 类型的栈
        intStack.push(7);
        cout << intStack.top() << endl;
        
        // 操作 string 类型的栈
        stringStack.push("hello");
        std::cout << stringStack.top() << std::endl;
        stringStack.pop();
//        stringStack.pop();
        
    } catch (exception const& ex) {
        cerr << "Exception: " << ex.what() << endl;
    }
}

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

void learnPthread()
{
  pthreadClass pthread;
  pthread.testPthread();
}

void learnCGI()
{
  cout << "Content-type:text/html\r\n\r\n";    cout << "<html>\n";
  cout << "<head>\n";
  cout << "<title>Hello World - 第一个 CGI 程序</title>\n";
  cout << "</head>\n";
  cout << "<body>\n";
  cout << "<h2>Hello World! 这是我的第一个 CGI 程序</h2>\n";
  cout << "</body>\n";
  cout << "</html>\n";
}

void swpaInt(int *a, int *b)
{
  *a = *b ^ *a;
  *b = *a ^ *b;
  *a = *b ^ *a;
}

void swpaIntTow(int &a, int &b) {
  a = b ^ a;
  cout << a << endl;
  b = a ^ b;
  cout << b << endl;
  
  a = b ^ a;
  cout << a << endl;
}

void swpaIntThrid(int a, int b)
{
  a = b ^ a;
  b = a ^ b;
  a = b ^ a;
}

void intArrSort()
{
  int arr[] = {1, 4, 5, 2, 0, 3};
  /*
  for (int i = 0; i < 6; i++) {
    for (int j = 1; j < 6 - i; j++) {
      if (arr[j - 1] < arr[j]) {
//        int a = arr[j - 1];
//        arr[j - 1] = arr[j];
//        arr[j] = a;
        swpaInt(&arr[j - 1], &arr[j]);
      }
    }
  }
   */
  
  int flag = 6;
  while (flag > 0) {
    int k = flag;
    flag = 0;
    for (int j = 1; j < k; j++) {
      if (arr[j - 1] < arr[j]) {
        //        int a = arr[j - 1];
        //        arr[j - 1] = arr[j];
        //        arr[j] = a;
//        swpaInt(&arr[j - 1], &arr[j]);
//        swpaIntTow(arr[j - 1], arr[j]);
        swpaIntThrid(arr[j - 1], arr[j]);
        flag = j;
      }
    }
  }
  
  for (int i = 0; i < 6; i++) {
    cout<< arr[i] << endl;
  }
  
  
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    inputYourName();
    
    
  char const* str = "";
    std::srand((unsigned)time(0));
    for (int i = 0; i < 6; i++) {
//        Delay(1000);
        int a = getrandNum(1, 6);
        std::cout << a << std::endl;
        
        int time = (int)std::time(0);
        std::stringstream timeStr;
        timeStr << time;
        
        std::cout << "当前时间:" + timeStr.str() << std::endl;
    }
    
    learnChar();
    
    lenarnString();
    
    learnPointer();
    
    learnNULL();
    
    learnPointerArithmetic();
    
    int *p;
    p = getRandom();
    for (int i = 0; i < 3; i++) {
        myclong("*(p + "<< i <<") = ", *(p + i));
    }
    
    learnRerence();
    lenarnStruct();
    learnClass();
    
    learnFrielAndStream();
    
    testTemplate();
  
  learnPthread();
  learnCGI();
  intArrSort();
    return 0;
}




