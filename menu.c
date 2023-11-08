#include <stdio.h>

int main()
{
    FILE *file;
    char line[200];
    char date[20];
    int year, month, day;

    file = fopen ("weather_data.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo de dados metereologicos.\n");
        return 1;
    }

    printf("Insira ano, mes e dia, respectivamente, para visualizar a previsao:\n");
    scanf("%d %d %d", &year, &month, &day);
    printf("Previsao para a data %d-%02d-%02d:\n", year, month, day);

    while (fgets(line, sizeof(line), file) != NULL) /*le cada linha do arqv, fgets le a proxima linha do arqv e armazena na variavel*/
    {
        if (sscanf(line, "%*s%19s", date) == 1)
        {
            int line_year = year, line_month = month, line_day = day;
            if (sscanf(date, "%d %d %d", &line_year, &line_month, &line_day) == 3) /*Verifica se o formato de data esta certo, 3 verifica se sscanf conseguiu atribuir com sucesso 3 valores inteiros às variaveis*/
            {
                printf(line);
                while (fgets(line, sizeof(line), file) && strcmp(line, "\n") != 0)
                {
                    printf("%s", line);
                }
                break;
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
/*if (sscanf(line, "%*s %19s", date) == 1) {: Dentro do loop, esta linha verifica se a linha atual pode ser analisada usando sscanf.
O formato especificado "%*s %19s" é usado para analisar a linha. O %*s ignora a primeira palavra na linha, e
%19s lê e armazena a segunda palavra na variável date. O retorno de sscanf (1 neste caso) indica que a linha foi analisada com sucesso*/


