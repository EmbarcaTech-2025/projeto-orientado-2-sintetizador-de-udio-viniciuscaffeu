
# Projetos de Sistemas Embarcados - EmbarcaTech 2025
## Projeto 2: Sintetizador de Áudio para a Placa BitDogLab

<br>

**Autor:** Vinicius Caffeu
<br>
**Curso:** Residência Tecnológica em Sistemas Embarcados
<br>
**Instituição:** EmbarcaTech - HBr

<br>

**Campinas, Junho de 2025**

</div>

---

### **1. Descrição do Projeto**

Este repositório contém o código-fonte para um **Sintetizador de Áudio**, desenvolvido especificamente para a placa **BitDogLab** como parte do segundo projeto orientado do programa EmbarcaTech 2025.

O sistema é projetado para **gravar** áudio utilizando o microfone embutido da placa e **reproduzi-lo** através de seus buzzers. O controle de gravação e reprodução é feito pelos botões A e B, com feedback visual fornecido pelo LED RGB. Adicionalmente, o projeto visa exibir a forma de onda do áudio capturado no display OLED integrado.

---

### **2. Funcionalidades Principais**

* **Gravação de Áudio**: Captura de áudio via microfone embutido, amostrado pelo conversor analógico-digital (ADC).
* **Reprodução de Áudio**: Reprodução do som gravado em um dos buzzers da placa, utilizando modulação por largura de pulso (PWM).
* **Controle Interativo**: Uso dos **botões A e B** para iniciar/parar as operações de gravação e reprodução.
* **Feedback Visual**: Utilização do **LED RGB** para indicar o estado atual do sistema (ex: vermelho para gravando, verde para reproduzindo, azul para ocioso).
* **Visualização de Dados**: Exibição da forma de onda do áudio capturado no **display OLED**.

---

### **3. Parâmetros do Sistema**

Para garantir a viabilidade do projeto dentro das limitações de memória da RP2040, foram definidos os seguintes parâmetros:

* **Taxa de Amostragem:** **8000 Hz**
* **Duração da Gravação:** **2 segundos**
* **Tamanho do Buffer de Áudio:** **16.000 amostras** (8000 Hz × 2s)
* **Resolução da Amostra:** **16 bits** (o buffer será do tipo `uint16_t`)

---

### **4. Estrutura do Projeto**

O projeto é construído em linguagem C de forma estruturada, utilizando o SDK oficial da Raspberry Pi Pico e o sistema de build CMake. A modularização do código é fundamental para a organização.

```
.
├── include/
│   ├── adc_audio.h
│   ├── pwm_audio.h
│   ├── button_control.h
│   ├── oled_display.h
│   └── led_feedback.h
├── src/
│   ├── adc_audio.c
│   ├── pwm_audio.c
│   ├── button_control.c
│   ├── oled_display.c
│   └── led_feedback.c
├── main.c
├── CMakeLists.txt
└── pico_sdk_import.cmake
```

---

### **5. Configuração e Compilação**

O processo de compilação segue o padrão do ambiente de desenvolvimento para a Raspberry Pi Pico.

#### **Pré-requisitos**

* [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)
* Compilador ARM GCC (`arm-none-eabi-gcc`)
* CMake
* Make

#### **Passos para Compilação**

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/EmbarcaTech-2025/projeto-orientado-2-sintetizador-de-udio-viniciuscaffeu.git](https://github.com/EmbarcaTech-2025/projeto-orientado-2-sintetizador-de-udio-viniciuscaffeu.git)
    cd projeto-orientado-2-sintetizador-de-udio-viniciuscaffeu
    ```

2.  **Crie e acesse um diretório de build:**
    ```bash
    mkdir build && cd build
    ```

3.  **Execute o CMake** (aponte para o caminho do seu SDK):
    ```bash
    cmake .. -DPICO_SDK_PATH=/path/to/your/pico-sdk
    ```

4.  **Compile o projeto:**
    ```bash
    make
    ```

5.  Ao final, o arquivo `.uf2` será gerado. Para gravar, arraste este arquivo para a sua BitDogLab quando ela estiver no modo bootloader.

---

### **📜 Licença**

Este projeto é distribuído sob a licença GNU GPL-3.0.
