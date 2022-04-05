#include <iostream>  
#include <unordered_map>  
#include <map>
#include <string>  
using namespace std;  

//优点：因为内部实现了哈希表，因此其查找速度非常的快，缺点：哈希表的建立比较耗费时间
//注意map是红黑树，而unordered_map是hash表
int main()  
{  
	//注意：C++11才开始支持括号初始化
    unordered_map<int, string> myMap={{ 5, "张大" },{ 6, "李五" }};//使用{}赋值
    myMap[2] = "李四";  //使用[ ]进行单个插入，若已存在键值2，则赋值修改，若无则插入。
    myMap.insert(pair<int, string>(3, "陈二"));//使用insert和pair插入
  
	//遍历输出+迭代器的使用
    auto iter = myMap.begin();//auto自动识别为迭代器类型unordered_map<int,string>::iterator
    while (iter!= myMap.end())
    {  
        cout << iter->first << "," << iter->second << endl;  
        ++iter;  
    }  
	
	//查找元素并输出+迭代器的使用
    auto iterator = myMap.find(2);//find()返回一个指向2的迭代器
    if (iterator != myMap.end())
	    cout << endl<< iterator->first << "," << iterator->second << endl;  
    system("pause");  
    return 0;  
}  

