#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Aresta {
    int origem, destino, peso;
};

// definição de um conjunto disjunto
class ConjuntoDisjunto {
public:
    ConjuntoDisjunto(int tamanho) {
        pai.resize(tamanho);
        nivel.resize(tamanho, 0);
        for (int i = 0; i < tamanho; ++i)
            pai[i] = i;
    }

    int encontrar(int v) {
        if (v != pai[v])
            pai[v] = encontrar(pai[v]);
        return pai[v];
    }

    void unir(int x, int y) {
        int raizX = encontrar(x);
        int raizY = encontrar(y);

        if (raizX == raizY) return;

        if (nivel[raizX] < nivel[raizY])
            pai[raizX] = raizY;
        else if (nivel[raizX] > nivel[raizY])
            pai[raizY] = raizX;
        else {
            pai[raizY] = raizX;
            nivel[raizX]++;
        }
    }

private:
    vector<int> pai;
    vector<int> nivel;
};

// comparação para ordenar as arestas
bool compararArestas(const Aresta &a, const Aresta &b) {
    return a.peso < b.peso;
}

// calcular o custo mínimo de iluminação
int custoMinimoIluminacao(int m, vector<Aresta> &arestas) {
    int custoTotal = 0;
    ConjuntoDisjunto conjunto(m);

    // ordenar as arestas pelo peso
    sort(arestas.begin(), arestas.end(), compararArestas);

    for (const auto &aresta : arestas) {
        int origem = aresta.origem;
        int destino = aresta.destino;

        // if p verificar adição da aresta forma um ciclo
        if (conjunto.encontrar(origem) != conjunto.encontrar(destino)) {
            conjunto.unir(origem, destino);
        } else {
            // Se forma ciclo, essa aresta não é necessária para aarvore resultado
            custoTotal += aresta.peso;
        }
    }

    return custoTotal;
}

int main() {
    int m, n;
    while (cin >> m >> n && (m != 0 || n != 0)) {
        vector<Aresta> arestas(n);
        for (int i = 0; i < n; ++i) {
            cin >> arestas[i].origem >> arestas[i].destino >> arestas[i].peso;
        }

        int custoMinimo = custoMinimoIluminacao(m, arestas);
        cout << custoMinimo << endl;
    }

    return 0;
}
