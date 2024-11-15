#include <ESP8266HTTPClient.h>
#include "ssd1306.h"
#include <ESP8266WiFi.h>
#include <Arduino_JSON.h>

const char* SSID = "PRIADI_EXT";
const char* PASSWORD = "prince123**";

String d_server_name = "http://worldtimeapi.org/api/timezone/Asia/Kolkata";
String ny_server_name = "http://worldtimeapi.org/api/timezone/America/New_York";

int _count = 0;
char _countChr[20];

char _ipChr[20];

String ny_time = "--:--";
char ny_date[] = "--/--/--";

String d_time = "--:--";
char d_date[] = "--/--/--";


HTTPClient d_http;
HTTPClient ny_http;
WiFiClient wifi_client;
      

void setup() {
    ssd1306_128x64_i2c_init();
    ssd1306_fillScreen(0x00);

    ssd1306_setFixedFont(ssd1306xled_font6x8);
    ssd1306_printFixed(5, 20, "Connecting to WiFi..", STYLE_BOLD);
    WiFi.begin(SSID,PASSWORD);
    while(WiFi.status() != WL_CONNECTED){
        sprintf(_countChr, "(%ds)", _count);
        ssd1306_printFixed(50, 40, _countChr, STYLE_BOLD);
        delay(1000);
        _count++;
    }

    ssd1306_setFixedFont(ssd1306xled_font6x8);
    ssd1306_fillScreen(0x00);
    ssd1306_printFixed(5, 20, "Connected to WiFi!", STYLE_BOLD);
    WiFi.localIP().toString().toCharArray(_countChr, sizeof(_countChr));
    sprintf(_ipChr, "IP: %s", _countChr);
    ssd1306_printFixed(5, 40, _ipChr, STYLE_BOLD);
    ssd1306_fillScreen(0x00);


    // d_http.setTimeout(5000);
    // ny_http.setTimeout(5000);

}

void loop(){

    if(WiFi.status() == WL_CONNECTED){

        d_http.begin(wifi_client, d_server_name.c_str());
        ny_http.begin(wifi_client, ny_server_name.c_str());

        int d_http_response = d_http.GET();
        int ny_http_response = ny_http.GET();

        if(d_http_response > 0){

            d_time = "";

            String d_payload = d_http.getString();
            JSONVar d_object = JSON.parse(d_payload);
            String d_datetime = d_object["datetime"];

            for(int i = 11; i < 16; i++){
                d_time += d_datetime.charAt(i);
            }

            sprintf(d_date, "%c%c/%c%c/%c%c",d_datetime.charAt(8),d_datetime.charAt(9),d_datetime.charAt(5),d_datetime.charAt(6),d_datetime.charAt(2),d_datetime.charAt(3));
        }


        if(ny_http_response > 0){

            ny_time = "";

            String ny_payload = ny_http.getString();
            JSONVar ny_object = JSON.parse(ny_payload);
            String ny_datetime = ny_object["datetime"];

            for(int i = 11; i < 16; i++){
                ny_time += ny_datetime.charAt(i);
            }

            sprintf(ny_date, "%c%c/%c%c/%c%c",ny_datetime.charAt(8),ny_datetime.charAt(9),ny_datetime.charAt(5),ny_datetime.charAt(6),ny_datetime.charAt(2),ny_datetime.charAt(3));
        }



        ssd1306_setFixedFont(ssd1306xled_font6x8);
        ssd1306_printFixed(69, 20, "NEW DELHI", STYLE_BOLD);
        ssd1306_setFixedFont(courier_new_font11x16_digits);
        ssd1306_printFixed(69, 30, d_time.c_str(), STYLE_BOLD);
        ssd1306_setFixedFont(ssd1306xled_font6x8);
        ssd1306_printFixed(69, 45, d_date, STYLE_BOLD);

        ssd1306_setFixedFont(ssd1306xled_font6x8);
        ssd1306_printFixed(5, 20, "NEW YORK", STYLE_BOLD);
        ssd1306_setFixedFont(courier_new_font11x16_digits);
        ssd1306_printFixed(5, 30, ny_time.c_str(), STYLE_BOLD);
        ssd1306_setFixedFont(ssd1306xled_font6x8);
        ssd1306_printFixed(5, 45, ny_date, STYLE_BOLD);

    }
    else {
        ssd1306_fillScreen(0x00);
        ssd1306_printFixed(5, 20, "WiFi disconnected!", STYLE_BOLD);
    }

    d_http.end();
    ny_http.end();

    delay(100);
}




