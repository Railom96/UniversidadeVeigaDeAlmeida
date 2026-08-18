#include <stdio.h>

#define LIMITE_HORAS_REGULARES 40.0
#define ADICIONAL_HORA_EXTRA 1.5
#define TAMANHO_NOME 100

/*
 * Descarta os caracteres que ainda estiverem no buffer de entrada.
 */
void limparEntrada(void)
{
    int caractere;

    while ((caractere = getchar()) != '\n' && caractere != EOF)
    {
        /* O corpo fica vazio porque os caracteres apenas serão descartados. */
    }
}

/*
 * Calcula e devolve o salário semanal. As horas acima de 40 recebem
 * adicional de 50%, ou seja, são pagas com 1,5 vez o valor da hora normal.
 */
double calcularSalario(double horasTrabalhadas, double valorHora)
{
    double salarioRegular;
    double salarioExtra;
    double horasExtras;

    if (horasTrabalhadas > LIMITE_HORAS_REGULARES)
    {
        horasExtras = horasTrabalhadas - LIMITE_HORAS_REGULARES;
        salarioRegular = LIMITE_HORAS_REGULARES * valorHora;
        salarioExtra = horasExtras * valorHora * ADICIONAL_HORA_EXTRA;

        return salarioRegular + salarioExtra;
    }

    return horasTrabalhadas * valorHora;
}

int main(void)
{
    char nome[TAMANHO_NOME];
    char continuar;
    double horasTrabalhadas;
    double valorHora;
    double horasExtras;
    double salarioTotal;
    int leituraValida;

    printf("=== Sistema de Cálculo de Salário Semanal ===\n");

    do
    {
        printf("\nNome do funcionário: ");
        fgets(nome, TAMANHO_NOME, stdin);

        do
        {
            printf("Horas trabalhadas na semana: ");
            leituraValida = scanf("%lf", &horasTrabalhadas);
            limparEntrada();

            if (leituraValida != 1 || horasTrabalhadas < 0.0)
            {
                printf("Entrada inválida. Digite um número maior ou igual a zero.\n");
            }
        } while (leituraValida != 1 || horasTrabalhadas < 0.0);

        do
        {
            printf("Valor da hora (R$): ");
            leituraValida = scanf("%lf", &valorHora);
            limparEntrada();

            if (leituraValida != 1 || valorHora < 0.0)
            {
                printf("Entrada inválida. Digite um número maior ou igual a zero.\n");
            }
        } while (leituraValida != 1 || valorHora < 0.0);

        salarioTotal = calcularSalario(horasTrabalhadas, valorHora);

        if (horasTrabalhadas > LIMITE_HORAS_REGULARES)
        {
            horasExtras = horasTrabalhadas - LIMITE_HORAS_REGULARES;
        }
        else
        {
            horasExtras = 0.0;
        }

        printf("\n--- Resultado ---\n");
        printf("Funcionário: %s", nome);
        printf("Horas trabalhadas: %.2f\n", horasTrabalhadas);
        printf("Horas extras: %.2f\n", horasExtras);
        printf("Valor da hora: R$ %.2f\n", valorHora);
        printf("Salário total: R$ %.2f\n", salarioTotal);

        printf("\nDeseja calcular o salário de outro funcionário? (S/N): ");
        scanf(" %c", &continuar);
        limparEntrada();
    } while (continuar == 'S' || continuar == 's');

    printf("\nPrograma encerrado.\n");

    return 0;
}
