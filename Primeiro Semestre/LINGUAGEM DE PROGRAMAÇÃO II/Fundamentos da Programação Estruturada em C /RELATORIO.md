# Fundamentos da Programação Estruturada em C

## 1. Objetivo

O programa foi desenvolvido para automatizar o cálculo do salário semanal de
funcionários de uma empresa prestadora de serviços. Ele solicita o nome do
funcionário, a quantidade de horas trabalhadas e o valor da hora. Quando a
jornada ultrapassa 40 horas semanais, cada hora excedente recebe adicional de
50%.

## 2. Lógica utilizada

O cálculo foi implementado na função `calcularSalario()`. Foram consideradas
as seguintes situações:

- até 40 horas: `salário = horas trabalhadas × valor da hora`;
- acima de 40 horas: `salário = salário das 40 horas regulares + salário das
  horas extras`;
- cada hora extra vale `valor da hora × 1,5`.

Por exemplo, um funcionário que trabalhou 45 horas e recebe R$ 20,00 por hora
tem o seguinte salário:

```text
Horas regulares: 40 × R$ 20,00 = R$ 800,00
Horas extras:     5 × R$ 20,00 × 1,5 = R$ 150,00
Salário total:   R$ 950,00
```

## 3. Conceitos de programação empregados

- variáveis dos tipos `char`, `int` e `double`;
- constantes para o limite semanal e o adicional de hora extra;
- operadores aritméticos, relacionais e lógicos;
- estruturas condicionais `if` e `else`;
- laços `do...while` e `while`;
- função com parâmetros e valor de retorno;
- validação das entradas numéricas.

O laço principal permite calcular o salário de vários funcionários sem
reiniciar o programa. Os demais laços solicitam novamente uma informação
quando o usuário digita um valor inválido ou negativo.

## 4. Compilação e execução

No terminal, dentro do diretório da atividade, devem ser usados os comandos:

```bash
gcc -std=c11 -Wall -Wextra -pedantic calculo_salario.c -o calculo_salario
./calculo_salario
```

## 5. Testes realizados

| Horas | Valor da hora | Horas extras | Salário esperado |
|---:|---:|---:|---:|
| 30 | R$ 20,00 | 0 | R$ 600,00 |
| 40 | R$ 20,00 | 0 | R$ 800,00 |
| 45 | R$ 20,00 | 5 | R$ 950,00 |
| 50 | R$ 15,00 | 10 | R$ 825,00 |

Também foram testadas entradas negativas e textos no lugar de números. Nessas
situações, o programa informa que a entrada é inválida e solicita um novo
valor.

## 6. Conclusão

O programa atende ao problema apresentado, pois calcula automaticamente o
salário semanal, diferencia horas regulares de horas extras e aplica o adicional
de 50%. A organização do cálculo em uma função torna o código mais legível e
facilita sua manutenção.

## 7. Referências

KERNIGHAN, B. W.; RITCHIE, D. M. *The C Programming Language*. 2. ed.
Englewood Cliffs: Prentice Hall, 1988.

DEITEL, P.; DEITEL, H. *C: How to Program*. Pearson.
