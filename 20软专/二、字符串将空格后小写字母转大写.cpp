#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main() { 
	string str;//创建字符串
	while (getline(cin,str)) {//读入字符串
		for (int i = 0; i < str.length(); i++) {//遍历字符串
			if (str[i] == ' ') {//当前字符为空格时，下一字符转为大写 
				str[i + 1] -= 32;//小写转大写（通过ASCII码增减）
			}
		}
		cout << str << endl;//输出转换后的字符串
	}
	
}