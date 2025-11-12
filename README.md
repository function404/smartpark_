# 🚗 SmartPark — Sistema de Estacionamento Inteligente com Arduino

## 👥 Integrantes
- Lincoln  
- Felipe G  
- Gustavo  

## 🎯 Objetivo do Projeto
Desenvolver um **sistema embarcado funcional** chamado **SmartPark**, que simula um **sensor de estacionamento automotivo inteligente**, utilizando **três sensores e dois atuadores**.  
O sistema mede a distância de obstáculos, detecta luminosidade ambiente e monitora a temperatura externa.  
Com base nesses dados, o SmartPark **aciona LEDs e um buzzer** para indicar a proximidade de obstáculos e **liga os faróis automaticamente** e também **altera a visualização de uma possível câmera traseira** quando escurece.

## ⚙️ Componentes Utilizados
| Tipo             | Componente   | Quantidade |
|----------------- | ------------------------------- | - |
| Microcontrolador | Arduino Uno R3                  | 1 |
| Sensor           | HC-SR04 (ultrassônico)          | 1 |
| Sensor           | LDR (luminosidade)              | 1 |
| Sensor           | DHT11 (temperatura e umidade)   | 1 |
| Atuador          | LEDs (verde, amarelo, vermelho) | 3 |
| Atuador          | Buzzer passivo                  | 1 |
| Outros           | Protoboard, resistores, jumpers | - |

## 💰 Custo Estimado
Aproximadamente **R$ 124,50**

## 🔌 Esquema de Montagem
- O **HC-SR04** mede a distância até o obstáculo e envia o sinal ao Arduino.  
  - Quando o obstáculo está longe, **apenas o LED verde** fica aceso.  
  - Conforme o objeto se aproxima, o **LED amarelo** acende e o **buzzer** emite apitos lentos.  
  - Quando o obstáculo está muito próximo, **o LED vermelho** acende e o **buzzer** emite apitos rápidos.  

- O **LDR** detecta a **luminosidade ambiente**.  
  - Se o ambiente estiver escuro, o sistema entende que é **noite** e **liga automaticamente os faróis do carro (simulados por LEDs)** e **altera a câmera traseira para modo noturno**.  

- O **DHT11** monitora a **temperatura ambiente externa** (simulando o sensor de temperatura fora do carro).  
  - Caso a temperatura ultrapasse **40 °C**, o sistema emite um **alerta sonoro e visual** de alta temperatura.  

- O **buzzer** e os **LEDs** trabalham juntos para indicar a distância e o estado do ambiente em tempo real.

## 📸 Demonstração
Video: [VÍDEO DE DEMONSTRAÇÃO](https://youtube.com/shorts/DLMjmrPVE5A?si=olXf0JUsB5tejPfD)

---

📘 **Professor Avaliador:**  
Este repositório contém o código-fonte, documentação e esquema de montagem do **SmartPark**, desenvolvido para a disciplina **Desenvolvimento de Sistemas Embarcados**.
