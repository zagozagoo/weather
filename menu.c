#include <stdio.h>
#include <string.h>

int main() {
  FILE *file;
  char line[200];
  char date[20];
  int year, month, day;

  file = fopen("weather_data.txt", "r");

  if (file == NULL) {
    printf("Erro ao abrir o arquivo de dados metereologicos.\n");
    return 1;
  }
  printf("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
  printf("█             _                 _           █\n");
  printf("             | |               | |           \n");
  printf("         ___ | | ___  _   _  __| |___        \n");
  printf("        / __|| |/ _ \\| | | |/ _` / __|      \n");
  printf("       | (__ | | (_) | |_| | (_| \\__ \\     \n");
  printf("        \\___||_|\\___/ \\__,_|\\__,_|___/   \n");
  printf("█                                           █\n");
  printf("█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█\n");
  
  printf("\nInsira ano, mes e dia, respectivamente, para visualizar a previsao:\n");
  scanf("%d %d %d", &year, &month, &day);
  printf("Previsao para a data %d-%02d-%02d:\n", year, month, day);

  while (fgets(line, sizeof(line), file) != NULL) // lê cada linha do arquivo e armazena a linha na variável "line"
  {
    if (sscanf(line, "%*s %10s", date) == 1) // pula a primeira palavra da linha em "line" e armazena a segunda palavra em "date"
    {
      int line_year, line_month, line_day;
      if (sscanf(date, "%04d-%02d-%02d", &line_year, &line_month, &line_day) == 3) // pega a data em "date" e armazena o dia, o mês e o ano em variáveis separadas
      {
        if (line_year == year && line_month == month &&
            line_day == day) // se os valores inseridos pelo usuário forem
                             // iguais ao da linha, printa a linha 
        {
          if (strcmp(";",";") == 0);
          printf("|");
        }
      }
    }
  }

  fclose(file);
  return 0;
}

