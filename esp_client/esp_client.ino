//receiver program for esp01 
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial ESP_ARD(SW_SERIAL_UNUSED_PIN, 2); // RX, TX  |||| RX = ESP8266 = GPIO_2
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
  // Read all the lines of the reply from server and print them to Serial
    while (client.available() == 0) {
    if (millis() - timeout > 2000) {
      Serial.println(">>> Clie Timeout !");
      client.stop();
      return;
    }
  }
  while (client.available()) {

    String line = client.readStringUntil('\r');

    Serial.print(line); 

    if (line.endsWith("a"))
    {
      ESP_ARD.write(97);
    }
    else if (line.endsWith("b"))
    {
      ESP_ARD.write(98);
    }
    else if (line.endsWith("c"))
    {
      ESP_ARD.write(99);
    }
    else if (line.endsWith("d"))
    {
      ESP_ARD.write(100);
    }
    else if (line.endsWith("z"))
    {
      ESP_ARD.write(122);
    }
    else if (line.endsWith("f"))
    {
      ESP_ARD.write(102);
    }
    else if (line.endsWith("g"))
    {
      ESP_ARD.write(103);

    }
    else if (line.endsWith("h"))
    {
      ESP_ARD.write(104);
    }
    else if (line.endsWith("i"))
    {
      ESP_ARD.write(105);
    }
    else if (line.endsWith("j"))
    {
      ESP_ARD.write(106);
    }
  }
 }
