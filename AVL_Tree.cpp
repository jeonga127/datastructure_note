#include <iostream>
#include <algorithm>

using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

class AVL {
public:
	node* root;
	int temp_level = 1;
	class AVL() {
		root = NULL;
	};
public:
	node* insert(node* root, int x);
	node* edit(node* temp);
	int height(node* temp);
	int diff(node* temp);
	node* rr(node* temp);
	node* ll(node* temp);
	node* rl(node* temp);
	node* lr(node* temp);
	void show(node* root, int level);
};

void AVL::show(node* temp, int level) {
	if (temp != NULL) {
		show(temp->right, level + 1);
		for (int i = 0;i < (height(root)-height(temp));i++)
			cout << "           ";
		if (temp == root) {
			cout << "Root : ";
		}
		else {
			cout << "Value : ";
		}
		cout << temp->data << endl;
		show(temp->left, level + 1);
	}
}

node* AVL::rr(node * temp) {
	node* tmp;
	tmp = temp->right;
	temp->right = tmp->left;
	tmp->left = temp;

	cout << "************* RR회전 발생! ************" << endl;
	return tmp;
}

node* AVL::ll(node * temp) {
	node* tmp;
	tmp = temp->left;
	temp->left = tmp->right;
	tmp->right = temp;
	cout << "************* LL회전 발생! ************" << endl;
	return tmp;
}

node* AVL::rl(node * temp) {
	node* tmp;
	tmp = temp->right;
	temp->right = ll(tmp);
	cout << "************* RL회전 발생! ************" << endl;
	return rr(temp);
}

node* AVL::lr(node * temp) {
	node* tmp;
	tmp = temp->left;
	temp->left = rr(tmp);
	cout << "************* LR회전 발생! ************" << endl;
	return ll(temp);
}
int AVL::height(node * temp) {
	int h = 0;
	if (temp != NULL) {
		int left = height(temp->left);
		int right = height(temp->right);
		int maxHeight = max(left, right);
		h = maxHeight + 1;
	}
	return h;
}

int AVL::diff(node * temp) {
	int left = height(temp->left);
	int right = height(temp->right);
	return (left - right);
}

node* AVL::edit(node * temp) {
	int df = diff(temp);
	if (df > 1) {
		if (diff(temp->left) > 0) {
			temp = ll(temp);
		}
		else {
			temp = lr(temp);
		}

	}
	else if (df < -1) {
		if (diff(temp->right) > 0) {
			temp = rl(temp);
		}
		else {
			temp = rr(temp);
		}
	}
	return temp;
}

node* AVL::insert(node * root, int x) {
	if (root == NULL) {
		root = new node;
		root->data = x;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (x < root->data) {
		temp_level++;
		root->left = insert(root->left, x);
		root = edit(root);
	}
	else if (x >= root->data) {
		temp_level++;
		root->right = insert(root->right, x);
		root = edit(root);
	}
	temp_level = 1;
	return root;
}

int main()
{
	char c;
	AVL avl;
	int input = 0;
	while (true) {
		cout << "***********************************************" << endl;
		cout << "Insert Integer : ";
		cin >> input;
		avl.root = avl.insert(avl.root, input);
		avl.show(avl.root, 1);
	}
	return 0;
