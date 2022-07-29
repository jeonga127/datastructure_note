#include <iostream>
#include <time.h>
#include <ctime>
#include <stack>
using namespace std;

int main(){
	stack<int> s;
	clock_t start, finish; double duration;
	start = clock();
	srand((unsigned)time(NULL));
	int size = 0;
	cout << "그래프의 크기를 입력하세요 : ";
	cin >> size;
	int **arr = new int*[size];
	for (int i = 0; i < size; i++){
		arr[i] = new int[size];
	}

	for (int i = 0; i < size; i++){
		for (int j = i; j < size; j++){
			arr[i][j] = rand() % 2;
			arr[j][i] = arr[i][j];
		}arr[i][i] = 0;
	} // 그래프 완성

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			cout << arr[i][j];
		} cout << endl;
	}

	int search = 0; // search할 정점
	int searchcheck = -1; //search를 더 해야할지 여부 체크
	int temp = 1; //visited에 저장할 변수
	int* mark = new int[size];
	for (int i = 0; i < size; i++){
		mark[i] = 0;
	}

	while (true){
		while (true){
			mark[search] = temp;
			int depthcheck = -1; // 더 깊이 들어갈지 말지 결정하는 변수, 깊이체크 아님x 
			for (int i = 0; i < size; i++){
				if (arr[search][i] == 1 && mark[i] == 0){
					depthcheck = 0;
					s.push(i);
				}
			}
			if (depthcheck == -1){
				s.pop(); 
				if (s.empty())
					break;
				else
					search = s.top();
			} else
				search = s.top();
		}

		cout << endl << "그래프 내 릴레이션 : " << endl;

		for (int i = 0; i < size; i++){
			if (mark[i] == temp)
				cout << i << " ";
		} cout << endl;
		temp++; 

		for (int i = 0; i < size; i++){
			if (mark[i] == 0){
				search = i;
				searchcheck = 1;
			}
		} if (searchcheck == -1)
			break;
	}
	finish = clock();
	duration = (double)(finish - start);
	cout << duration << " 초 걸렸습니다." << endl;
}
