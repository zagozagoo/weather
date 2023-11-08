#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;
    char line[200];
    char date[20];
    int year, month, day;

    file = fopen("weather_data.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo de dados meteorologicos.\n");
        return 1;
    }

    printf("Insira ano, mes e dia, respectivamente, para visualizar a previsao:\n");
    scanf("%d %d %d", &year, &month, &day);
    printf("Previsao para a data %d-%02d-%02d:\n", year, month, day);

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%*s%19s", date))
        {
            int line_year, line_month, line_day;
            if (sscanf(date, "%d %d %d", &line_year, &line_month, &line_day) == 3)
            {
                if (line_year == year && line_month == month && line_day == day)
                {
                    printf(line);
                    while (fgets(line, sizeof(line), file) && strcmp(line, "\n") != 0)
                    {
                        printf("%s", line);
                    }
                    break;
                }
            }
        }
        else
        {
            printf("Opcao invalida. Escolha 1 para visualizar previsao por data ou 2 para sair.\n");
        }
    }

    fclose(file);
    return 0;
}

