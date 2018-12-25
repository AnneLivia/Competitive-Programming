#include <iostream>

using namespace std;

class Node {
private:
	int value;
	Node* left, *right;
public:
	Node(int value, Node *left, Node *right) : value(value), left(left), right(right) {}
	int getValue() const {
		return this->value;
	}
	Node* getRight() {
		return this->right;
	}
	Node* getLeft() {
		return this->left;
	}
	void setRight(Node *right) {
		this->right = right;
	}

	void setLeft(Node *left) {
		this->left = left;
	}

};

class Binary_tree {
private:
	Node* root;
    bool first = false;
public:
	Binary_tree(int value) {
		this->root = new Node(value, nullptr, nullptr);
	}

	Binary_tree() {
		this->root = nullptr;
	}

	void add_node(int value) {
		Node *aux = root, *previous = nullptr;
		if (root != nullptr) {
			while (aux != nullptr) {
				previous = aux;
				if (value > aux->getValue()) {
					aux = aux->getRight();
				}
				else {
					aux = aux->getLeft();
				}
			}
			if (value > previous->getValue())
				previous->setRight(new Node(value, nullptr, nullptr));
			else
				previous->setLeft(new Node(value, nullptr, nullptr));
		}
		else {
			root = new Node(value, nullptr, nullptr);
		}
	}

	void pre_order(Node *no) {
		if (no != nullptr) {
            if(first)
                cout << " ";
			cout << no->getValue();
			first = true;
			pre_order(no->getLeft());
			pre_order(no->getRight());
		}
	}

    void in_order(Node *no) {
        if(no != nullptr) {
            in_order(no->getLeft());
            if(first)
                cout << " ";
            cout << no->getValue();
            first = true;
            in_order(no->getRight());
        }
    }

    void post_order(Node *no) {
        if(no != nullptr) {

            post_order(no->getLeft());
            post_order(no->getRight());
            if(first)
                cout << " ";
            cout << no->getValue();

            first = true;
        }
    }

	void transverse(int op) {
	    this->first = false;
		switch (op) {
		case 1: cout << "Pre.: "; pre_order(this->root); cout << endl;
			break;
        case 2: cout << "In..: "; in_order(this->root); cout << endl;
            break;
        case 3: cout << "Post: "; post_order(this->root); cout << endl;
            break;
		}
	}

	void free_node(Node *node) {
        if(node != nullptr) {
            free_node(node->getLeft());
            free_node(node->getRight());
            delete node;
        }
	}

	~Binary_tree() {
	    free_node(root);
		root = nullptr;
	}
};

int main()
{
	int t, n, v;
    cin >> t;
    for (int i = 0; i < t; i++) {
        Binary_tree bt;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> v;
            bt.add_node(v);
        }
        cout << "Case " << i + 1 << ":\n";
        for (int j = 0; j < 3; j++) {
            bt.transverse(j + 1);
        }
        cout << endl;
    }

	return 0;
}
