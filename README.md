# Monitoramento da Cápsula Órion com ESP32

## Sobre o Projeto

Este projeto foi desenvolvido com o objetivo de monitorar grandezas físicas críticas para o correto funcionamento da cápsula espacial Órion, utilizando conceitos de Internet das Coisas (IoT) e sistemas embarcados.

A solução foi implementada na plataforma de simulação Wokwi utilizando um microcontrolador ESP32, sensores para aquisição de dados e um display OLED para visualização em tempo real das informações coletadas.

O sistema realiza o monitoramento contínuo de:

* Temperatura
* Luminosidade
* Corrente elétrica (simulada por potenciômetro)

---

## Objetivos

* Monitorar as condições ambientais da cápsula Órion.
* Realizar a aquisição de dados através de sensores.
* Processar as informações coletadas pelo ESP32.
* Exibir os resultados em tempo real em um display OLED.
* Simular uma aplicação de IoT voltada ao contexto aeroespacial.

---

## 🛠️ Componentes Utilizados

| Componente                   | Quantidade |
| ---------------------------- | ---------- |
| ESP32 DevKit V1              | 1          |
| Sensor DHT22                 | 1          |
| Sensor de Luminosidade (LDR) | 1          |
| Potenciômetro                | 1          |
| Display OLED SSD1306 128x64  | 1          |

---

## Ligações

### DHT22

| DHT22 | ESP32  |
| ----- | ------ |
| VCC   | 3V3    |
| DATA  | GPIO15 |
| GND   | GND    |

### Sensor de Luminosidade

| Sensor LDR | ESP32  |
| ---------- | ------ |
| VCC        | 3V3    |
| GND        | GND    |
| AO         | GPIO34 |

### Potenciômetro

| Potenciômetro | ESP32  |
| ------------- | ------ |
| VCC           | 3V3    |
| GND           | GND    |
| SIG           | GPIO35 |

### Display OLED

| OLED SSD1306 | ESP32  |
| ------------ | ------ |
| VCC          | 3V3    |
| GND          | GND    |
| SDA          | GPIO21 |
| SCL          | GPIO22 |

---

## Funcionamento

O ESP32 realiza a leitura contínua dos sensores conectados ao sistema.

* O DHT22 fornece os valores de temperatura.
* O sensor LDR mede a intensidade luminosa do ambiente.
* O potenciômetro simula a leitura de corrente elétrica da cápsula.

Após a aquisição dos dados, o microcontrolador processa as informações e exibe os resultados no display OLED.

O sistema também verifica limites pré-definidos para identificar situações de alerta, permitindo o acompanhamento das condições operacionais da cápsula em tempo real.

---

## Tecnologias Utilizadas

* C++
* ESP32
* Wokwi
* OLED SSD1306
* DHT22
* Sensores Analógicos

---

## Conceitos Aplicados

* Internet das Coisas (IoT)
* Sistemas Embarcados
* Monitoramento em Tempo Real
* Aquisição de Dados
* Sensoriamento Ambiental
* Simulação Eletrônica

---

## Autores

| NOME                                  | RM     |
| ------------------------------------  | ------ |
| Mateus de Oliveira Fernandes Neves    | 572431 |
| Marcelo do Nascimento Batista Pereira | 569410 |
| Nathan Hiroshi Watanabe               | 572806 |

Projeto desenvolvido para fins acadêmicos, demonstrando a integração entre sensores, sistema embarcado e interface de visualização para monitoramento da cápsula Órion.
