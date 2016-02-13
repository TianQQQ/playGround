//
//  mutex.cpp
//  threadtest
//
//  Created by Tian Qiu on 11/30/15.
//  Copyright © 2015 Tian Qiu. All rights reserved.
//

#include "mutex.hpp"

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void outnum( int n){
    static mutex m ;
    m.lock();
    cout <<"["<<n<<"]"<<endl;
    m.unlock();
}

void printnums(int start, int n){
    for (int i = 0; i< n ;i++){
        outnum(start + i);
    }
}

int main(){
    
    thread t[50];
    for (int i=0; i<50; i++) {
        t[i] = thread t2 (printnums i, 100);
    }
    for (int i = 0; i<50 ; i++) {
        t[i].join();
    }
    
}
