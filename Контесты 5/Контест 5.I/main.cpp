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

	void LeftNextRight(Node<T>* currNode, std::vector<T>& output) {
		if (currNode == nullptr) {
			return;
		}
		LeftNextRight(currNode->left, output);
		output.push_back(currNode->data);
		LeftNextRight(currNode->right, output);
	}

	void LeftNextRightLeafs(Node<T>* currNode, std::vector<T>& output) {
		if (currNode == nullptr) {
			return;
		}
		if ((currNode->left == nullptr) && (currNode->right == nullptr)) {
			output.push_back(currNode->data);
		}
		LeftNextRightLeafs(currNode->left, output);
		LeftNextRightLeafs(currNode->right, output);
	}

	void LeftNextRightInterNodes(Node<T>* currNode, std::vector<T>& output) {
		if (currNode == nullptr) {
			return;
		}
		LeftNextRightInterNodes(currNode->left, output);
		if ((currNode->left != nullptr) && (currNode->right != nullptr)) {
			output.push_back(currNode->data);
		}
		LeftNextRightInterNodes(currNode->right, output);
	}

	void LeftNextRightHalfNodes(Node<T>* currNode, std::vector<T>& output) {
		if (currNode == nullptr) {
			return;
		}
		LeftNextRightHalfNodes(currNode->left, output);
		if (((currNode->left == nullptr) && (currNode->right != nullptr)) ||
			((currNode->left != nullptr) && (currNode->right == nullptr))) {
			output.push_back(currNode->data);
		}
		LeftNextRightHalfNodes(currNode->right, output);
	}

	bool CheckBalance(Node<T>* currNode) {
		if (currNode == nullptr) {
			return true;
		}
		int leftHeight = TreeHeight(currNode->left);
		int rightHeight = TreeHeight(currNode->right);
		if (std::abs(leftHeight - rightHeight) > 1) {
			return false;
		}
		return CheckBalance(currNode->left) && CheckBalance(currNode->right);
	}

public:
	BinaryTree() {
		root = nullptr;
	}

	bool Find(T key) {
		Node<T>* interNode = Search(key, root);
		if (interNode == nullptr) {
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

	void DeleteMax() {
		root = Erase(SearchMaxNode(root)->data, root);
	}

	std::vector<T> GetNodesInNonDecreaseOrder() {
		std::vector<T> output;
		LeftNextRight(root, output);
		return output;
	}

	std::vector<T> GetLeafsInNonDecreaseOrder() {
		std::vector<T> output;
		LeftNextRightLeafs(root, output);
		return output;
	}

	std::vector<T> GetInterNodesInNonDecreaseOrder() {
		std::vector<T> output;
		LeftNextRightInterNodes(root, output);
		return output;
	}

	std::vector<T> GetHalfNodesInNonDecreaseOrder() {
		std::vector<T> output;
		LeftNextRightHalfNodes(root, output);
		return output;
	}

	T GetMax() {
		return SearchMaxNode(root)->data;
	}

	void Print() {
		PrintTree(root, 0);
	}

	bool IsBalanced() {
		return CheckBalance(root);
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

	if (tree.IsBalanced()) {
		std::cout << "YES\n";
	}
	else {
		std::cout << "NO\n";
	}
}