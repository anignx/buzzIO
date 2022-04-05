#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> res;
    res.push(1);
    res.push(2);
    res.push(3);
    res.push(4);

    //首位元素
    std::cout << "栈顶：" << res.top();

    //栈顶弹出
    res.pop();

    //长度
    std::cout << res.size() << std::endl;

    //判断空
    res.empty();

    return 0;
}