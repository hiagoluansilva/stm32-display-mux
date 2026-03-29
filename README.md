# stm32-display-mux

Display de 7 segmentos multiplexado com mensagem rolante no STM32F4xx.

## Descrição

Projeto que controla múltiplos displays de 7 segmentos por multiplexação no tempo, exibindo uma frase rolante caractere a caractere. Cada dígito é ativado individualmente em alta frequência criando a ilusão de todos acesos simultaneamente.

## Hardware

- Microcontrolador: STM32F4xx
- Displays: 7 segmentos (cátodo/ânodo comum)
- Segmentos: GPIOC (PC0–PC6)
- Seletores de dígito: PA0, PA1, PB0, PB1

## Codificação dos segmentos

Tabela de caracteres A–Z mapeada para os 7 segmentos (registros de 7 bits).

## Timers

| Timer | Função |
|-------|--------|
| TIM10 | Multiplexação dos dígitos |
| TIM11 | Velocidade de rolagem da frase |

## Configuração

```c
TIM10->PSC = 16000;  // 1 kHz
TIM10->ARR = 1;       // Troca de dígito a cada 2 ms
TIM11->PSC = 16000;
TIM11->ARR = 1000;    // Rolagem a cada ~1 s
```

## IDE

Atollic TrueSTUDIO 9.3

## Escola

Centro Tecnológico Liberato — Novo Hamburgo/RS
