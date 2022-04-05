#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(){
    std::string s = "hello";
    char str[] = "223344";
    
    //长度
    std::cout << "长度:" << s.length() << "," << s.size();
    std::cout << "长度:" << str; //不计算\0

    //读取一行
    getline(cin, s);
    gets(str);

    //设置
    s = "world";
    strcpy(str, "world");

    //相加
    s = s + "hello,";
    strcat(str, "hello");

    //比较
    if(s == "TTT"){
        std::cout << "True";
    };
    strcmp(str, "TTT");


    return 0;
}