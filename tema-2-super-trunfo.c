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

// funcao para mostar o resultado da comparacao e retornar o valor da vitoria, positivo para a carta 1, negativo para a carta 2 e zero para empate
float resultComparisonAttribute(const char *attribute, const char *text1, const char *text2, float value1, float value2)
{
  printf("Comparacao das cartas (Atributo: %s):\n", attribute);
  printf("\n");

  printf("Carta 1 - %s\n", text1);
  printf("Carta 2 - %s\n", text2);

  if (value1 > value2)
  {
    printf("Resultado: Carta 1 venceu!\n");
    return 1.0;
  }
  else if (value1 < value2)
  {
    printf("Resultado: Carta 2 venceu!\n");
    return -1.0;
  }
  else
  {
    printf("Resultado: Empate!\n");
    return 0.00;
  }
}

// funcao para comparar os atributos das cartas
void compareAttrubutes(Card card1, Card card2, int currentOption, float *result)
{
  const char *atribute;
  float cardResult1, cardResult2;
  char cardText1[256], cardText2[256];

  switch (currentOption)
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
    printf("Opcao invalida. Digite novamente!\n");
    printf("\n");
    return;
  }

  *result += resultComparisonAttribute(atribute, cardText1, cardText2, cardResult1, cardResult2);
}

// funcao para escolher a opcao da comparacao
void selectOption(Card card1, Card card2, int currentOption, int *option)
{
  if (currentOption != 1)
    printf("1 - Comparar Populacao\n");
  if (currentOption != 2)
    printf("2 - Comparar Area\n");
  if (currentOption != 3)
    printf("3 - Comparar PIB\n");
  if (currentOption != 4)
    printf("4 - Comparar Pontos Turisticos\n");
  if (currentOption != 5)
    printf("5 - Comparar Densidade Populacional\n");
  if (currentOption != 6)
    printf("6 - Comparar PIB per Capita\n");
  printf("7 - Mostar cartas\n");

  printf("\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", option);
  printf("\n");

  if (*option == 7)
  {
    printCard(card1);
    printf("\n");
    printCard(card2);
    printf("\n");
    selectOption(card1, card2, currentOption, option);
    return;
  }

  // validando a opcao escolhida
  if (currentOption == *option)
  {
    printf("Essa escolha ja foi feita. Escolha outra!\n");
    printf("\n");

    // chamando a funcao novamente caso a opcao ja tenha sido escolhida
    selectOption(card1, card2, currentOption, option);
    return;
  }
  else if (*option < 1 || *option > 7)
  {
    printf("Opcao invalida. Digite novamente!\n");
    printf("\n");

    // chamando a funcao novamente caso a opcao seja invalida
    selectOption(card1, card2, currentOption, option);
    return;
  }
}

int main()
{
  // Cartas pre-definidas
  Card card1 = {1, "Sao Paulo", "S01", "Sao Paulo", 12345678, 1523.45, 345678.90, 10, 8092.34, 28000.67};
  Card card2 = {2, "Rio de Janeiro", "R02", "Rio de Janeiro", 6789012, 1200.67, 234567.89, 8, 5654.78, 34567.89};

  // imprimindo as cartas
  printCard(card1);
  printf("\n");
  printCard(card2);
  printf("\n");

  // armazenando a escolha do primeiro e segundo atributo
  int firstOption = 0, secondOption = 0;
  // armazenando o resultado da vitoria
  float result = 0.0;

  // menu para selecionar os atributos a serem comparados da primeira carta
  selectOption(card1, card2, 0, &firstOption);
  compareAttrubutes(card1, card2, firstOption, &result);
  printf("\n");

  // menu para selecionar os atributos a serem comparados da segunda carta
  selectOption(card1, card2, firstOption, &secondOption);
  compareAttrubutes(card1, card2, secondOption, &result);
  printf("\n");

  // imprimindo o resultado final
  if (result > 0)
    printf("Resultado final: Carta 1 venceu!\n");
  else if (result < 0)
    printf("Resultado final: Carta 2 venceu!\n");
  else
    printf("Resultado final: Empate!\n");

  return 0;
}