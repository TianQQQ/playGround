//
//  main.cpp
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
    std::thread t1(printnums, 0 , 100);
    std::thread t2(printnums,1000, 100);
    t1.join();  // wait for t1 finished before allowing main thread go in
    t2.join();
    
}
