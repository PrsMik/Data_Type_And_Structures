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

	int TreeHeight(Node<T>* currNode) {
		if (currNode == nullptr) {
			return 0;
		}
		return 1 + std::max(TreeHeight(currNode->left), TreeHeight(currNode->right));
	}

	int TreeSize(Node<T>* currNode) {
		if (currNode == nullptr) {
			return 0;
		}
		return 1 + TreeSize(currNode->left) + TreeSize(currNode->right);
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

	int Size() {
		return TreeSize(root);
	}

	int Height() {
		return TreeHeight(root);
	}

	~BinaryTree() {
		DeleteTree(root);
	}
};

int main() {
	BinaryTree<int> tree;

	while (true) {
		int x;
		std::cin >> x;
		if (x == 0) {
			break;
		}
		tree.Add(x);
	}

	std::cout << tree.Size();
}
