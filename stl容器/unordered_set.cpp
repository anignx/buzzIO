#include <iostream>  
#include <unordered_set>  

using namespace std; 

//unordered_set是一种关联容器，set和map内部实现是基于RB-Tree，是有序的，unordered_set和unordered_map是基于hashtable。是无序的。
//首先了解哈希表的机制。哈希表是根据关键码值进行直接访问的数据结构，通过相应的哈希函数处理关键字得到相应的关键码值，
//关键码值对应着一个特定位置，用该位置来存取相应的信息。这样就能以较快的速度获取关键字的信息。
int main(){
    unordered_set<int> c1;
    c1.emplace(1);
    c1.emplace(1);
    c1.emplace(1);
    c1.empty();//判断是否为空
    c1.size();//获取元素个数
    c1.max_size();//获取最大存储量

    //返回头迭代器
    unordered_set<int>::iterator ite_begin=c1.begin();
    //返回尾迭代器
    unordered_set<int>::iterator ite_end=c1.end();
    //槽迭代器
    // unordered_set<int>::iterator local_iter_begin=c1.begin(1);
    // unordered_set<int>::iterator local_iter_end=c1.end(1);

    //查找函数find通过给定主键查找元素
    unordered_set<int>::iterator find_iter=c1.find(1);
    //value出现的次数count返回匹配给定主键元素的个数
    c1.count(1);
    //返回元素在哪个区域equal_range，返回值匹配给定搜索值的元素组成的范围
    pair<unordered_set<int>::iterator,
    unordered_set<int>::iterator> pair_equal_range = c1.equal_range(1);
    //插入函数emplace
    c1.emplace(1);
    //插入函数emplace_hint()使用迭代器
    // c1.emplace_hint(ite.begin,1);
    //插入函数insert
    c1.insert(1);
    //删除erase
    c1.erase(1);
    //清空clear
    c1.clear();
    //交换swap
    // c1.swap(c2);
    return 0;
}