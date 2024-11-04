const int PinoSensor = A0; // Pino Analógico de Entrada 0 (Saída do sensor KY-038)
 
int ValorSensor = 0;
int valorMaior = 0;
int cont = 0;
 
void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial
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

}
