//
//  learnFileAndStream.cpp
//  LearnC++
//
//  Created by lwj on 2018/5/2.
//  Copyright © 2018年 ydd. All rights reserved.
//

#include "learnFileAndStream.hpp"
#include <fstream>
#include <iostream>

using namespace std;

FileAndStream::FileAndStream()
{
    
}

FileAndStream::~FileAndStream()
{
    
}

void FileAndStream::testFileAndStream()
{
    char data[100];
    
    // 以写模式打开文件
    ofstream outfile;
    outfile.open("afile.dat");
    cout << "写入文件" << endl;
    cout << "输入你的名字: ";
    cin.getline(data, 100);
    
    // 向文件写入用户输入的数据
    outfile << data << endl;
    
    cout << "输入年龄: ";
    cin >> data;
    cin.ignore();
    
    // 再次向文件写入用户输入的数据
    outfile << data << endl;
    
    // 关闭文件
    outfile.close();
    
    // 以读模式打开文件
    ifstream infile;
    infile.open("afile.dat");
    cout << "读取文件" << endl;
    infile >> data;
    
    // 在屏幕上写入数据
    cout << data << endl;
    
    // 再次从文件读取数据, 并显示它
    infile >> data;
    cout << data << endl;
    
    
    
    
    // 关闭打开的文件
    infile.close();

//    实例中使用了 cin 对象的附加函数，比如 getline()函数从外部读取一行，ignore() 函数会忽略掉之前读语句留下的多余字符。
}
