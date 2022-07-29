#include <iostream>
#include <ctime>
#include <time.h>
#include <stack>
#include <list>
using namespace std;

stack<int> s;

class Graph{
public:
	int size;
	list<int> *linked;
	int* mark;
public:
	Graph(int size);
	void Graphprint();
	void DFS(int x, int temp);
	void result();
};

Graph::Graph(int size){
	srand((unsigned)time(NULL));
	this->size = size;

	mark = new int[size];
	for (int i = 0; i < size; i++)
		mark[i] = 0;

	linked = new list<int>[size];
	for (int i = 0; i < size; i++){
		for (int j = i + 1; j < size; j++){
			if (rand() % 2 == 1){
				linked[i].push_back(j);
				linked[j].push_back(i);
			}
		} // linked[i] 종료
	} 
}

void Graph::Graphprint(){
	for (int i = 0; i < size; i++){
		for (list<int>::iterator j = linked[i].begin(); j != linked[i].end(); j++){
			cout << *j << " ";
		} cout << endl;
	}
}

void Graph::DFS(int x, int temp){
	int depthcheck = -1;
	mark[x] = temp;
	for (list<int>::iterator j = linked[x].begin(); j != linked[x].end(); j++){
		if (mark[*j] == 0){
			depthcheck = 0;
			DFS(*j, temp);
		}
	}	if (depthcheck == -1)
		return;
}

void Graph::result(){
	int temp = 1;
	int searchcheck = -1;
	int search = 0;

	while (true){
		searchcheck = -1;
		DFS(search, temp);
		cout << endl << "그래프 내 릴레이션 : " << endl;

		for (int i = 0; i < size; i++){
			if (mark[i] == temp)
				cout << i << " ";
		} temp++;

		for (int i = 0; i < size; i++){
			if (mark[i] == 0){
				search = i;
				searchcheck = 1;
			}
		} if (searchcheck == -1)
			break;
	}
	return;
}

int main(){
	clock_t start, finish; double duration;
	start = clock();
	srand((unsigned)time(NULL));
	int size = 0;
	cout << "그래프의 크기를 입력하세요 : ";
	cin >> size;
	Graph arr(size); 
	arr.Graphprint();
	arr.result();
	finish = clock();
	duration = (double)(finish - start);
	cout << endl << endl << duration << " 초 걸렸습니다." << endl;
}
