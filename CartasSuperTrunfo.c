#include <stdio.h>

// Definindo a estrutura para a carta
typedef struct
{
  int id;
  char state[100];
  char code[4];
  char cityName[100];
  unsigned long int population;
  float area;
  float pib;
  int numberTouristAttractions;
  float populationDensity;
  float pibPerCapita;
} Card;

// funcao para imprimir os dados da carta
void printCard(Card card)
{
  printf("Carta %d:\n", card.id);
  printf("Estado: %s\n", card.state);
  printf("Codigo: %s\n", card.code);
  printf("Nome da Cidade: %s\n", card.cityName);
  printf("Populacao: %lu\n", card.population);
  printf("Area: %.2f km quadrados\n", card.area);
  printf("PIB: %.2f bilhoes de reais\n", card.pib);
  printf("Numero de Pontos Turisticos: %d\n", card.numberTouristAttractions);
  printf("Densidade Populacional: %.2f hab/km quadrados\n", card.populationDensity);
  printf("PIB per Capita: %.2f reais\n", card.pibPerCapita);
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
  printf("\n");
  printCard(*card);
}

// funcao para calcular o super poder da carta
float calculateSuperPower(Card card)
{
  float inverseDensity = 1 / card.populationDensity;

  float superPower = (float)card.population + card.area + card.pib +
                     (float)card.numberTouristAttractions + card.pibPerCapita +
                     inverseDensity;

  return superPower;
}

// funcao para imprimir o resultado da comparacao
void printComparisonResult(const char *type, float value1, float value2)
{
  int comparisonResult = value1 > value2;

  if (value1 > value2)
    printf("%s: Carta 1 venceu (%d)\n", type, comparisonResult);
  else if (value1 < value2)
    printf("%s: Carta 2 venceu (%d)\n", type, comparisonResult);
  else
    printf("%s: Empate\n", type);
}

// funcao para comparar as cartas
void compareCards(Card card1, Card card2)
{
  float superPower1 = calculateSuperPower(card1);
  float superPower2 = calculateSuperPower(card2);

  printf("Comparacao de Cartas:\n");

  printComparisonResult("Populacao", (float)card1.population, (float)card2.population);
  printComparisonResult("Area", card1.area, card2.area);
  printComparisonResult("PIB", card1.pib, card2.pib);
  printComparisonResult("Pontos Turisticos", (float)card1.numberTouristAttractions, (float)card2.numberTouristAttractions);
  printComparisonResult("Densidade Populacional", card2.populationDensity, card1.populationDensity);
  printComparisonResult("PIB per Capita", card1.pibPerCapita, card2.pibPerCapita);
  printComparisonResult("Super Poder", superPower1, superPower2);
}

// funcao para comparar os atributos das cartas
void resultComparisonAttribute(const char *attribute, const char *text1, const char *text2, float value1, float value2)
{
  printf("Comparacao das cartas (Atributo: %s):\n", attribute);
  printf("\n");

  printf("Carta 1 - %s\n", text1);
  printf("Carta 2 - %s\n", text2);

  if (value1 > value2)
    printf("Resultado: Carta 1 venceu!\n");
  else if (value1 < value2)
    printf("Resultado: Carta 2 venceu!\n");
  else
    printf("Resultado: Empate!\n");
}

// menu para escolher qual atributo comparar
void menuCompareAtributes(Card card1, Card card2)
{
  int option;

  printf("1 - Comparar Populacao\n");
  printf("2 - Comparar Area\n");
  printf("3 - Comparar PIB\n");
  printf("4 - Comparar Pontos Turisticos\n");
  printf("5 - Comparar Densidade Populacional\n");
  printf("6 - Comparar PIB per Capita\n");
  printf("\n");

  printf("Digite a opcao desejada: ");
  scanf("%d", &option);
  printf("\n");

  float cardResult1, cardResult2;
  const char *atribute;
  char cardText1[256], cardText2[256];

  switch (option)
  {
  case 1:
    atribute = "Populacao";
    cardResult1 = (float)card1.population;
    cardResult2 = (float)card2.population;
    sprintf(cardText1, "%s (%s): %lu", card1.state, card1.cityName, card1.population);
    sprintf(cardText2, "%s (%s): %lu", card1.state, card1.cityName, card2.population);
    break;
  case 2:
    atribute = "Area";
    cardResult1 = card1.area;
    cardResult2 = card2.area;
    sprintf(cardText1, "%s (%s): %.2f km quadrados", card1.state, card1.cityName, card1.area);
    sprintf(cardText2, "%s (%s): %.2f km quadrados", card1.state, card1.cityName, card2.area);
    break;
  case 3:
    atribute = "PIB";
    cardResult1 = card1.pib;
    cardResult2 = card2.pib;
    sprintf(cardText1, "%s (%s): %.2f bilhoes de reais", card1.state, card1.cityName, card1.pib);
    sprintf(cardText2, "%s (%s): %.2f bilhoes de reais", card1.state, card1.cityName, card2.pib);
    break;
  case 4:
    atribute = "Pontos Turisticos";
    cardResult1 = (float)card1.numberTouristAttractions;
    cardResult2 = (float)card2.numberTouristAttractions;
    sprintf(cardText1, "%s (%s): %d", card1.state, card1.cityName, card1.numberTouristAttractions);
    sprintf(cardText2, "%s (%s): %d", card1.state, card1.cityName, card2.numberTouristAttractions);
    break;
  case 5:
    atribute = "Densidade Populacional";
    cardResult1 = card2.populationDensity;
    cardResult2 = card1.populationDensity;
    sprintf(cardText1, "%s (%s): %.2f hab/km quadrados", card1.state, card1.cityName, card1.populationDensity);
    sprintf(cardText2, "%s (%s): %.2f hab/km quadrados", card1.state, card1.cityName, card2.populationDensity);
    break;
  case 6:
    atribute = "PIB per Capita";
    cardResult1 = card1.pibPerCapita;
    cardResult2 = card2.pibPerCapita;
    sprintf(cardText1, "%s (%s): %.2f reais", card1.state, card1.cityName, card1.pibPerCapita);
    sprintf(cardText2, "%s (%s): %.2f reais", card1.state, card1.cityName, card2.pibPerCapita);
    break;
  default:
    printf("Opcao invalida\n");
    return;
  }

  resultComparisonAttribute(atribute, cardText1, cardText2, cardResult1, cardResult2);
}

int main()
{
  // Card card1, card2;

  // // Chamando a funcao para criar as cartas
  // printf("\n");
  // createCard(&card1, 1);
  // printf("\n");
  // createCard(&card2, 2);
  // printf("\n");

  // // Chamando a funcao para comparar as cartas
  // compareCards(card1, card2);
  // printf("\n");

  // Cartas pre-definidas
  Card card1 = {1, "Sao Paulo", "S01", "Sao Paulo", 12345678, 1523.45, 345678.90, 10, 8092.34, 28000.67};
  Card card2 = {2, "Rio de Janeiro", "R02", "Rio de Janeiro", 6789012, 1200.67, 234567.89, 8, 5654.78, 34567.89};

  printCard(card1);
  printf("\n");
  printCard(card2);
  printf("\n");

  // Chamando menu para escolher qual atributo comparar
  menuCompareAtributes(card1, card2);
  printf("\n");

  return 0;
}