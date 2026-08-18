#include <stdio.h>

/* Limites de temperatura adotados pelo sistema. */
#define TEMPERATURA_MINIMA 18.0f
#define TEMPERATURA_MAXIMA 25.0f

/* Códigos que representam as possíveis ações do sistema. */
#define AQUECER 1
#define RESFRIAR 2
#define ESTAVEL 3

/*
 * Lê e devolve a temperatura informada pelo usuário.
 */
float lerTemperatura(void)
{
    float temperatura;

    printf("Digite a temperatura atual do ambiente (em graus Celsius): ");
    scanf("%f", &temperatura);

    return temperatura;
}

/*
 * Compara a temperatura com os limites e devolve a ação necessária.
 */
int analisarTemperatura(float temperatura)
{
    if (temperatura < TEMPERATURA_MINIMA)
    {
        return AQUECER;
    }
    else if (temperatura > TEMPERATURA_MAXIMA)
    {
        return RESFRIAR;
    }
    else
    {
        return ESTAVEL;
    }
}

/*
 * Exibe a mensagem correspondente à ação escolhida pelo sistema.
 */
void exibirResultado(int resultado)
{
    if (resultado == AQUECER)
    {
        printf("Aquecendo...\n");
    }
    else if (resultado == RESFRIAR)
    {
        printf("Resfriando...\n");
    }
    else
    {
        printf("Temperatura estável.\n");
    }
}

int main(void)
{
    float temperaturaAtual;
    int resultado;

    printf("=== Sistema de Controle de Temperatura ===\n");
    printf("Faixa ideal: %.1f C a %.1f C\n", TEMPERATURA_MINIMA,
           TEMPERATURA_MAXIMA);

    temperaturaAtual = lerTemperatura();
    resultado = analisarTemperatura(temperaturaAtual);
    exibirResultado(resultado);

    return 0;
}
