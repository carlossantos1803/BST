// Arbol Binario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
class Node
{
public:
	Node(const int& _key) : key(_key), left(nullptr), right(nullptr) {
		printf("Construyendo Nodo\n");
	};
	~Node() {
		printf("Destruyendo Nodo\n");
		delete left;
		delete right;
	};
	const int getKey() {
		return key;
	}
	void setLeft(Node* _left) {
		left = _left;
	}
	Node* getLeft() {
		return left;
	}
	void setRight(Node* _right) {
		right = _right;
	}
	Node* getRight() {
		return right;
	}
private:
	int key;
	Node* left;
	Node* right;
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

private:
	Node* agregar(Node* x, const int& _key) {
		if (x == nullptr) {
			return new Node(_key);
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
	void mostrar(Node* x) {
		if (x == nullptr) return;
		//printf("%d ", x->getKey());
		//if(x!=nullptr)
		mostrar(x->getLeft());
		printf("%d ", x->getKey());
		//if (x != nullptr) 
		mostrar(x->getRight());
		//printf("%d ", x->getKey());
	}
	Node* root = nullptr;

};


int main()
{
	BST tree;
	tree.add(25);
	tree.add(15);
	tree.add(35);
	tree.show();
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
