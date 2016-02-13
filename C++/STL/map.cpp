/* Created by Qiu on 7/29/2015 to test map STL*/

#include <map>
#include <iostream>

class Map_Practice{
public:
    static void RunAllTests();
    
private:
    static void Test();
    static void Show(const std::map<char, int> &map1);
};

using std::map;
using namespace std;

int main(){
    Map_Practice::RunAllTests();
}

void Map_Practice::RunAllTests(){
    Test();
}

void Map_Practice::Test(){
    map<char, int> map1;
    map1['a'] = 10;
    map1['b'] = 2;
    map1['c'] = 30;
    
   // Show(map1);
    
    map<char, int> map2(map1.begin(), map1.end());
    for (map<char, int>::iterator iter = map2.begin(); iter != map2.end(); iter++) {
        cout << iter->first << " => " << iter ->second << endl;
    }
}


ddddd

/*void Map_Practice::Show(const map<char, int> &map1){
    for (map<char, int>::iterator iter = map1.begin(); iter != map1.end(); iter++) {
        cout << iter->first << " => " << iter ->second << endl;
    }
}
*/