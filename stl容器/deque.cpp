#include <iostream>
#include <queue>

using namespace std;

int main(){

    //大根堆
    deque<int> que;
    que.push_back(1); //尾部插入
    que.push_front(3); //头部插入
    que.push_front(4); //头部插入
    que.push_front(5); //头部插入
    que.push_front(6); //头部插入

    for(auto i = que.begin(); i != que.end(); i++){
        std::cout << *i;
    }
    std::cout << "头：" << que.front() << ",尾" << que.back();

    que.pop_back(); //尾部弹出
    que.pop_front(); //头部弹出
    que.clear(); //清空

    return 0;
}