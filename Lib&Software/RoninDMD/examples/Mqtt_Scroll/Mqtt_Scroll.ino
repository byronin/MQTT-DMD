#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <RoninDMD.h>                    // Include lib & font 
#include <fonts/Arial_Black_16.h>
#define FONT Arial_Black_16

#define WIDTH 1                          // Set width & height
#define HEIGHT 1
RoninDMD P10(WIDTH, HEIGHT);

const char *ssid         = "Your-SSID";  // Wi-Fi settings
const char *password     = "SSID-Password";
bool clnt_state = 0 ;

const char *mqtt_broker = "broker.hivemq.com"; // mqtt broker settings
const char *topic = "ronin_dsp_test"; // SET TOPIC !!!
const char *mqtt_username = "";
const char *mqtt_password = "";
const int mqtt_port = 1883;

String Message = "Hi Im Ronin";


WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.println("Connecting to WiFi..");


  }
  Serial.println("Connected to the WiFi network");
  //connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
    String client_id = "TEST-2152";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("mqtt broker connected");
      clnt_state = 1;
    } else {
      clnt_state = 0 ;
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
  P10.begin();              // Begin the display & font
  P10.setFont(FONT);

  P10.setBrightness(20);    // Set the brightness

  P10.drawText(0 , 0, " :) "); // P10.drawText(position x , position y, String type text);
  client.subscribe(topic);
  client.publish("dsp_ronin", "dsp++");
}



void callback(char *topic, byte *payload, unsigned int length) {
  payload[length] = 0;
  Message  = String(( char *) payload);
  delay(100);
  Serial.println(Message);



}

void Scrolling_text(int text_height , int scroll_speed , String scroll_text ) {
  static uint32_t pM ;
  pM = millis();
  static uint32_t x = 0;
  scroll_text = scroll_text + " ";

  bool  scrl_while = 1 ;
  int dsp_width = P10.width();
  int txt_width = P10.textWidth(scroll_text);

  while (scrl_while == 1) {

    P10.loop();
    
    delay(1);
    if (millis() - pM > scroll_speed) {
      P10.setFont(FONT);
      P10.drawText(dsp_width - x, text_height, scroll_text);
      client.loop();

      x++;
      if (x >  txt_width + dsp_width) {

        x = 0 ;
        scrl_while = 0 ;

      }
      pM = millis();

    }


  }

}

void loop() {
  P10.loop();          // Run DMD loop
  client.loop();       // "Message" come from "callback" function
  
  Scrolling_text(0 , 50 , Message );  // Call the function to write scrolling text on screen.
                                      // like -> Scrolling_text( position y , scroll speed, String type text);
                                      // or for not scroll -> P10.drawText(position x , position y, String type text);

  delay(100);



  if (!client.connected()) {
    String client_id = "TEST-2152";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("mqtt broker connected");
      clnt_state = 1;
      client.subscribe(topic);
    } else {
      clnt_state = 0 ;
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}
