#include <iostream>
#include <time.h>
#define MAP_SIZE 11
using namespace std;

int map[MAP_SIZE][MAP_SIZE] = { 0 };

class stack {
public:
	int trace[(MAP_SIZE - 2)*(MAP_SIZE - 2)];
	int top;
public:
	stack();
	void push(int data);
	int pop();
	void print();
};

stack::stack() {
	trace[(MAP_SIZE - 2)*(MAP_SIZE - 2)] = 0;
	top = -1;
}

void stack::push(int data) {
	if (top == (MAP_SIZE - 2)*(MAP_SIZE - 2) - 1){
		cout << "stack full" << endl;
		return;
	}
	trace[++top] = data;
}

int stack::pop() {
	if (top == -1){
		return 0;
	}
	return trace[top--];
}

void stack::print() {
	for (int i = 0; i <= top; i++)
		cout << trace[i] << " ";
}

int checknear(int coord){
	int x = coord / 10; int y = coord % 10;
	if (map[x + 1][y + 1] == 0)
		return (x + 1) * 10 + (y + 1);
	else if (map[x + 1][y] == 0)
		return (x + 1) * 10 + (y);
	else if (map[x][y + 1] == 0)
		return (x) * 10 + (y + 1);
	else if (map[x - 1][y + 1] == 0)
		return (x - 1)* 10 + (y + 1);
	else if (map[x + 1][y - 1] == 0)
		return (x + 1)* 10 + (y - 1);
	else if (map[x - 1][y] == 0)
		return (x - 1) * 10 + (y);
	else if (map[x][y - 1] == 0)
		return (x) * 10 + (y - 1);
	else if (map[x - 1][y - 1] == 0)
		return (x - 1) * 10 + (y - 1);
	else
		return -1;
}

int main(){
	stack s; 
	srand(time(NULL));


	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			map[i][j] = rand() % 2;
		}
	}

	for (int i = 0; i < MAP_SIZE; i++) {
		map[0][i] = 1;
		map[i][0] = 1;
		map[i][MAP_SIZE - 1] = 1;
		map[MAP_SIZE - 1][i] = 1;
	}

	map[1][1] = 0;
	map[MAP_SIZE - 2][MAP_SIZE - 2] = 0;
	

	cout << endl << endl;

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (i == 0 || j == 0 || i == MAP_SIZE - 1 || j == MAP_SIZE - 1)
				cout << "@";
			else if (map[i][j] == 0)
				cout << "o";
			else if (map[i][j] == 1)
				cout << "x";
		}
		cout << endl;
	}

	int coord = 11; s.push(11);
	int depth = 0;

	while (coord != 99){
		coord = checknear(coord);
		if (coord == -1){
			coord = s.pop(); depth--;
			if (depth == -1){
				cout << "출발지까지의 경로가 없습니다." << endl;
				break;
			}
		}		else {
			s.push(coord); map[coord / 10][coord % 10] = 3;
			depth++;
		}
	}

	s.print();
}
