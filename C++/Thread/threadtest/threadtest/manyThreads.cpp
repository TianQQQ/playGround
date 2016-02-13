//
//  manyThreads.cpp
//  threadtest
//
//  Created by Tian Qiu on 11/30/15.
//  Copyright © 2015 Tian Qiu. All rights reserved.
//

#include <iostream>
#include <thread>

using namespace std;

void printnums(int start, int n){
    for (int i = 0; i< n ;i++){
        cout <<"["<<start + i << "]" << endl;
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

