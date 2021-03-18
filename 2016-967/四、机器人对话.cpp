#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char M1[3] = { 'Y','N','2' };
char M2[3] = { 'y','n','1' };

bool exsit(int flag ,char x) {
	if (flag) {//判断说的话和机器人身份是否相符
		for (int i = 0; i < 3; i++) {
			if (M1[i] == x)return true;
		}
		return false;
	}
	else {
		for (int i = 0; i < 3; i++) {
			if (M2[i] == x)return true;
		}
		return false;
	}
}
bool judge(char *str) {
	
	int flag = 1;//flag指示当前那个机器人在说话
	if (!exsit(flag, str[0])) {//判断是否第一个机器人先说话
		return false;
	}
	for (int i = 1; i < strlen(str); i++) {//遍历整个数组
		if (str[i] == '2') {//第一个机器人结束，标记转为第二个机器人
			flag = 0;
		}
		else if (str[i] == '1') {//第二个机器人结束，标记转为第一个机器人
			flag = 1;
		}
		else if (!exsit(flag, str[i])) {//判断当前说的话和说话的机器人是否相符
			return false;
		}

	}
	return true;
}

int main() {
	char str[100];
	while (scanf("%s", str) != EOF) {
		if (judge(str))printf("1\n");
		else printf("0\n");
	}
}