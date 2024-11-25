#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int valor;
    Node* nodos[2]; // nodos[0] -> izquierdo, nodos[1] -> derecho
    sf::CircleShape shape;
    sf::Text text;
    Node(int v) : valor(v), shape(20) {
        nodos[0] = nodos[1] = nullptr;
        shape.setFillColor(sf::Color::Green);
    }
};

struct Tree {
    Node* Root;
    sf::Font font;

    Tree(Node* raiz = nullptr) : Root(raiz) {
        if (!font.loadFromFile("Arial.ttf")) {
            cout << "No se pudo cargar la fuente." << endl;
            exit(1);
        }
    }

    ~Tree() { delete Root; }
    void Add(int v);
    void Del(int v);
    bool Find(Node**& Linea, int v);
    Node** Rep(Node** Linea);
    void Draw(sf::RenderWindow& window, Node* n, float x, float y, float offsetX, float offsetY);
    void Inorder(Node* n);
    void Print();
};

void Tree::Add(int v) {
    Node** p = &Root;
    while (*p) {
        p = &((*p)->nodos[v < (*p)->valor]);
    }
    *p = new Node(v);
}

bool Tree::Find(Node**& Linea, int v) {
    Linea = &Root;
    while (*Linea && (*Linea)->valor != v) {
        Linea = &((*Linea)->nodos[(*Linea)->valor < v]);
    }
    return *Linea != nullptr;
}

void Tree::Del(int v) {
    Node** p;
    if (!Find(p, v)) { return; }
    // Caso 2: Nodo con dos hijos
    if ((*p)->nodos[0] && (*p)->nodos[1]) {
        Node** q = Rep(p);
        (*p)->valor = (*q)->valor;
        p = q;
    }
    // Caso 1 y caso 0
    Node* temp = *p;
    *p = (*p)->nodos[(*p)->nodos[1] != nullptr];
    delete temp;
}

Node** Tree::Rep(Node** Linea) {
    Linea = &(*Linea)->nodos[0];
    while ((*Linea)->nodos[1]) {
        Linea = &(*Linea)->nodos[1];
    }
    return Linea;
}
void Tree::Draw(sf::RenderWindow& window, Node* n, float x, float y, float offsetX, float offsetY) {
    if (n) {
        n->shape.setPosition(x - 20, y - 20);
        window.draw(n->shape);

        // Configurar el texto (valor del nodo)
        n->text.setString(std::to_string(n->valor));
        n->text.setFont(font);  // Asignar la fuente
        n->text.setCharacterSize(100);
        n->text.setFillColor(sf::Color::Blue);
        n->text.setPosition(x - 10, y - 10); // Ajusta el texto dentro del círculo
        window.draw(n->text);  

        // Dibujar las conexiones
        if (n->nodos[0]) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y)),
                sf::Vertex(sf::Vector2f(x - offsetX, y + offsetY))
            };
            window.draw(line, 2, sf::Lines);
            Draw(window, n->nodos[0], x - offsetX, y + offsetY, offsetX / 2, offsetY);
        }
        if (n->nodos[1]) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y)),
                sf::Vertex(sf::Vector2f(x + offsetX, y + offsetY))
            };
            window.draw(line, 2, sf::Lines);
            Draw(window, n->nodos[1], x + offsetX, y + offsetY, offsetX / 2, offsetY); // Llamada recursiva
        }
    }
}

void Tree::Inorder(Node* n) {
    if (n) {
        Inorder(n->nodos[0]);
        cout << n->valor << "\t";
        Inorder(n->nodos[1]);
    }
}

void Tree::Print() {
    Inorder(Root);
}

int main() {

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Visualización de Árbol Binario");

    Tree Arbol;
    Arbol.Add(10);
    Arbol.Add(5);
    Arbol.Add(15);
    Arbol.Add(3);
    Arbol.Add(7);
    Arbol.Add(12);
    Arbol.Add(17);

    Arbol.Del(17);
    Arbol.Del(3);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana y dibujar el árbol
        window.clear();
        Arbol.Draw(window, Arbol.Root, 400, 50, 100, 80);
        window.display();
    }

    return 0;
}
