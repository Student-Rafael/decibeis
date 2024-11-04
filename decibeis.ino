const int PinoSensor = A0; // Pino Analógico de Entrada 0 (Saída do sensor KY-038)
const int ledVerde = 3;
const int ledAmarelo = 4;
const int ledVermelho = 5;
 
int ValorSensor = 0;
int valorMaior = 0;
float tensao = 0;
int dB = 0;
int cont = 0;
 
void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
    // Configuração dos pinos dos LEDs
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}
 
void loop() {
  // Coletando dados por um número menor de amostras para reduzir a latência
  while (cont < 1000) {  // Número menor de amostras para respostas mais rápidas
    ValorSensor = analogRead(PinoSensor); // Leitura do sensor KY-038
    if (ValorSensor > valorMaior) {
      valorMaior = ValorSensor; // Armazena o maior valor lido
    }
    cont++;
  }
 
 Serial.print(valorMaior);
  cont = 0; // Reinicia o contador para nova coleta
  tensao = valorMaior / 1023.0 * 4.6; // Ajustado para usar 4.6 como múltiplo
 
  // Cálculo aproximado para decibéis (ajuste conforme a calibração do sensor)
  dB = 50 * tensao; // Ajuste conforme o sensor KY-038
 
  // Garante que o valor de dB não seja negativo
  if (dB < 0) {
    dB = 0;
  }
 
  // Exibe o valor de dB no monitor serial
  Serial.print("Intensidade: ");
  Serial.print(dB);
  Serial.println(" dB");
// Controlando LEDs com base no valor de decibéis
  if (dB < 48) {
    digitalWrite(ledVerde, LOW);    // Som baixo, não acende o LED
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }  
    else if (dB < 65) {
    digitalWrite(ledVerde, HIGH);   // Som considerado, acende o LED Verde
    digitalWrite(ledAmarelo, LOW);  
    digitalWrite(ledVermelho, LOW);
  } else if (dB < 80) {
    digitalWrite(ledVerde, HIGH);   
    digitalWrite(ledAmarelo, HIGH);   // Som médio, acende o LED amarelo
    digitalWrite(ledVermelho, LOW); 
  
  } else {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, HIGH);  
    digitalWrite(ledVermelho, HIGH);  // Som alto, acende o LED Vermelho
  }
 
  valorMaior = 0; // Reinicia o valor máximo para a próxima leitura
 
  delay(10);  // Delay reduzido para 10 ms para respostas mais rápidas

}
