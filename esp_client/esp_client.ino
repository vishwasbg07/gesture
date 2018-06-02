//receiver program for esp01 
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
const char* ssid     = "MASTER DEVICE";
const char* password = "vishwas123";
const char* host = "192.168.4.1";
void setup() {
  Serial.begin(115200);
  ESP_ARD.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {
  delay(2000);
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
    Serial.print("Requesting URL: ");
  //Serial.println(url);
  // This will send the request to the server
  client.print(String("GET ") + "/ " + " HTTP/1.1\r\n" +
               "Host: " +  + "\r\n" + 
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
    }
  }
  while (client.available()) {

    String line = client.readStringUntil('\n'); 

    if (line=='a'))
    {
      ESP_ARD.write(97);
    }
    else if (line=='b'))
    {
      ESP_ARD.write(98);
    }
    else if (line=='c')
    {
      ESP_ARD.write(99);
    }
    else if (line=='d')
    {
      ESP_ARD.write(100);
    }
    else if (line=='e')
    {
      ESP_ARD.write(122);
    }
  
  }
 }
