#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matriz) {
    const int linhas = matriz.size();
    const int colunas = matriz[0].size();
    int resposta = 0;
    vector<vector<int>> memoria(linhas, vector<int>(colunas));

    for (int i = 0; i < linhas; ++i)
      for (int j = 0; j < colunas; ++j)
        resposta = max(resposta, buscaProfundidade(matriz, i, j, INT_MIN, memoria));

    return resposta;
  }

 private:
  int buscaProfundidade(const vector<vector<int>>& matriz, int i, int j, int anterior,
          vector<vector<int>>& memoria) {
    if (i < 0 || i == matriz.size() || j < 0 || j == matriz[0].size())
      return 0;
    if (matriz[i][j] <= anterior)
      return 0;
    int& resposta = memoria[i][j];
    if (resposta > 0)
      return resposta;

    const int atual = matriz[i][j];
    return resposta = 1 + max(max(max(buscaProfundidade(matriz, i + 1, j, atual, memoria),
                                      buscaProfundidade(matriz, i - 1, j, atual, memoria)),
                                buscaProfundidade(matriz, i, j + 1, atual, memoria)),
                              buscaProfundidade(matriz, i, j - 1, atual, memoria));
  }
};

int main() {
    // A função main foi escrita apenas para quem quiser testaruma vez que não é necessária pro LeetCode.
    // Dessa forma, quem quiser testar o código via terminal conseguirá =)
    
    cout << "Digite o número de linhas e colunas da matriz: ";
    int linhas, colunas;
    cin >> linhas >> colunas;

    cout << "Digite os elementos da matriz:" << endl;
    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cin >> matriz[i][j];
        }
    }

    Solution solucao;
    int resultado = solucao.longestIncreasingPath(matriz);
    cout << "O comprimento do caminho mais longo crescente é: " << resultado << endl;

    return 0;
}
