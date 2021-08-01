# PACMAN
Este é um jogo simples que se assemelha ao Pacman.

# Objetivo
Praticar a linguagem C e a lógica de programação.

# Dicas
## 1
Caso esteja usando o CLion e a função `fopen` não consiga encontrar o arquivo `mapa.txt`, siga os seguintes passos:
- Clique em *Run*, no menu superior;
- Clique em *Edit Configurations*;
- Na nova janela que abriu, verifique se no lado esquerdo a aplicação está selecionada;
- Clique em *Working directory*
- Selecione o diretório do projeto.

## 2
Para usar a biblioteca `locale.h` no CLion e ver o efeito no terminal do CLion é preciso usar a função `wprintf(L"")`.

## 3
Uso da função `memcpy()` para copiar uma `struct` inteira para outra.
```c
struct contato {
char nome[20];
char email[50];
};
typedef struct contato CONTATO;

int main() {
CONTATO mauricio;
strcpy(mauricio.nome, "Mauricio Aniche");
strcpy(mauricio.email, "mauricio.aniche@caelum.com.br");
}
//Copiar struct inteira
CONTATO aniche;
CONTATO mauricio;

memcpy(&aniche, &mauricio, sizeof(CONTATO));
```

Uso da função `memset()` para inicializar *structs* ou *arrays* com algum valor padrão (geralmente NULO), pois alguns compiladores de C não limpam as regiões de memória antes de liberá-las  para o programador.
```c
CONTATO marcelo;

// 0 significa NULO
memset(&marcelo, 0, sizeof(CONTATO));
```