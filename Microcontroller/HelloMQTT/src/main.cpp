// Chris Bass - Coventry University
// 13/04/2019
// Secure encrypted MQTT with TLS/SSL using the ESP32 esp32doit-devkit-v1
// main.cpp
// This program provides an example of sending and receiving data via the MQTT publish-subscribe protocol

#include <Arduino.h>

const int SERIAL_0_SPEED = 9600;
const int LEDPort = 32;
//bool LEDSet = false;

/*
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#include "mqttcert.h"

WiFiClientSecure espClient;
PubSubClient mqttClient(espClient);

long lastMsgTimer = 0;
const int onboardLED = 2; // GPIO2 (D2) on the DOIT-ESP32-DevKitV1

void blinkLED(int times) {
    for (int i = 0; i < times; i++) {
        digitalWrite(onboardLED, HIGH);
        delay(200);
        digitalWrite (onboardLED, LOW);
        delay(200);
    }
}

// The receivedCallback() function will be invoked when this client receives data about the subscribed topic:
void receivedCallback(char* topic, byte* payload, unsigned int length) {
    Serial.print("Message received on topic:  ");
    Serial.print(topic);
    Serial.print("  Message reads:  ");
    for (int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
    //Turns LED on and of based upon MQTT message sent.
    if ((char)payload[0] == 'O' && (char)payload[1] == 'N'){
        digitalWrite(LEDPort, HIGH);
    }
    else if((char)payload[0] == 'O' && (char)payload[1] == 'F' && (char)payload[2] == 'F'){
        digitalWrite(LEDPort, LOW);
    }
    
    Serial.println();
    blinkLED(2);
}

// The mqttConnect() function will attempt to connect to MQTT and subscribe to a topic feed:
void mqttConnect() {
    while (!mqttClient.connected()) {

        Serial.print("In mqttConnect(), connecting...  ");

        if (mqttClient.connect(MQTT_CLIENT_ID, MQTT_USERNAME.c_str(), MQTT_PASSWORD)) {
            Serial.println("...connected to mqtt server!");
            blinkLED(3);
            Serial.print("Subscribing to topic:  ");
            Serial.println(MQTT_TOPIC_NAME.c_str());

            // Subscribe topic with default QoS 0
            // Let's just subscribe to the same feed we are publishing to, to see if our message gets recorded.
            mqttClient.subscribe(MQTT_TOPIC_NAME.c_str());

        } else {
            Serial.println("...mqttConnect() failed, status code =");
            Serial.println(mqttClient.state());
            Serial.println("try again in 5 seconds...");
            delay(5000); // Wait 5 seconds before retrying
        }
    }
}
*/
void setup() {
    pinMode(LEDPort, OUTPUT);
    digitalWrite(LEDPort, LOW);
    digitalPinHasPWM(LEDPort)
/*
    Serial.begin(SERIAL_0_SPEED);
    Serial.println("Starting LED test");

    pinMode(onboardLED, OUTPUT);
    Serial.begin(9600);
    Serial.println();
    Serial.println();
    Serial.println("Hello MQTT program");
    Serial.print("Attempting to connect to WiFi SSID:  ");
    Serial.println(WIFI_SSID);
    blinkLED(1);
    Serial.print("Connecting");
    
    // We start by connecting to a WiFi network
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    blinkLED(2);
    Serial.print("IP address:  ");
    Serial.println(WiFi.localIP());

    Serial.println("Setting up MQTT...");
    
    // We need a certificate in order to do a __secure__ TLS/SSL connection to our server
    espClient.setCACert(CA_CERT);

    // Port 1883 is reserved with IANA for use with MQTT.
    // TCP/IP port 8883 is also registered, for using MQTT over SSL.
    // help url:  http://www.iotsharing.com/2017/08/how-to-use-esp32-mqtts-with-mqtts-mosquitto-broker-tls-ssl.html
    mqttClient.setServer(MQTT_SERVER, 8883); // Port 8883 for MQTT over SSL.

    // The receivedCallback() function will be invoked when this client receives the subscribed topic:
    mqttClient.setCallback(receivedCallback);
*/
}

void loop() {
    /* For basic LED turn on test.
    digitalWrite(LEDPort, HIGH);
    delay(2000);
    digitalWrite(LEDPort, LOW);
    delay(2000);
    */

   
   //PWM

   // mqttConnect();

    // this function will listen for incoming subscribed topic processes and invoke receivedCallback()
    //mqttClient.loop();
    /* Used for sending data
    // we send a reading every 5 secs
    // we count until 5 secs reached to avoid blocking program (instead of using delay())
    long now = millis();
    if (now - lastMsgTimer > 5000) {
        lastMsgTimer = now;

        // just convert time stamp to a c-string and send as data:
        String dataToSend = String(LEDSet); // dataToSend could be a sensor reading instead
        Serial.println();
        Serial.print("Publishing data:  ");
        Serial.println(dataToSend);
        blinkLED(1);
        mqttClient.publish(MQTT_TOPIC_NAME.c_str(), dataToSend.c_str());
    }
    if (LEDSet == 1)
        LEDSet = 0;
    else if (LEDSet == 0)
        LEDSet = 1;
        */
}
