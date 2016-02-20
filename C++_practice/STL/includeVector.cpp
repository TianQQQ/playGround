/* 
    Test algorithm and vector library (stl)
 
    Created by Qiu on 7/24/2015
    All rights are reserved
*/

#include<stdio.h>
//#include<algorithm>
#include<vector>          // library
#include<iostream>

using namespace std;

typedef struct rect{
    int id;
    int length;
    int width;
    
    bool operator<(const rect &a) const{
        if(id != a.id){
            return id < a.id;
        }else{
            if(length != a.length){
                return length<a.length;
            }else{
                return width<a.width;
            }
        }
    }
    
}Rect;

int main(){
    vector<Rect> vec;       // create vector container
    Rect rect;
    rect.id = 1;
    rect.length = 2;
    rect.width = 3;
    vec.push_back(rect);    // insert number rect
    vector<Rect>::iterator it = vec.begin();
    cout<<(*it).id<<""<<(*it).length<<""<<(*it).width<<endl;
    return 0;
    
}