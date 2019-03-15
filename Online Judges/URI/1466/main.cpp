#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int value;
    Node* left, *right;
};

class Tree {
private:
    Node *root = nullptr;
public:
    void add_node(int v) {
        if(root == nullptr) {
            root = new Node;
            root->value = v;
            root->left = root->right = nullptr;
        } else {
            Node *aux = root, *previous;
            while(true) {
                previous = aux;
                if(v > aux->value) {
                    aux = aux->right;
                } else {
                    aux = aux->left;
                }

                if(aux == nullptr)
                    break;
            }
            Node* n = new Node{v,nullptr,nullptr};
            if(previous->value < v) {
                previous->right = n;
            } else {
                previous->left = n;
            }
        }
    }

    void breath() {
        queue<Node *>q;
        int first = 1;
        Node *aux;
        q.push(root);

        while(!q.empty()) {
            aux = q.front();
            if(!first)
                cout << " ";
            cout << aux->value;
            if(aux->left != nullptr)
                q.push(aux->left);
            if(aux->right != nullptr)
                q.push(aux->right);
            q.pop();
            first = 0;
        }
        cout << endl << endl;
    }

    void remove_tree(Node *no) {
        if(no != nullptr) {
            remove_tree(no->left);
            remove_tree(no->right);
            delete no;
            no = nullptr;
        }
    }

    void clear_tree() {
        remove_tree(root);
        root = nullptr;
    }

    ~Tree() {
        clear_tree();
    }
};
int main()
{
    int t, n, v, c = 1;
    Tree tr;
    cin >> t;
    while(t--) {
        cin >> n;
        while(n--) {
            cin >> v;
            tr.add_node(v);
        }

        cout << "Case " << c++ << ":\n";
        tr.breath();
        tr.clear_tree();
    }

    return 0;
}
