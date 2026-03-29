# STM32 Display Multiplex — Mensagem Rolante em 7 Segmentos

🇧🇷 **Português** | 🇺🇸 [English](#english)

---

## Português

Exibição de mensagem rolante "feliz aniversario" (21 caracteres) em display de 7 segmentos multiplexado, usando dois timers no STM32F4xx.

### O que faz
- Exibe a mensagem **"feliz aniversario"** (21 chars) em modo scrolling
- **TIM10** multiplexa os dígitos a **500 Hz** (PSC=16000, ARR=1)
- **TIM11** avança o scroll a **1 Hz** (PSC=16000, ARR=1000)
- Decodificação de caracteres alfanuméricos para segmentos A–G

### Configuração dos Timers
```
TIM10: PSC = 16000, ARR = 1  → 500 Hz (multiplexação dos dígitos)
TIM11: PSC = 16000, ARR = 1000 → 1 Hz  (avanço do scroll)
```

### Arquitetura
```
TIM10 IRQ (500 Hz) → seleciona próximo dígito → atualiza segmentos
TIM11 IRQ (1 Hz)   → incrementa índice da mensagem
```

### Microcontrolador
STM32F4xx — Atollic TrueSTUDIO

---

## English

Scrolling message "feliz aniversario" (21 characters) on a multiplexed 7-segment display using two timers on STM32F4xx.

### What it does
- Displays the message **"feliz aniversario"** (21 chars) in scrolling mode
- **TIM10** multiplexes digits at **500 Hz** (PSC=16000, ARR=1)
- **TIM11** advances the scroll at **1 Hz** (PSC=16000, ARR=1000)
- Alphanumeric character decoding to segments A–G

### Timer configuration
```
TIM10: PSC = 16000, ARR = 1    → 500 Hz (digit multiplexing)
TIM11: PSC = 16000, ARR = 1000 → 1 Hz   (scroll advance)
```

### Architecture
```
TIM10 IRQ (500 Hz) → select next digit → update segments
TIM11 IRQ (1 Hz)   → increment message index
```

### MCU
STM32F4xx — Atollic TrueSTUDIO
