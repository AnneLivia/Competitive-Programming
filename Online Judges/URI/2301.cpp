#include <iostream>

using namespace std;
class Node {
private:
    int id, index;
    Node *next, *back;
public:
    Node(int value, int index, Node *next = nullptr, Node *back = nullptr) {
        this->id = value;
        this->index = index;
        this->next = next;
        this->back = back;
    }

    void setNext(Node *next) {
        this->next = next;
    }

    void setBack(Node *back) {
        this->back = back;
    }

    Node* getNext() {
       return this->next;
    }

    Node* getBack() {
        return this->back;
    }

    int getValue() const {
        return this->id;
    }
};

class LinkedList {
private:
    Node* head;
    int sz;
public:
    LinkedList() {
        head = nullptr;
        this->sz = 0;
    }

    void addNode(int value) {
        Node *n = new Node(value, ++this->sz);
        if (head == nullptr) {
            head = n;
        } else {
            Node *aux = head;
            while(aux->getNext() != nullptr) {
                aux = aux->getNext();
            }
            aux->setNext(n);
            n->setBack(aux);
        }
    }

    void print() {
        Node *aux = head;
        while(aux != nullptr) {
            cout << aux->getValue() << endl;
            aux = aux->getNext();
        }
    }

    void remove(int c) {
        int cont = 1;
        Node *aux = head;
        while(cont != c && aux != nullptr) {
            aux = aux->getNext();
            cont++;
        }

        if(aux != nullptr) {
            if (aux == head) {
                head = aux->getNext();
                head->setBack(nullptr);
            } else {
                aux->getBack()->setNext(aux->getNext());
                if (aux->getNext() != nullptr) {
                    aux->getNext()->setBack(aux->getBack());
                }
            }
            delete aux;
            aux = nullptr;
            this->sz--;
        }
    }

    void clearTree() {
        
        Node *aux = head, *prev;
        while(aux != nullptr) {
            prev = aux->getNext();
            delete aux;
            aux = prev;
            this->sz--;
        }
        head = nullptr;
    }

    int getFirstValue() {
        return head->getValue();
    }
};

int main() {
    int p, r, x, t = 1, n, j, ac, vet[1001];
    LinkedList l;
    
    while(cin >> p >> r && p && r) {
       
        for (int i = 0; i < p; i++) {
            cin >> x;
           
            l.addNode(x);
        }

        int qtd;
        while(r--) {
            cin >> n >> j;
            qtd = 0;

            for (int i = 1; i <= n; i++) {
                cin >> ac;

                if (ac != j) {
                    vet[qtd++] = i;
                }
            }

            for (int i = qtd-1; i >= 0; i--) {
                l.remove(vet[i]);
            }
        }

        cout << "Teste " << t++ << endl;
        
        cout << l.getFirstValue() << "\n\n";
        
        l.clearTree();
        
    }    
    return 0;  
}
