#include <stdio.h>
#include <stdbool.h>

#define MAX_V 26 //(a-z)
#define MAX_E 100 

bool grafo[MAX_V][MAX_V]; 
bool visitado[MAX_V]; 

void dfs(int v, int n, char *vert, int* comp) {
    visitado[v] = true; 
    vert[(*comp)++] = 'a' + v; 
    for (int i = 0; i < n; i++) {
        if (grafo[v][i] && !visitado[i]) {
            dfs(i, n, vert, comp); 
        }
    }
}

void ordenar_vertices(char* vertices_visitados, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vertices_visitados[j] > vertices_visitados[j + 1]) {
                char temp = vertices_visitados[j];
                vertices_visitados[j] = vertices_visitados[j + 1];
                vertices_visitados[j + 1] = temp;
            }
        }
    }
}

int main() {
    int casos, n, m;
    scanf("%d", &casos); 

    for (int caso = 1; caso <= casos; caso++) {
        scanf("%d %d", &n, &m); 

        for (int i = 0; i < n; i++) {
            visitado[i] = false;
            for (int j = 0; j < n; j++) {
                grafo[i][j] = false;
            }
        }

        for (int i = 0; i < m; i++) {
            char origem, destino;
            scanf(" %c %c", &origem, &destino); 
            grafo[origem - 'a'][destino - 'a'] = true; 
            grafo[destino - 'a'][origem - 'a'] = true; 
        }

        printf("Case #%d:\n", caso); 

        int componentes = 0; 
        char vert[MAX_V];

        for (int i = 0; i < n; i++) {
            if (!visitado[i]) { 
                int comp = 0; 
                dfs(i, n, vert, &comp);
                ordenar_vertices(vert, comp);
                for (int j = 0; j < comp; j++) {
                    printf("%c,", vert[j]);
                    if (j < comp - 1) {
                        // printf(",");
                    }
                }
                printf("\n"); 
                componentes++; 
            }
        }

        printf("%d connected components\n\n", componentes);
    }

    return 0;
}
