#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais --- 
#define MAX_LIVROS 50
#define MAX_EMPRSTIMOS 100 // Definirmos uma capacidade para emprestimos
#define TAM_STRING 100

// --- Definição de Estruturas ---
// Strucr Livro agora tem um campo "disponivel" para controlar o status
struct Livro
{
  char nome[TAM_STRING];
  char autor[TAM_STRING];
  char editora[TAM_STRING];
  int edicao;
  int disponivel; // 1 para disponível, 0 para emprestado
};

//  Nova struct para armazenar informações de emprestimos
struct Emprestimo
{
  char indiceLivro; // Para saber qual livro do arrey "biblioteca" foi emprestado;
  char nomeUsuario[TAM_STRING];
};

// --- Função para limpar o buffer de entrada ---
void limparBuffer()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// --- Funçao Principal (main) ---

int main(){
  // 1. ALOCAÇÃO DINÂMICA DE MEMORIA
  // Agora, em vez de arrays estáticos, usamos ponteiros
  struct Livro *biblioteca;
  struct Emprestimo *emprestimos;

  // Usamos calloc para o array de livros. calloc (num_elementos, tamanho_de_cada_elemento)
  // Vantagem: incializa toda a memoria com zeros. 
  biblioteca = (struct Livro *)calloc(MAX_LIVROS, sizeof(struct Livro));
  
  //IUsamos malloc para o arrauy de emprestimos. malloc(tamanho_total_em_bytes)
  emprestimos = (struct Emprestimo *)malloc(MAX_EMPRSTIMOS * sizeof(struct Emprestimo));

  // VERFICAÇÃO:É crucial verificar se a alocação da memoria deu certo.
  if (biblioteca == NULL || emprestimos == NULL)
  {
    printf("Erro ao alocar memoria!\n");
    return 1; // Retorna 1 para indicar erro  
  }

  int totalLivros = 0; // Contador para o número de livros cadastrados
  int totalEmprestimos = 0; // Contador para o número de emprestimos realizados
  int opcao;

  do
  {
    printf("===========================\n");
    printf("BIBLIOTECA PARTE 2\n");
    printf("===========================\n");
    printf("1. Cadastrar Livro\n");
    printf("2. Listar todos os Livros\n");
    printf("3. Realizar Emprestimo\n");
    printf("4. Listar Emprestimos\n");
    printf("5. Sair\n");
    printf("-------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer(); // Limpa o buffer após ler a opção

    switch (opcao)
    {
    case 1: //CADASTRAR LIVRO
    printf("--- Cadastro de Novo Livro ---\n");
    if (totalLivros < MAX_LIVROS)
    {
      // o acesso aos campos é igual ao do array estático
      printf("Nome do Livro: ");
      fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

      // ... (demais leituras são iguai à Parte 1 do projeto)      
    }
