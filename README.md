# Tarefa Clock e Temporizadores - Atividade 02: Temporizador de um disparo (One Shot). 
 
Este projeto implementa o controle de três LEDs usando a placa Raspberry Pi Pico e um botão para iniciar uma sequência de desligamento com temporizadores.

## Descrição

Ao pressionar o botão conectado ao pino GPIO 5, os três LEDs (conectados aos pinos GPIO 11, 12 e 13) acendem simultaneamente. Em seguida, após 3 segundos, os LEDs se apagam um a um com intervalos de 3 segundos entre cada desligamento. O botão fica desativado enquanto a sequência está em execução para evitar interrupções.

## Hardware Utilizado

- Raspberry Pi Pico
- 3 LEDs
- 3 resistores de 220Ω (um para cada LED)
- 1 Botão push-button
- Jumpers e protoboard

## Pinos Utilizados

- **LED1**: GPIO 11
- **LED2**: GPIO 12
- **LED3**: GPIO 13
- **BUTTON**: GPIO 5

## Bibliotecas Necessárias

- pico/stdlib.h
- hardware/gpio.h
- hardware/timer.h

## Funcionamento

1. Inicializa os pinos dos LEDs como saída e do botão como entrada com pull-up interno.
2. Configura uma interrupção no botão para detectar borda de subida (pressionamento).
3. Ao pressionar o botão, todos os LEDs acendem e inicia uma sequência de desligamento com temporizadores:
   - Após 3 segundos, LED1 apaga.
   - Após mais 3 segundos, LED2 apaga.
   - Após mais 3 segundos, LED3 apaga.
4. O sistema fica pronto para uma nova ativação após o término da sequência.

## Compilação

Utilize o SDK do Raspberry Pi Pico com CMake para compilar o código.

## Autor

João Marcelo Nascimento Fernandes - Desenvolvido como parte de estudos de sistemas embarcados.

