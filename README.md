# Tarefa 02: Simulação da Raspberry Pi Pico W e comunicação serial via terminal Putty

## Descrição
Nessa tarefa simulamos uma placa Raspberry Pi Pico W conectado a um terminal Putty para controlar três LEDs RGB e um buzzer.
Os seguintes recursos foram implementados:

- **Digitar 1:** Liga o LED verde conectado ao GPIO 11 (desliga todas as outras portas GPIO)
- **Digitar 2:** Liga o LED azul conectado ao GPIO 12 (desliga todas as outras portas GPIO)
- **Digitar 3:** Liga o LED vermelho conectado ao GPIO 13 (desliga todas as outras portas GPIO)
- **Digitar 4:** Liga o LED na cor branca (LED verde, azul e vermelho ligados ao mesmo tempo)
- **Digitar 5:** Desliga todos os LEDS
- **Digitar 6:** Emite um bip de 2 segundos utilizando o Buzzer conectado ao GPIO 21
- **Digitar 7:** Ativa o modo BOOTSEL da Pico W via software <br>
O projeto foi desenvolvido de forma a funcionar também no kit de desenvolvimento BitDogLab.
## Estrutura do Projeto
O projeto foi desenvolvido em C e utiliza o simulador **Wokwi** para emular o circuito. A estrutura de diretórios é organizada para facilitar o desenvolvimento e a compilação com a extensão **Raspberry Pi Pico** no VS Code.

### Diretórios Principais
- src/: Contém o arquivo principal do código-fonte (main.c).
- lib/: Contém os arquivos de cabeçalho (.h) das bibliotecas implementadas e as suas respectivas implementações.
- diagram.json e wokwi.toml: Contém o arquivo de simulação do circuito Wokwi.

## Requisitos
- **Software**:
  - VS Code com a extensão **Raspberry Pi Pico**
  - Simulador **Wokwi**
- **Hardware(opcional)**:
  - **Raspberry Pi Pico W** (no nosso caso utilizaremos o robusto kit de desenvolvimento da BitdogLab
  - **Putty** (para acessar o terminal do nosso microcontrolador)
## Como Compilar e Executar
1. Clone este repositório:
   
```bash
   git clone <https://github.com/lucaasifx/matrix-keypad-task>
```


2. Abra o projeto no VS Code.

3. Certifique-se de que a extensão **Raspberry Pi Pico** e  **Wokwi** estão instaladas e configuradas corretamente.
4. Clique no ícone da extensão da Pico<br>

  ![image](https://github.com/user-attachments/assets/28cdb91b-16e2-4687-a6a1-950f219ddf34)

5. Selecione importar projeto para que a pasta build seja gerada automaticamente:<br>
![image](https://github.com/user-attachments/assets/b0dc78cd-f619-4648-9b5b-d509c65800d7)
  - Selecione o caminho do projeto e clique em Importar<br>
![image](https://github.com/user-attachments/assets/1a15e0c5-de88-4684-bf6d-2684db73ccb9)


6. Navegue até a opção Compilar Projeto:<br>
![image](https://github.com/user-attachments/assets/366a506d-171c-4c30-9577-e61d1575da33)

7. Se desejar testar no simulador, abra o arquivo diagram.json e inicie a simulação. <br>
- Ao iniciar a simulação, **pressione ``ENTER``** para que o menu apareça
![image](https://github.com/user-attachments/assets/3a1e34f8-70cb-4e02-bbf4-d7d2c1c4bdc0)
8. Para realizar os testes com a placa BitDogLab, devemos:
- Colocar a placa no modo BOOTSEL
- Carregar o software compilado na placa utilizando a função Run da extensão Raspberry Pi Pico <br>
![image](https://github.com/user-attachments/assets/7e96e25f-29ef-44f8-bdc0-0a2bceea0327) <br>
![image](https://github.com/user-attachments/assets/1f14244b-483c-48b0-9d1d-b09cf047aaaf)<br>
- Abrir uma sessão no Putty utilizando o modo serial<br>
![image](https://github.com/user-attachments/assets/0e54c0e0-3e06-4279-bdbc-e3f6cbaeff2d)<br>
  - Configurações importantes do Putty:
      - O tipo de conexão deve estar configurado como ``Serial``
      - A velocidade deve estar definida como ``115200`` (padrão da Pico W)
      - A porta serial da placa deve estar corretamente selecionada
- Ao entrar na sessão, deve-se **pressionar ``ENTER``** para exibir o menu <br>
![image](https://github.com/user-attachments/assets/871aa929-7236-40de-9043-90dd53afd340)
- O software está pronto para uso.



## Simulação no Wokwi
O projeto inclui suporte para simulação do circuito utilizando o **Wokwi**. **Após compilar o projeto** basta abrir o arquivo diagram.json e iniciar a simulação.

## Contribuição
Esse projeto foi construído pelos membros do Grupo 04 Subgrupo 08 do EmbarcaTech, uma iniciativa do CEPEDI.
Alunos:
 - Elisson Nadson
 - Lucas Emanoel
 - Davi Moura
 - Ariel Pina
 - Marcus Porto
 - Guilherme Lopes
 - Claudemir da Silva 
