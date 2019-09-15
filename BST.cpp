#include <iostream>

using namespace std;

class BST {
  class Node {
    int* key;
    int count;
    Node* left;
    Node* right;
    public:
    Node (int _key)
		: key(new int(_key)), count(1), left(nullptr), right(nullptr)
		{}
	
    int* getKey(){
        return key;
    }
    void setLeftNode(Node* _left){
        left = _left;
    }
    Node* getLeftNode(){
        return  left;
    }
    void setRightNode(Node* _right){
        right = _right;
    }
    Node* getRightNode(){
        return right;
    }
    void setCount(int _count){
    	count = _count;
	}
	int getCount(){
		return count;
	}
  };
  
    Node* root = 0;  //nullptr = 0;
    
	int size(Node* x){
		if(!x) return 0; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		return (x->getCount()); 
	}
    Node* put(Node* x, int _key){
        if(!x) // como nullptr = 0 y en bool false = 0, entonces esta bien decir !x = x = nullptr
			{return new Node(_key);}
        int key = *(x->getKey());
		if(_key < key) 
			{x->setLeftNode(put(x->getLeftNode(), _key));}
        else {
			if (_key > key) 
				{x->setRightNode(put(x->getRightNode(),_key));}
		}
		x->setCount( 1 + size(x->getLeftNode()) + size(x->getRightNode()));
        return x;
    }
    void show(Node* x){
        if (!x) return; // como nullptr = 0 y en bool false = 0, entonces esta bien decir !x = x = nullptr
        //cout<< *(x->getKey())<<" "; //preorder;
        show(x->getLeftNode());
        cout<< *(x->getKey()) << " "; //inorder;
        show(x->getRightNode());
        //cout<<*(x->getKey())<<" "; //postorder;
    }
	void fixCount(Node * x){
		x->setCount(1 + size(x->getLeftNode()) + size(x->getRightNode()));
	}
    void Min(Node* x) { 
		if (!x) return; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		else if (!x->getLeftNode()) cout << "\nEl dato minimo del arbol es: " << *(x->getKey()) << endl; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		Min(x->getLeftNode());	
	}
	void Max(Node* x) { 
		if (!x) return; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		if (!x->getRightNode()) cout << "\nEl dato maximo del arbol es: " << *(x->getKey()) << endl; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
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
	void get(Node* x, int _key) {
		if (x == nullptr) return;
		if (_key < *(x->getKey())) get(x->getLeftNode(), _key);
		else if (_key > *(x->getKey())) get(x->getRightNode(), _key);
		else cout << "\nSe encontro el dato " << *(x->getKey())<<endl;
	}
   	Node* floor(Node* x, int _key){
		if(!x)
			{return x; } // como nullptr = 0 y en bool false = 0, entonces esta bien decir !x = x = nullptr
		//int cmp = compareTo(_key, x->getKey());
		int key = *(x->getKey());
		if(_key == key) 
			{return x;}
		//if(cmp < 0) return floor(x->getLeftNode(), _key);
		if(_key < key)
			{return floor(x->getLeftNode(), _key);}
		Node* t = floor(x->getRightNode(), _key);
		//if(t != NULL) return t;
		if(t) // como nullptr = 0 y en bool false = 0, entonces esta bien decir t = t != nullptr
			{return t;}
		else 
			{return x;}
	}
	Node* ceiling(Node* x, int _key){
		Node* larger = NULL;
		while(x){ // como nullptr = 0 y en bool false = 0, entonces esta bien decir x == x != nullptr
			int key = *(x->getKey());
			if(_key == key ) 
				{return x;}
			else if (_key < key) {
				larger = x;
				x = x->getLeftNode();	
				}
			else {
				x = x->getRightNode();}
		}
		return larger;
	}
	int rank(Node* x, int _key){// how many keys < kth
		if (!x) return 0; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		int key = *(x->getKey());
		if (_key < key) 
			{return rank(x->getLeftNode(),_key);}
		else if (_key > key) 
				{return 1+ size(x->getLeftNode()) + rank(x->getRightNode(),_key);}
		else{
			 return size(x->getLeftNode());
		}
	}
	Node* deleteMin(Node* x){
		if (!x->getLeftNode()) // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
			{return x->getRightNode();} 
		x->setLeftNode(deleteMin(x->getLeftNode()));
		x->setCount(1 + size(x->getLeftNode()) + size(x->getRightNode()));
		return x;
	}
	Node* eliminar(Node* x, int _key){
		if(!x) return NULL; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
		int key = *(x->getKey());
		if (_key < key) x->setLeftNode(eliminar(x->getLeftNode(),_key));
		else if (_key > key) x->setRightNode(eliminar(x->getRightNode(), _key)) ;
		else{
			if(!x->getRightNode()) return x->getLeftNode(); // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
			if(!x->getLeftNode()) return x->getRightNode(); // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
			
			Node* t = x;
			x->setRightNode(deleteMin(t->getRightNode()));
			x->setLeftNode(t->getLeftNode());
		}
		x->setCount(size(x->getLeftNode()) + size(x->getRightNode()) + 1);
		return x;
	}
	public:
		int size(){
			return size(root);
		}
	    void put(int _key){
	        root = put(root, _key);
	    }
	    void mostrar(){
	        show(root);
	    }
	    void Min(){
	        Min(root);
	    }
	    void Max(){
	        Max(root);
	    }
	    void deleteMin(){
			root = borrarMin(root);
		}
		void deleteMax(){
			root = borrarMax(root);
		}
		void get(int _key){
			get(root, _key);
		}
		int minKey(){
			Node* x = root;
			while(x->getLeftNode()){ //x->getLeftNode() != NULL
				x = x->getLeftNode();
			}
			cout<< "\nEl minimo elemento del arbol es: "<< *(x->getKey())<<endl;
		}
		int maxKey(){
			Node* x = root;
			while(x->getRightNode()){
				x = x->getRightNode();
			}
			cout<<"\nEL maximo elemento del arbol es: "<< *(x->getKey())<<endl;
		}
		int floor(int _key){
			Node* x = floor(root, _key);
			if(!x) return 0; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
			return *(x->getKey());
		}
		int ceiling(int _key){ //analizar ceiling
			Node* x = ceiling(root, _key);
			if(!x) return 0; // como nullptr = 0 y en bool false = 0, entonces esta bien decir x = x = nullptr
			return *(x->getKey());
		}
		int rank(int _key){
			return rank(root, _key);
		}
		//hibbard deletion		
		void eliminar(int _key){
			root = eliminar(root,_key);
		}
};

int main() {
  	
  	BST* arbol = new BST;
	arbol->put(80);
	arbol->put(50);
	arbol->put(60);
	arbol->put(90);
	arbol->put(85);
	arbol->put(105);
	arbol->put(3);
	arbol->mostrar();
	cout<<endl;
	cout << "\nEl tamaño del arbol es :" << arbol->size() << endl;
	arbol->Min();
	arbol->Max();
	arbol->deleteMin();
	arbol->mostrar();
	cout<<endl;
	arbol->deleteMax();
	arbol->mostrar();
	cout<<endl;
	cout << "\nEl tamaño del arbol es :" << arbol->size() << endl;
	arbol->get(85);
	arbol->minKey();
	arbol->maxKey();
    cout << arbol->floor(55) <<endl;
    cout << arbol->ceiling(55) <<endl;
    cout << arbol->rank(50)<<endl;
    arbol->eliminar(85);
    arbol->mostrar();
	cout<<endl;
	cout << "\nEl tamaño del arbol es :" << arbol->size() << endl;
    return 0;
}

