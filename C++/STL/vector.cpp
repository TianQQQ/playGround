/* Created by Qiu on 7/28/2015 to test vector*/


#include "vector.h"

using std::vector;

int main(){
    Vector_Practice::RunAllTests();
}

void Vector_Practice::RunAllTests(){
    Test_Constructor();
}

void Vector_Practice::Show(const std::vector<int> &v){
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void Vector_Practice::Test_Constructor(){
    std::cout << '\n' << "Test_constructor"<< std::endl;
    vector<int> first;      // empty
    Show(first);
    vector<int> first1(5); // five zeros
    Show(first1);
    vector<int> second(4, 100); // four 100s
    Show(second);
    vector<int> third(second.begin(), second.end()); // four 100s
    Show(third);
    vector<int> fourth(third);  // four 100s
    Show(third);
    // iterator constructor can also be constructed from array
    int arr[] = {12, 23, 23, 2};
    int arrNum = sizeof(arr) / sizeof(int);
    std::cout << arrNum << std::endl;
    vector<int> fifth (arr, arr + arrNum);
    Show(fifth); // the same as vector.begin() vector.end() but it is array
    
    std::cout << "Test assignment";
    first = first1;
    first1 = fifth;
    Show(first);
    Show(fifth);
    
    // test iterator
    vector<int> empty;
    for (int i = 0 ; i < 5;  i ++) {
        empty.push_back(i); // 0 1 2 3 4   push_back
    }
    Show(empty);
    
    std::cout << "reverse output \n" << " empty vector contains: ";
    vector<int>::reverse_iterator rit;
    for (rit = empty.rbegin(); rit != empty.rend(); ++rit) {   // 4 3 2 1 0
        std::cout << *rit << " ";
    }
    
    // test size, capacity(reallocate), max_size
    std::cout << "\n 5 elements empty size: " << empty.size() << std::endl;
    std::cout << "\n 5 elements empty capacity: " << empty.capacity() << std::endl;
    std::cout << "\n 5 elements empty max_size: " << empty.max_size() << std::endl;
    

    
    empty.insert(empty.begin(), 2, 100); // 100 100 0 1 2 3 4
    Show(empty);
    
    empty.pop_back();   // 100 100 0 1 2 3 pop_back
    Show(empty);
    
    empty.resize(5);    // 100 100 0 1 2
    Show(empty);
    
    empty.resize(10, 9); // 100 100 0 1 2 9 9 9 9 9   resize
    Show(empty);
    
    vector<int>::size_type capacity = empty.capacity();
    empty.reserve(100);        // reserve capacity to 100
    std::cout << "Original capacity is: " << empty.capacity() << std::endl;
    for (int i = 0; i < 100; i ++) {
        empty.push_back(1);
        if (empty.capacity() != capacity) {
            capacity = empty.capacity();
            std::cout << " New capacity: " << empty.capacity() << std::endl;
        }
    }

    std::cout << empty.empty() << std::endl; // 0  clear empty
    empty.clear();
    std::cout << empty.empty() << std::endl; // 1
    
    for (int i = 0 ; i < 5;  i ++) {
        empty.push_back(i); // 0 1 2 3 4
    }
    empty.at(0) = 2;               // 2 1 2 3 4
    Show(empty);
    
    std::cout << empty.back() << std::endl;  // 4
    std::cout << empty.front() << std::endl; // 2    different with .begin()
    //std::cout << empty.begin() << std::endl;  Wrong!
    
    int *p = empty.data();    // copy p as array
    std::cout << p[4] << std::endl;
    
    for (unsigned int i = 0; i < empty.size(); i++) {
        std::cout << *p << " ";
        p++;
    }
    
    empty.assign(7, 100);  // add 7 more 100s    assign
    Show(empty);
}













