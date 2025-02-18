#include <stdio.h>

// funcao que sera responsavel por criar as cartas
int card(int id)
{
  char state[100];
  char code[4];
  char cityName[100];
  int population;
  float area;
  float pib;
  int numberTouristAttractions;

  // pedindo para o usuario digitar os dados
  printf("Digite o nome do estado: ");
  scanf("%s", state);

  printf("Digite o codigo da carta: ");
  scanf("%s", code);

  printf("Digite o nome da cidade: ");
  scanf("%s", cityName);

  printf("Digite a quantidade de populacao: ");
  scanf("%d", &population);

  printf("Digite o numero de area: ");
  scanf("%f", &area);

  printf("Digite o numero de PIB: ");
  scanf("%f", &pib);

  printf("Digite o numero de pontos turisticos: ");
  scanf("%d", &numberTouristAttractions);

  // imprimindo os dados
  printf("\n");
  printf("Carta %d:\n", id);
  printf("Estado: %c\n", state[0]);
  printf("Codigo: %s\n", code);
  printf("Nome da Cidade: %s\n", cityName);
  printf("Populacao: %d\n", population);
  printf("Area: %.2f km quadrados", area);
  printf("PIB: %.2f bilhoes de reais\n", pib);
  printf("Numero de Pontos Turisticos: %d\n", numberTouristAttractions);
  printf("\n");

  return 0;
}

int main()
{
  // chamando a funcao para criar as cartas
  card(1);
  card(2);

  return 0;
}
