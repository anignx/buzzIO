#include <iostream>
#include <set>

using namespace std;

int main(){

    //set集合，默认升序，内部红黑树
    set<int> ss;
    ss.insert(5);
    ss.insert(4);
    ss.insert(2);
    ss.insert(1);
    ss.insert(8);
    ss.insert(-4);

    ss.erase(-4);

    for(auto i = ss.begin(); i != ss.end(); i++){
        std::cout << *i;
    }

    set<int>::iterator lit = ss.lower_bound(2); //查找第一个大于等于2的迭代器，二分查找
    if(lit != ss.end()){
        std::cout << "，找到2:" << *lit;
    }

    set<int>::iterator uit = ss.upper_bound(5); //查找第一个小于等于5的迭代器，二分查找
    if(uit != ss.end()){
        std::cout << "，找到5:" << *uit << std::endl;
    }

    auto myset = ss.equal_range(1); //它返回一个范围的边界，该范围包括容器中与val等效的所有元素。

    std::cout << "，left:" << *myset.first << "，右:" << *myset.second;

    if(ss.find(1) != ss.end()){
        std::cout << "，找到1";
    }

    ss.empty();
    ss.size();
    ss.clear();
    

    return 0;
}