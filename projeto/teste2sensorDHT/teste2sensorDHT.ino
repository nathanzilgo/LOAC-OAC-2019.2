#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup(){

  Serial.begin(9600);
  Serial.println("Aguardando dados...");

  dht.begin();
}

void loop(){
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if(isnan(h) || isnan(t)){
    Serial.println("Falha ao ler dados do sensor!");
    return;
  }

  //PRINTA TEMP NO MONITOR
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");

  // PRINTA UMIDADE NO MONITOR
  Serial.print("Umidade: ");
  Serial.print(h);
  Serial.println(" %");
  
}
