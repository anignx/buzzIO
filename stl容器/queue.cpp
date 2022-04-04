#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> res;
    res.push(1);
    res.push(2);
    res.push(3);
    res.push(4);

    //首位元素
    std::cout << "首：" << res.front() << ",尾" << res.back() << std::endl;

    //尾部插入
    res.push(8);

    //长度
    std::cout << res.size() << std::endl;

    //尾部删除
    res.pop(); 

    //判断空
    res.empty();

    return 0;
}