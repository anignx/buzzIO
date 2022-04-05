#include <iostream>
#include <bitset>

using namespace std;

int main(){
    bitset<10000> s; //10的5次方个bits
    s.count();

    s.set(); //全部置为1
    s.set(5, 1); // 第五位置0

    s.reset(); //全部置0
    s.reset(5); //第5位置0

    s.flip(); //整体按位取反
    s.flip(4); //第四位按位取反

    s[3] = 0; //直接赋值
    s[8] = 1; //直接赋值

    s.any(); //整个bits是否有至少1个1
    s.none(); //整个bits都是0

    return 0;
}