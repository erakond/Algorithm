/* Author: wqw
 * File : ALGO-21.cpp
 * Description  : 经典的01背包问题
 */

//ALGO-21     算法训练   装箱问题
//（动态规划）
//时间限制：1.0s   内存限制：256.0MB
//
//问题描述
//有一个箱子容量为V（正整数，0＜＝V＜＝20000），同时有n个物品（0＜n＜＝30），每个物品有一个体积（正整数）。
//　　要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。
//输入格式
//第一行为一个整数，表示箱子容量；
//　　第二行为一个整数，表示有n个物品；
//　　接下来n行，每行一个整数表示这n个物品的各自体积。
//输出格式
//一个整数，表示箱子剩余空间。
//样例输入
//24
//6
//7
//2
//12
//7
//9
//7
//样例输出
//    0

#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;

void get_result(int* box, int* good, int V, int n) {
	for (int i=0; i < n; i++) {
		for (int j=V; j >= good[i]; j--) {
			if (box[j-good[i]] + good[i] > box[j])
				box[j] = box[j-good[i]] + good[i];
		}
	}
}

int main() {
	int box[20001] = {0};
	int good[31] = {0};
	int V, n;
	
	cin>>V>>n;
	for (int i=0; i < n; i++) 
		cin>>good[i];
	get_result(box, good, V, n);
	
	cout<<(V - box[V]);
	return 0;
}
