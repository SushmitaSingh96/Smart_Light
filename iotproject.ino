
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h> 

const char* ssid ="YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* host="YOUR_HOST";


const int ledPin = 5;
const int ldrPin = A0;
WiFiClient client;


void setup() 
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() !=WL_CONNECTED)
  {
    delay(500);
    Serial.print("...");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);

  // Connect to host
  Serial.print("Connecting to ");
  Serial.println(host);

  
  // Use WiFiClient class to create TCP connections
  const int httpPort = 80;
  while(!client.connect(host, httpPort)) 
  {
    Serial.println("Connection failed!");
  }
  Serial.println("Connected");
}

void loop() 
{
  
  int ldrStatus = analogRead(ldrPin);
  Serial.println(ldrStatus);
  if (ldrStatus >=600) 
  {
    digitalWrite(ledPin, HIGH);
    Serial.print(ldrStatus);
    Serial.println(" : LDR is DARK, LED is ON");
  }
  else 
  {
    digitalWrite(ledPin, LOW);
    Serial.print(ldrStatus);
    Serial.println(" : LED is OFF");
  }
   delay(500);
//  Create a URL for the request
  String url = "/index.php?ldrStatus=";
  url += ldrStatus;
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
 client.print(String("GET ") + url +" HTTP/1.1\r\n" +
            "Host: " + host+ ":"  + "\r\n" +
            //"Host: " + host + "\r\n"
             "Connection: close\r\n" +
             "\r\n"
            );
  /*delay(500);
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");*/
/*  unsigned long timeout = millis();
  while (client.available() == 0) 
  {
    if (millis() - timeout > 5000) 
    {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }*/

  while(client.available())
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
  delay(3000);
}
 
  



