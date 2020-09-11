// Arbol Binario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <memory>
/*class Node
{
public:
	Node(const int& _key) : key(_key) { //, left(nullptr), right(nullptr) {
		printf("Construyendo Nodo\n");
	};
	Node(const std::shared_ptr<Node>& old) : key(old->key) {//, left(old.left), right(old.right) {
		printf("Usando Copy Constructor");
	};
	~Node() {
		printf("Destruyendo Nodo\n");
	};
	const int getKey() {
		return key;
	}
	void setLeft(const std::shared_ptr<Node>& _left) {
		left = _left;
	}
	std::shared_ptr<Node> getLeft() const {
		return left;
	}
	void setRight(const std::shared_ptr<Node>& _right) {
		right = _right;
	}
	std::shared_ptr<Node> getRight() const {
		return right;
	}
private:
	int key;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
};

class BST
{
public:
	BST() {};
	~BST() {};
	void add(const int& key) {
		root = agregar(root, key);
	}
	void show() {
		mostrar(root);
	}
	void minimo() {
		min(root);
	}
	void maximo() {
		max(root);
	}

private:
	void min(const std::shared_ptr<Node>& x) {
		if (!x->getLeft()) {
			printf("\nMinimo elemento del arbol binario: %d\n", x->getKey());
			return;
		}
		min(x->getLeft());
	}
	void max(const std::shared_ptr<Node>& x) {
		if (!x->getRight()) {
			printf("\nMaximo elemento del arbol binario: %d\n", x->getKey());
			return;
		}
		min(x->getRight());
	}
	std::shared_ptr<Node> agregar(const std::shared_ptr<Node>& x, const int& _key) {
		if (!x){// == nullptr) {
			return std::make_shared<Node>(_key);
		}
		else {
			if (x->getKey() >= _key) {
				x->setLeft(agregar(x->getLeft(), _key));
			}
			else if (x->getKey() < _key) {
				x->setRight(agregar(x->getRight(), _key));
			}
		}
		return x;
	}
	void mostrar(const std::shared_ptr<Node>& x) {
		if (x == nullptr) return;
		mostrar(x->getLeft());
		printf("%d ", x->getKey());
		mostrar(x->getRight());
	}
	std::shared_ptr<Node> root;

};


int main()
{
	{
		BST tree;
		tree.add(25);
		tree.add(15);
		tree.add(35);
		tree.show();
		tree.minimo();
		tree.maximo();
	}
	std::cin.get();
	return 0;
}*/

#include <iostream>

class Node {
	int* key;
	int count;
	Node* left;
	Node* right;
public:
	Node() = default;
	Node(const int& _key): key(new int(_key)), count(1), left(nullptr), right(nullptr)	{
		printf("Construyendo un nodo\n");
	}
	Node(const Node& other)
	: key(new int(*(other.key))), count(other.count), left(other.left), right(other.right){
		printf("Copy constructor de nodos");
	}
	Node(Node&& other) noexcept {
		//other.~Node();
		printf("Move constructor de node");
		this->key = other.key;
		this->count = other.count;
		this->left = other.left;
		this->right = other.right;
		other.key = nullptr;
		other.left = nullptr;
		other.right = nullptr;
		other.count = 0;
	}
	Node& operator=(Node&& other) noexcept {
		other.~Node();
		printf("Move asignment operator de node");
		this->key = other.key;
		this->count = other.count;
		this->left = other.left;
		this->right = other.right;
		other.key = nullptr;
		other.left = nullptr;
		other.right = nullptr;
		other.count = 0;
		return *this;
	}
	Node& operator=(const Node& other) {
		printf("Asignment operator de nodos");
		if (this != &other)
		{
			this->key = other.key;
			this->count = other.count;
			this->left = other.left;
			this->right = other.right;
		}
		return *this;
	}

	~Node() {
		printf("Destruyendo nodos\n");
		delete key;
		delete left;
		delete right;
	}

	const int* getKey() {
		return key;
	}
	void setLeftNode(Node* _left) {
		left = _left;
	}
	Node* getLeftNode() {
		return  left;
	}
	void setRightNode(Node* _right) {
		right = _right;
	}
	Node* getRightNode() {
		return right;
	}
	void setCount(const int& _count) {
		count = _count;
	}
	const int getCount() {
		return count;
	}
};

class BST {
	Node* root = nullptr;
	
	Node* put(Node* x, const int& _key) {
		if (!x) // como nullptr = 0 y en bool false = 0, entonces esta bien decir !x = x = nullptr
		{
			return new Node(_key);
		}
		int key = *(x->getKey());
		if (_key < key)
		{
			x->setLeftNode(put(x->getLeftNode(), _key));
		}
		else {
			if (_key > key)
			{
				x->setRightNode(put(x->getRightNode(), _key));
			}
		}
		x->setCount(1 + size(x->getLeftNode()) + size(x->getRightNode()));
		return x;
	}
	const int size(Node* x) {
		if (!x) return 0; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		return (x->getCount());
	}
	const void show(Node* x) {
		if (!x) return; // como nullptr = 0 y en bool false = 0, entonces esta bien decir !x = x = nullptr
		//cout<< *(x->getKey())<<" "; //preorder;
		show(x->getLeftNode());
		std::cout << *(x->getKey()) << " "; //inorder;
		show(x->getRightNode());
		//std::cout<<*(x->getKey())<<" "; //postorder;
	}
	void fixCount(Node* x) {
		x->setCount(1 + size(x->getLeftNode()) + size(x->getRightNode()));
	}
	void Min(Node* x) {
		if (!x) return; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		else if (!x->getLeftNode()) {
			std::cout << "\nEl dato minimo del arbol es: " << *(x->getKey()) << std::endl;
		}
		Min(x->getLeftNode());
	}
	void Max(Node* x) {
		if (!x) return; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		if (!x->getRightNode()) {
			std::cout << "\nEl dato maximo del arbol es: " << *(x->getKey()) << std::endl;
		}
		Max(x->getRightNode());
	}
	Node* borrarMin(Node* x) {
		if (!x->getLeftNode()) return nullptr; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		x->setLeftNode(borrarMin(x->getLeftNode()));
		fixCount(x);
	}
	Node* borrarMax(Node* x) {
		if (!x->getRightNode()) return nullptr; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		x->setRightNode(borrarMax(x->getRightNode()));
		fixCount(x);
	}
	const void get(Node* x, const int& _key) {
		if (x == nullptr) return;
		if (_key < *(x->getKey())) get(x->getLeftNode(), _key);
		else if (_key > * (x->getKey())) get(x->getRightNode(), _key);
		else std::cout << "\nSe encontro el dato " << *(x->getKey()) << std::endl;
	}
	Node* floor(Node* x, const int& _key) {
		if (!x) { return x; } // como nullptr = 0 y en bool false = 0, entonces esta bien decir !x = x = nullptr
		//int cmp = compareTo(_key, x->getKey());
		int key = *(x->getKey());
		if (_key == key)
		{
			return x;
		}
		//if(cmp < 0) return floor(x->getLeftNode(), _key);
		if (_key < key)
		{
			return floor(x->getLeftNode(), _key);
		}
		Node* t = floor(x->getRightNode(), _key);
		//if(t != NULL) return t;
		if (t) // como nullptr = 0 y en bool false = 0, entonces esta bien decir t = t != nullptr
		{
			return t;
		}
		else
		{
			return x;
		}
	}
	Node* ceiling(Node* x, const int& _key) {
		Node* larger = NULL;
		while (x) { // como nullptr = 0 y en bool false = 0, entonces esta bien decir x == x != nullptr
			int key = *(x->getKey());
			if (_key == key)
			{
				return x;
			}
			else if (_key < key) {
				larger = x;
				x = x->getLeftNode();
			}
			else {
				x = x->getRightNode();
			}
		}
		return larger;
	}
	int rank(Node* x, const int& _key) {// how many keys < kth
		if (!x) return 0; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		int key = *(x->getKey());
		if (_key < key)
		{
			return rank(x->getLeftNode(), _key);
		}
		else if (_key > key)
		{
			return 1 + size(x->getLeftNode()) + rank(x->getRightNode(), _key);
		}
		else {
			return size(x->getLeftNode());
		}
	}
	Node* deleteMin(Node* x) {
		if (!x->getLeftNode()) // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		{
			return x->getRightNode();
		}
		x->setLeftNode(deleteMin(x->getLeftNode()));
		x->setCount(1 + size(x->getLeftNode()) + size(x->getRightNode()));
		return x;
	}
	Node* eliminar(Node* x, const int& _key) {
		if (!x) return NULL; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		int key = *(x->getKey());
		if (_key < key) x->setLeftNode(eliminar(x->getLeftNode(), _key));
		else if (_key > key) x->setRightNode(eliminar(x->getRightNode(), _key));
		else {
			if (!x->getRightNode()) return x->getLeftNode(); // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
			if (!x->getLeftNode()) return x->getRightNode(); // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr

			Node* t = x;
			x->setRightNode(deleteMin(t->getRightNode()));
			x->setLeftNode(t->getLeftNode());
		}
		x->setCount(size(x->getLeftNode()) + size(x->getRightNode()) + 1);
		return x;
	}
	Node* altura(Node* x, int& high, int _high = 1) {
		if (!x) {
			if (--_high > high) high = _high;
			return x;
		}
		altura(x->getLeftNode(), high, ++_high);
		--_high;
		altura(x->getRightNode(), high, ++_high);
		return x;
	}
public:
	~BST() { delete root; }
	void put(const int& _key) {
		root = put(root, _key);
	}
	const int size() {
		return size(root);
	}
	const void mostrar() {
		show(root);
	}
	const void altura() {
		int high = 0;
		altura(root, high);
		std::cout << "\nHeight of the binary search tree: " << high << "\n";
	}
	const void Min() {
		Min(root);
	}
	const void Max() {
		Max(root);
	}
	void deleteMin() {
		borrarMin(root);
	}
	void deleteMax() {
		root = borrarMax(root);
	}
	void get(const int& _key) {
		get(root, _key);
	}
	const void minKey() {
		Node* x = root;
		while (x->getLeftNode()) { //x->getLeftNode() != NULL
			x = x->getLeftNode();
		}
		std::cout << "\nEl minimo elemento del arbol es: " << *(x->getKey()) << std::endl;
	}
	const void maxKey() {
		Node* x = root;
		while (x->getRightNode()) {
			x = x->getRightNode();
		}
		std::cout << "\nEL maximo elemento del arbol es: " << *(x->getKey()) << std::endl;
	}
	const int floor(const int& _key) {
		Node* x = floor(root, _key);
		if (!x) return 0; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		return *(x->getKey());
	}
	const int ceiling(const int& _key) { //analizar ceiling
		Node* x = ceiling(root, _key);
		if (!x) return 0; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		return *(x->getKey());
	}
	const int rank(const int& _key) {
		return rank(root, _key);
	}
	//hibbard deletion		
	void eliminar(const int& _key) {
		root = eliminar(root, _key);
	}
	
};

int main() {

	/*{
		BST arbol;
		arbol.put(80);
		arbol.put(60);
	}*/
	{
		BST* arbol = new BST;
		arbol->put(80);
		arbol->put(50);
		arbol->put(60);
		arbol->put(90);
		arbol->put(85);
		arbol->put(105);
		arbol->put(3);
		arbol->put(55);
		arbol->put(73);
		arbol->put(66);
		arbol->put(68);
		arbol->put(86);
		arbol->put(70);
		std::cout << "\nCantidad de Nodos en el arbol :" << arbol->size() << std::endl;
		arbol->mostrar();
		arbol->altura();
		std::cout << std::endl;
		arbol->Min();
		arbol->Max();
		arbol->deleteMin();
		arbol->mostrar();
		std::cout << std::endl;
		arbol->deleteMax();
		arbol->mostrar();
		std::cout << std::endl;
		std::cout << "\nCantidad de Nodos en el arbol :" << arbol->size() << std::endl;
		arbol->get(85);
		arbol->minKey();
		arbol->maxKey();
		std::cout << arbol->floor(55) << std::endl;
		std::cout << arbol->ceiling(55) << std::endl;
		std::cout << arbol->rank(50) << std::endl;
		arbol->eliminar(70);
		std::cout << "\nCantidad de Nodos en el arbol :" << arbol->size() << std::endl;
		arbol->mostrar();
		arbol->altura();
		std::cout << std::endl;
		
	}
	system("pause");
	std::cin.get();
	return 0;
}


