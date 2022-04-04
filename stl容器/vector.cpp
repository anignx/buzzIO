#include <iostream>
#include <vector>

using namespace std;

int main(){
    std::vector<int> res = {1,2,3,4,5,6,7};
    //迭代器
    for(auto i = res.begin(); i != res.end(); i++){
        std::cout << *i << std::endl;
    }
    //首位元素
    std::cout << "首：" << res.front() << ",尾" << res.back() << std::endl;

    //尾部插入
    res.push_back(8);

    //长度
    std::cout << res.size() << std::endl;

    //尾部删除
    res.pop_back(); 

    //判断空
    res.empty();

    //清空
    res.clear();

    return 0;
}