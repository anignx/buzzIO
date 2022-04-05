#include <iostream>
#include <map>

using namespace std;

//优点：有序性，这是map结构最大的优点，其元素的有序性在很多应用中都会简化很多的操作；
//优点：红黑树，内部实现一个红黑树使得map的很多操作在O(lgn)的时间复杂度下就可以实现，因此效率非常的高。
//缺点：空间占用率高，因为map内部实现了红黑树，虽然提高了运行效率，但是因为每一个节点都需要额外保存父节点、孩子节点和红/黑性质，使得每一个节点都占用大量的空间
int main(){
    std::map<int, char> m; //红黑树

    m[1] = 'c';
    m[2] = 'b';
    m.insert(std::map<int, char>::value_type(5, 'd'));
    m.erase(2);

    for(auto it = m.begin(); it != m.end(); it++){
        std::cout << it->first << ", " << it->second;
    }

    auto mit = m.find(1);
    if(mit != m.end()){
        std::cout << "find:" << mit->second;
    }

    return 0;
}