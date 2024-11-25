#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;

struct Nodes {
    int valor;
    Nodes* nodes[2];
    int altura;
    Nodes(int v) {
        valor = v;
        nodes[0] = nullptr;
        nodes[1] = nullptr;
    }
};

class AvlTree {

    Nodes* m_root = nullptr;
    bool find(int x, Nodes**& p, vector<Nodes*>& rec);
    void Inorder(Nodes* p);
    static int calcularaltura(Nodes* p);
    static int diferenciadealtura(Nodes* p);
    void Ordenamiento(vector<Nodes*>& rec);
    static void draw(Nodes* root);

    void drawTree(Nodes* root) {
        if (!root) {
            cout << "El árbol está vacío." << endl;
            return;
        }

        queue<Nodes*> q;
        q.push(root);

        int height = calcularaltura(root); // Altura del árbol
        int max_width = pow(2, height) - 1;

        vector<vector<string>> levels(height);
        vector<int> spaces(height);

        // Calcular espaciado
        for (int i = 0; i < height; ++i) {
            spaces[i] = (max_width / pow(2, i + 1)) * 3;
        }

        int current_level = 0;
        int nodes_in_level = 1;

        while (!q.empty() && current_level < height) {
            vector<string> level;
            int next_level_nodes = 0;

            for (int i = 0; i < nodes_in_level; ++i) {
                Nodes* node = q.front();
                q.pop();

                if (node) {
                    level.push_back(to_string(node->valor));
                    q.push(node->nodes[0]);
                    q.push(node->nodes[1]);
                    next_level_nodes += 2;
                } else {
                    level.push_back(" ");
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }

            levels[current_level] = level;
            nodes_in_level = next_level_nodes;
            ++current_level;
        }

        // Imprimir árbol
        for (int i = 0; i < height; ++i) {
            cout << string(spaces[i], ' ');
            for (size_t j = 0; j < levels[i].size(); ++j) {
                cout << levels[i][j];
                if (j < levels[i].size() - 1) {
                    cout << string(spaces[i] * 2, ' ');
                }
            }
            cout << endl;
        }
    }

public:
    bool Insert(int x);
    void print();
    void printTree() {
        draw(m_root);
    }
    void printTree2(){
        drawTree(m_root);
    }
};

int AvlTree::calcularaltura(Nodes* p) {
    if (!p) return 0;
    int left = p->nodes[0] ? p->nodes[0]->altura : 0;
    int right = p->nodes[1] ? p->nodes[1]->altura : 0;
    return 1 + max(left, right);
}

int AvlTree::diferenciadealtura(Nodes* p) {
    int left = p->nodes[0] ? p->nodes[0]->altura : 0;
    int right = p->nodes[1] ? p->nodes[1]->altura : 0;

    return right - left;
}

bool AvlTree::find(int x, Nodes**& p, vector<Nodes*>& rec) {
    for (p = &m_root; *p && (*p)->valor != x; p = &((*p)->nodes[(*p)->valor < x])) {
        if (*p != nullptr) {
            rec.push_back(*p);
        }
    }
    return *p && (*p)->valor == x;
}



void AvlTree::Ordenamiento(vector<Nodes*>& rec) {
    for (int i = rec.size() - 1; i >= 0; --i) {
        Nodes* act = rec[i];
        act->altura = calcularaltura(act);
        int balance = diferenciadealtura(act);

        // Caso 1: Rotación LLL
        if (balance == 2 && diferenciadealtura(act->nodes[1]) >= 0) {
            Nodes* temp = act->nodes[1];
            act->nodes[1] = temp->nodes[0];
            temp->nodes[0] = act;
            if (act == m_root) {
                m_root = temp;
            } else {
                Nodes* padre = rec[i - 1];
                padre->nodes[0] == act ? padre->nodes[0] = temp : padre->nodes[1] = temp;
            }
            act->altura = calcularaltura(act);
            temp->altura = calcularaltura(temp);
        }
            // Caso 2: Rotación DDD
        else if (balance == -2 && diferenciadealtura(act->nodes[0]) <= 0) {
            Nodes* temp = act->nodes[0];
            act->nodes[0] = temp->nodes[1];
            temp->nodes[1] = act;
            if (act == m_root) {
                m_root = temp;
            } else {
                Nodes* padre = rec[i - 1];
                padre->nodes[0] == act ? padre->nodes[0] = temp : padre->nodes[1] = temp;
            }
            act->altura = calcularaltura(act);
            temp->altura = calcularaltura(temp);
        }
            // Caso 3: Rotación RRL
        else if (balance == 2 && diferenciadealtura(act->nodes[1]) < 0) {
            Nodes* temp = act->nodes[1];
            Nodes* c = temp->nodes[0];
            temp->nodes[0] = c->nodes[1];
            c->nodes[1] = temp;
            act->nodes[1] = c->nodes[0];
            c->nodes[0] = act;

            if (act == m_root) {
                m_root = c;
            } else {
                Nodes* padre = rec[i - 1];
                padre->nodes[0] == act ? padre->nodes[0] = c : padre->nodes[1] = c;
            }
            act->altura = calcularaltura(act);
            temp->altura = calcularaltura(temp);
            c->altura = calcularaltura(c);
        }
            // Caso 4: Rotación LLR
        else if (balance == -2 && diferenciadealtura(act->nodes[0]) > 0) {
            Nodes* temp = act->nodes[0];
            Nodes* c = temp->nodes[1];
            temp->nodes[1] = c->nodes[0];
            c->nodes[0] = temp;
            act->nodes[0] = c->nodes[1];
            c->nodes[1] = act;

            if (act == m_root) {
                m_root = c;
            } else {
                Nodes* padre = rec[i - 1];
                padre->nodes[0] == act ? padre->nodes[0] = c : padre->nodes[1] = c;
            }
            act->altura = calcularaltura(act);
            temp->altura = calcularaltura(temp);
            c->altura = calcularaltura(c);
        }
    }
}



bool AvlTree::Insert(int x) {
    Nodes** p;
    vector<Nodes*> rec;
    if (find(x, p, rec)) {
        return false;
    }
    *p = new Nodes(x);
    rec.push_back(*p);
    Ordenamiento(rec);
    return true;
}

void AvlTree::Inorder(Nodes* p) {
    if (!p) return;
    Inorder(p->nodes[0]);
    cout << p->valor << " ";
    Inorder(p->nodes[1]);
}


void AvlTree::print() {
    Inorder(m_root);
    cout << endl;
}

void AvlTree::draw(Nodes* root) {
    if (!root) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    // Cola para realizar un recorrido por niveles
    queue<Nodes*> q;
    q.push(root);

    int height = calcularaltura(root); // Altura del árbol
    int max_width = pow(2, height) - 1; // Número máximo de nodos en el nivel más profundo

    vector<vector<string>> levels(height); // Contendrá los valores por nivel
    vector<int> spaces(height); // Espaciado para cada nivel

    // Inicializa espaciado proporcional al nivel
    for (int i = 0; i < height; ++i) {
        spaces[i] = (max_width / pow(2, i + 1)) * 3; // Espaciado entre nodos
    }

    int current_level = 0;
    int nodes_in_level = 1; // Nodos esperados en el nivel actual

    while (!q.empty() && current_level < height) {
        vector<string> level; // Valores en el nivel actual
        int next_level_nodes = 0;

        for (int i = 0; i < nodes_in_level; ++i) {
            Nodes* node = q.front();
            q.pop();

            if (node) {
                level.push_back(to_string(node->valor)); // Añade valor del nodo
                q.push(node->nodes[0]);                 // Agrega hijo izquierdo
                q.push(node->nodes[1]);                 // Agrega hijo derecho
                next_level_nodes += 2;
            } else {
                level.push_back(" "); // Nodo nulo representado como espacio
                q.push(nullptr);
                q.push(nullptr);
            }
        }

        levels[current_level] = level; // Guarda el nivel actual
        nodes_in_level = next_level_nodes; // Actualiza el conteo de nodos
        ++current_level; // Pasa al siguiente nivel
    }

    // Imprimir árbol con formato adecuado
    for (int i = 0; i < height; ++i) {
        // Imprimir espacios iniciales
        cout << string(spaces[i], ' ');

        for (size_t j = 0; j < levels[i].size(); ++j) {
            cout << levels[i][j]; // Imprime el valor del nodo
            if (j < levels[i].size() - 1) {
                cout << string(spaces[i] * 2, ' '); // Espaciado entre nodos
            }
        }
        cout << endl;
    }
}

int main() {
    AvlTree t;
    t.Insert(1);
    t.Insert(8);
    t.Insert(9);
    t.Insert(4);
    t.Insert(7);
    t.Insert(6);
    t.Insert(2);
    t.Insert(3);

    t.print();
    t.printTree();
}
