#include<stdio.h>
#include<string.h>
int visit[25];
int path[25];

void findpaths(int a[5][5], int v, int aim, int path[], int d) {
	visit[v] = 1;
	path[++d] = v;
	if (v == aim && d > 1) {
		for (int i = 0; i <= d; i++) {
			printf(" %d", path[i]);
		}
		printf("\n");
	}
	for (int i = 0; i < 5; i++) {
		if (a[v][i] == 1) {
			if (visit[i] == 0) {
				findpaths(a, i, aim, path, d);
			}
		}
	}
	visit[v] = 0;

}






int main() {
	int a[5][5] = {
		0,1,0,1,0,
		1,0,1,0,0,
		0,1,0,1,1,
		1,0,1,0,1,
		0,0,1,1,0
	};
	memset(visit, 0, sizeof(visit));
	memset(path, 0, sizeof(path));
	findpaths(a, 0, 4, path, -1);

}
