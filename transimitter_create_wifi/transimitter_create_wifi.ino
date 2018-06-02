#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>
const char *ssid = "MASTER DEVICE";
const char *password = "vishwas123";
const char *code1 = "Attack a";
const char *code2 = "Follow me b";


ESP8266WebServer server(80);
void handleRoot()
{

  while (ESP_ARD.available())
  {
    char y = ESP_ARD.read();
    if ( y == 97)
    {
      server.send(200, "text/html", code1);
    }
    else if ( y == 98)
    {
      server.send(200, "text/html", code2);
    }
    else if ( y == 99)
    {
      server.send(200, "text/html", code3);
    }
    else if ( y == 100)
    {
      server.send(200, "text/html", code4);

    }
    else if ( y == 101)
    {
      server.send(200, "text/html", code5);
    }

    else if ( y == 102)
    {
      server.send(200, "text/html", code6);

    }
    else if ( y == 103)
    {

      server.send(200, "text/html", code7);

    }
    else if ( y == 104)
    {

      server.send(200, "text/html", code8);

    }
    else if ( y == 105)
    {

      server.send(200, "text/html", code9);

    }
    else if ( y == 106)
    {

      server.send(200, "text/html", code10);

    }

  }
}

void setup()
{
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point1q...");
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/get", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}
void loop()
{

  handleRoot();

}


