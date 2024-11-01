#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;
};

template <typename T>
class BinaryTree {
private:
	Node<T>* root;

	Node<T>* Search(T key, Node<T>* currNode) {
		if (currNode == nullptr) {
			return currNode;
		}
		if (currNode->data == key) {
			return currNode;
		}
		if (key < currNode->data) {
			return Search(key, currNode->left);
		}
		return Search(key, currNode->right);
	}

	Node<T>* SearchMinNode(Node<T>* currNode) {
		if (currNode->left == nullptr) {
			return currNode;
		}
		return SearchMinNode(currNode->left);
	}

	Node<T>* SearchMaxNode(Node<T>* currNode) {
		if (currNode->right == nullptr) {
			return currNode;
		}
		return SearchMaxNode(currNode->right);
	}

	Node<T>* Insert(T key, Node<T>* currNode) {
		if (currNode == nullptr) {
			currNode = new Node<T>{ key, nullptr, nullptr };
		}
		else if (key < currNode->data) {
			currNode->left = Insert(key, currNode->left);
		}
		else if (key > currNode->data) {
			currNode->right = Insert(key, currNode->right);
		}
		return(currNode);
	}

	Node<T>* Erase(T key, Node<T>* currNode) {
		if (currNode == nullptr) {
			return nullptr;
		}
		if (key < currNode->data) {
			currNode->left = Erase(key, currNode->left);
		}
		else if (key > currNode->data) {
			currNode->right = Erase(key, currNode->right);
		}
		else if (currNode->left != nullptr && currNode->right != nullptr) {
			Node<T>* maxNode = SearchMaxNode(currNode->left);
			currNode->data = maxNode->data;
			currNode->left = Erase(currNode->data, currNode->left);
		}
		else if (currNode->left != nullptr) {
			Node<T>* tmp = currNode->left;
			*currNode = *currNode->left;
			delete tmp;
		}
		else if (currNode->right != nullptr) {
			Node<T>* tmp = currNode->right;
			*currNode = *currNode->right;
			delete tmp;
		}
		else {
			Node<T>* tmp = currNode;
			currNode = nullptr;
			delete tmp;
		}
		return currNode;
	}

	void DeleteTree(Node<T>* currNode) {
		if (currNode != nullptr) {
			DeleteTree(currNode->left);
			DeleteTree(currNode->right);
			delete currNode;
		}
	}

	void PrintTree(Node<T>* p, int level) {
		if (p == nullptr) {
			return;
		}
		PrintTree(p->left, level + 1);
		for (int i = 0; i < level; i++) {
			std::cout << ".";
		}
		std::cout << p->data << std::endl;
		PrintTree(p->right, level + 1);
	}

public:
	BinaryTree() {
		root = nullptr;
	}

	bool Find(T key) {
		Node<T>* node = Search(key, root);
		if (node == nullptr) {
			return false;
		}
		else {
			return true;
		}
	}

	void Add(T key) {
		root = Insert(key, root);
	}

	void Delete(T key) {
		root = Erase(key, root);
	}

	void Print() {
		PrintTree(root, 0);
	}

	~BinaryTree() {
		DeleteTree(root);
	}
};

int main() {
	std::vector<std::pair<std::string, int>> commands;
	BinaryTree<int> tree;

	std::string cmd;

	while (std::cin >> cmd) {
		int vl;
		if (cmd == "ADD") {
			std::cin >> vl;
			commands.push_back({ "ADD", vl });
		}
		else if (cmd == "DELETE") {
			std::cin >> vl;
			commands.push_back({ "DELETE", vl });
		}
		else if (cmd == "SEARCH") {
			std::cin >> vl;
			commands.push_back({ "SEARCH", vl });
		}
		else if (cmd == "PRINTTREE") {
			commands.push_back({ "PRINTTREE", 0 });
		}
	}

	for (const auto& command : commands) {
		if (command.first == "ADD") {
			if (tree.Find(command.second)) {
				std::cout << "ALREADY\n";
			}
			else {
				tree.Add(command.second);
				std::cout << "DONE\n";
			}
		}
		else if (command.first == "DELETE") {
			if (!tree.Find(command.second)) {
				std::cout << "CANNOT\n";
			}
			else {
				tree.Delete(command.second);
				std::cout << "DONE\n";
			}
		}
		else if (command.first == "SEARCH") {
			if (tree.Find(command.second)) {
				std::cout << "YES\n";
			}
			else {
				std::cout << "NO\n";
			}
		}
		else if (command.first == "PRINTTREE") {
			tree.Print();
		}
	}
}
