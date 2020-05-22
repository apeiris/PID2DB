#include <Arduino.h>
#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"

static const char* TAG "thimy";
void setup() {
  // put your setup code here, to run once:
  int a=12,b=-1200;
  printf("HI a=%i b=%i \n",a,b);
  ESP_LOGD(TAG,"HIIIIII\n");
}

void loop() {
  // put your main code here, to run repeatedly:
}