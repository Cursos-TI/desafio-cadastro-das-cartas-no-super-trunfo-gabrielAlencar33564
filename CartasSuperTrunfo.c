#include <stdio.h>

// Definindo a estrutura para a carta
typedef struct
{
  int id;
  float pib;
  float area;
  char code[4];
  char state[100];
  float pibPerCapita;
  char cityName[100];
  float populationDensity;
  unsigned long int population;
  int numberTouristAttractions;
} Card;

// funcao para imprimir os dados da carta
void printCard(Card card)
{
  printf("\n");
  printf("Carta %d:\n", card.id);
  printf("Estado: %c\n", card.state[0]);
  printf("Codigo: %s\n", card.code);
  printf("Nome da Cidade: %s\n", card.cityName);
  printf("Populacao: %lu\n", card.population);
  printf("Area: %.2f km quadrados\n", card.area);
  printf("PIB: %.2f bilhoes de reais\n", card.pib);
  printf("Numero de Pontos Turisticos: %d\n", card.numberTouristAttractions);
  printf("Densidade Populacional: %.2f hab/km quadrados\n", card.populationDensity);
  printf("PIB per Capita: %.2f reais\n", card.pibPerCapita);
  printf("\n");
}

// funcao que sera responsavel por criar as cartas
void createCard(Card *card, int id)
{
  card->id = id;

  // pedindo para o usuario digitar os dados
  printf("Digite o nome do estado: ");
  scanf("%s", card->state);

  printf("Digite o codigo da carta: ");
  scanf("%s", card->code);

  printf("Digite o nome da cidade: ");
  scanf("%s", card->cityName);

  printf("Digite a quantidade de populacao: ");
  scanf("%lu", &card->population);

  printf("Digite o numero de area: ");
  scanf("%f", &card->area);

  printf("Digite o numero de PIB: ");
  scanf("%f", &card->pib);

  printf("Digite o numero de pontos turisticos: ");
  scanf("%d", &card->numberTouristAttractions);

  // calculando a densidade populacional e o PIB per capita
  card->populationDensity = card->area > 0 ? card->population / card->area : 0;
  card->pibPerCapita = card->population > 0 ? card->pib / card->population : 0;

  // imprimindo os dados
  printCard(*card);
}

// funcao para calcular o super poder da carta
long double calculateSuperPower(Card card)
{
  return (long double)card.population + card.area + card.pib +
         card.numberTouristAttractions + card.pibPerCapita +
         (1 / card.populationDensity);
}

// funcao para comparar as cartas
void compareCards(Card card1, Card card2)
{
  long double superPower1 = calculateSuperPower(card1);
  long double superPower2 = calculateSuperPower(card2);

  printf("Comparacao de Cartas:\n");

  printf("Populacao: Carta %d venceu (%d)\n",
         card1.population > card2.population ? card1.id : card2.id,
         card1.population > card2.population);

  printf("Area: Carta %d venceu (%d)\n",
         card1.area > card2.area ? card1.id : card2.id,
         card1.area > card2.area);

  printf("PIB: Carta %d venceu (%d)\n",
         card1.pib > card2.pib ? card1.id : card2.id,
         card1.pib > card2.pib);

  printf("Pontos Turisticos: Carta %d venceu (%d)\n",
         card1.numberTouristAttractions > card2.numberTouristAttractions ? card1.id : card2.id,
         card1.numberTouristAttractions > card2.numberTouristAttractions);

  printf("Densidade Populacional: Carta %d venceu (%d)\n",
         card1.populationDensity < card2.populationDensity ? card1.id : card2.id,
         card1.populationDensity < card2.populationDensity);

  printf("PIB per Capita: Carta %d venceu (%d)\n",
         card1.pibPerCapita > card2.pibPerCapita ? card1.id : card2.id,
         card1.pibPerCapita > card2.pibPerCapita);

  printf("Super Poder: Carta %d venceu (%d)\n",
         superPower1 > superPower2 ? card1.id : card2.id,
         superPower1 > superPower2);
}

int main()
{
  Card card1, card2;

  // Chamando a funcao para criar as cartas
  createCard(&card1, 1);
  createCard(&card2, 2);

  // Chamando a funcao para comparar as cartas
  compareCards(card1, card2);

  return 0;
}