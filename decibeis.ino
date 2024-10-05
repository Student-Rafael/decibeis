
//190 - 47dB
//192 - 70dB
//193 - 78dB
//195 - 86dB


const int sensorPin = A0;
int valorSom;
int maiorValor = 0;  // Variável para armazenar o maior valor

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  valorSom = analogRead(sensorPin);

  // Exibe todos os valores lidos quando o valor for maior que 195
  if (valorSom > 210) {
    Serial.print("Nível de som: ");
    Serial.println(valorSom);

    // Atualiza o maior valor se o valor atual for maior
    if (valorSom > maiorValor) {
      maiorValor = valorSom;
      // Exibe o maior valor
    Serial.print("Maior nível de som até agora: ");
    Serial.println(maiorValor);
    }

  }

}

