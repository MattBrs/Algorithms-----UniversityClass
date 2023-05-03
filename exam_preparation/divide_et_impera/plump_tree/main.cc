#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct node {
	node* parent = nullptr;
	int value;
	node* left_child = nullptr;
	node* right_child = nullptr;
};

typedef node* tree;

void init_tree(tree &root);
void tree_push(tree &root, tree parent, int new_value);
void tree_push(tree &root, int new_value);
void print_tree(tree root);

bool isPlump(tree root) {
	int level = 0;
	int node_count = 1;

	queue<tree> node_queue;
	node_queue.push(root);

	while (!node_queue.empty()) {
		tree curr_node = node_queue.front();
		node_queue.pop();
		node_count--;


		if (curr_node->left_child != nullptr) {
			node_queue.push(curr_node->left_child);
		}

		if (curr_node->right_child != nullptr) {
			node_queue.push(curr_node->right_child);
		}

		if (node_count == 0) {
			node_count = node_queue.size();
			level++;

			if (node_count > 0 && node_count < pow(2, level - 1)) {
				return false;
			}
		}
	}

	return true;
}



int main() {
	tree root = nullptr;

	tree_push(root, 50);
	tree_push(root, 40);
	tree_push(root, 70);
	tree_push(root, 20);
	tree_push(root, 60);
	tree_push(root, 100);
	tree_push(root, 15);

	tree_push(root, 22);
	tree_push(root, 58);
	tree_push(root, 65);
	tree_push(root, 90);
	tree_push(root, 150);
	tree_push(root, 10);
	tree_push(root, 21);

	tree_push(root, 23);
	tree_push(root, 55);
	tree_push(root, 61);
	tree_push(root, 67);
	tree_push(root, 80);
	tree_push(root, 120);

	// print_tree(root);

	cout << "the tree " << (isPlump(root) ? "is plump" : "is not plump") << endl;

	return 0;
}

void init_tree(tree &root) {
	root = new node;
}

void tree_push(tree &root, tree parent, int new_value) {
	if (root == nullptr) {
		root = new node;
		root->value = new_value;
		return;
	}

	if (new_value <= root->value) {
		tree_push(root->left_child, nullptr, new_value);
		return;
	}

	if (new_value > root->value) {
		tree_push(root->right_child, nullptr,new_value);
		return;
	}
}

void tree_push(tree &root, int new_value) {
	tree_push(root, nullptr, new_value);
}

void print_tree(tree root) {
	if (root == nullptr) {
		return;
	}

	print_tree(root->left_child);
	cout << root->value << endl;
	print_tree(root->right_child);
}