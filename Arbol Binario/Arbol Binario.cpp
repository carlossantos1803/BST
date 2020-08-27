// Arbol Binario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <memory>
class Node
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
}

