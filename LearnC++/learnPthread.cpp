//
//  learnPthread.cpp
//  LearnC++
//
//  Created by lwj on 2018/5/7.
//  Copyright © 2018年 ydd. All rights reserved.
//

#include "learnPthread.hpp"
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib>
#define NUM_THREADS 5

using namespace std;

struct thread_data {
  int thread_id;
  char *message;
};

void* say_hello(void* args)
{
  string time = __TIME__;
  string contentstr = time + ": Hello w3cscholl! \n";
  cout << contentstr << endl;
  return NULL;
}

void *PrintHello (void *threadid)
{
  // 对传入的参数进行强制类型转换, 由于类型指针变为整形数指针, 然后再读取
  int tid = *((int *)threadid);
  tid = *static_cast<int*>(threadid);
  string tidStr = to_string(tid);
  string time = __TIME__;
  string str = time + ": Hello w3cschool ! 线程 ID, " + tidStr + "\n";
  cout << str << endl;
  pthread_exit(NULL);
}

void pthreadClass::testPthread()
{
  this->example1();
  this->example2();
  this->example3();
//  this->example4();

}

// 使用 pthread_create() 例:创建了 5 个线程。每个线程打印一个 "Hello World!" 消息，然后调用 pthread_exit() 终止线程。
// pthread_exit()相当于 return, 无返回值函数不能调用 pthread_exit()
void* pthreadClass::example1()
{
  // 定义线程 id 变量, 多个变量使用数组
  pthread_t tids[NUM_THREADS];
  for (int i = 0; i < NUM_THREADS; i++) {
    // 参数依次是:创建的线程 id, 线程参数, 调用的函数, 传入的函数参数
    int ret = pthread_create(&tids[i], NULL,say_hello, NULL);
    if (ret != 0) {
      cout << "pthread_create error: error_code=" << ret << endl;
    }
    
  }
  // 等各个线程退出后, 进程才结束, 否则进程强制结束了, 线程可能还没有没反应过来;
//    pthread_exit(NULL);
  return 0;
}

// pthread_create() 函数创建了 5 个线程，并接收传入的参数。每个线程打印一个 "Hello w3cschool！" 消息，并输出接收的参数，然后调用 pthread_exit() 终止线程
int pthreadClass::example2()
{
  pthread_t threads[NUM_THREADS];
  int indexes[NUM_THREADS]; // 用数组来保存 i 的值
  int rc, i;
  for (i = 0; i < NUM_THREADS; i++) {
    cout << "example2() : 创建线程, " << i << endl;
    indexes[i] = i; // 先保存 i 的值
    // 传入的时候必须强制转化为 void* 类型, 即无类型指针
    rc = pthread_create(&threads[i], NULL, PrintHello, static_cast<void*>(&indexes[i]));
    if (rc) {
      cout << "Error: 无法创建线程," << rc << endl;
      exit(-1);
    }
  }
//  pthread_exit(NULL);
  return 0;
}

// 向线程传递参数
// 这个实例演示了如何通过结构传递多个参数。您可以在线程回调中传递任意的数据类型，因为它指向 void
void *PrintHello3(void *threadarg)
{
  struct thread_data *my_data;
  my_data = static_cast<thread_data*>(threadarg);
  
  cout << "Thread Id : " << my_data->thread_id;
  cout << " Message : " << my_data->message << endl;
  
  pthread_exit(NULL);
}

int pthreadClass::example3()
{
  pthread_t threads[NUM_THREADS];
  struct thread_data td[NUM_THREADS];
  int rc;
  int i;
  for (i = 0; i < NUM_THREADS; i++) {
    cout << "example3() : creating thread, " << i << endl;
    td[i].thread_id = i;
    td[i].message = (char*)"This is message";
    rc = pthread_create(&threads[i], NULL, PrintHello3, static_cast<void*>(&td[i]));
    if (rc) {
      cout << "Error:unable to create thread," << endl;
      exit(-1);
    }
    
  }
//  pthread_exit(NULL);
  return 0;
  
}

// 连接和分离线程

/*
有以下两个例程，我们可以用它们来连接或分离线程：
pthread_join (threadid, status)
pthread_detach (threadid)
 
pthread_join() 子例程阻碍调用例程，直到指定的 threadid 线程终止为止。当创建一个线程时，它的某个属性会定义它是否是可连接的（joinable）或可分离的（detached）。只有创建时定义为可连接的线程才可以被连接。如果线程创建时被定义为可分离的，则它永远也不能被连接。
 */

void *wait(void *t)
{
  int i;
  long tid;
  tid = (long)t;
   cout << "Sleeping in thread " << endl;
  sleep(1);
 
  cout << "Thread with id : " << tid << "  ...exiting " << endl;
  pthread_exit(NULL);
  
}

int pthreadClass::example4()
{
  
  int  rc;
  int i;
  pthread_t threads[NUM_THREADS];
  pthread_attr_t attr;
  void *status;
  // 初始化并设置线程为可连接的 (joinable)
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  
  for (i = 0; i < NUM_THREADS; i++) {
    cout << "main() : creating thread, " << i << endl;
    rc = pthread_create(&threads[i], NULL, wait, static_cast<void*>(&i));
    if (rc) {
      cout << "Error: unable to create thread," << rc << endl;
      exit(-1);
    }
  }
  
  // 删除属性, 并等待其他线程
  pthread_attr_destroy(&attr);
  for (int i = 0; i < NUM_THREADS; i++) {
    rc = pthread_join(threads[i], &status);
    if (rc) {
      cout << "Error:unable to join," << rc << endl;
      exit(-1);
    }
    cout << "Main: completed thread id :" << i;
    cout << " exiting with status :" << status << endl;
  }
  cout << "Main: program exiting." << endl;
  
  
  //  pthread_exit(NULL);
  return 0;
}

