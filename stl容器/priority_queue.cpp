#include <iostream>
#include <queue>

using namespace std;

int main(){

    //大根堆
    priority_queue<int, vector<int>, less<int>> que_less;
    que_less.push(1);
    que_less.push(3);
    que_less.push(5);
    que_less.push(7);
    que_less.push(-4);

    //小根堆
    priority_queue<int, vector<int>, greater<int>> que_greater;
    que_greater.push(1);
    que_greater.push(3);
    que_greater.push(5);
    que_greater.push(7);
    que_greater.push(-4);

    std::cout << que_less.top(); //大根堆，top取出最大值
    std::cout << que_greater.top();  //小根堆，top取出最小值

    std::cout << que_less.size();
    que_less.pop(); //删除尾部元素，大根堆删最小值，小根堆删最大值
    std::cout << que_less.size();

    que_less.empty();

    return 0;
}