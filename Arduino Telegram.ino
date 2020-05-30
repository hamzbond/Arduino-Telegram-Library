#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <TelegramBot.h>

// Initialize Wifi connection to the router
char ssid[] = "";             // your network SSID (name)
char pass[] = "";           // your network key

// Initialize Telegram BOT
const char BotToken[] = ""; //Your Telegram Bot Token

WiFiClientSecure net_ssl;
TelegramBot bot (BotToken, net_ssl);


void setup() {

  Serial.begin(115200);
  while (!Serial); // Wait for the Serial monitor to be opened

  // attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


  bot.begin();

}

void loop() {
 
    message m = bot.getUpdates(); // Read new messages
    if ( m.chat_id != 0 ){ // Checks if there are some updates
      Serial.println(m.text);
      bot.sendMessage(m.chat_id, m.text);  // Reply to the same chat with the same text
    } else {
      Serial.println("no new message");
    }

}
