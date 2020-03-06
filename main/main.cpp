#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_spi_flash.h"
#include <nvs.h>
#include "nvs_flash.h"

#include "esp_log.h"
#include "esp_system.h"
#include "sdkconfig.h"

#if __has_include("esp_idf_version.h")
#include "esp_idf_version.h"
#endif

#include "esp_a2dp_api.h"
#include "esp_avrc_api.h"
#include "esp_bt.h"
#include "esp_bt_device.h"
#include "esp_bt_main.h"
#include "esp_gap_bt_api.h"

#include "Bluetooth.h"

extern "C"{

void app_main(){

  //Flash storage is initialised to be able to used BT
  esp_err_t err = nvs_flash_init();
  if(err == ESP_ERR_NVS_NO_FREE_PAGES){
    ESP_ERROR_CHECK(nvs_flash_erase());
    err = nvs_flash_init();
  }

  //Initializing and starting Bluetooth service by given configations.
  //If no other bluetooth sevice is not started. Configures bt-controller.
  //Enables controller. Init/Enables bluedroid. Initialises controller as
  //A2DP_sink and sets stream type to AUDIO_STREAM_READER.'
  std::cout << "Setting up Bluetooth A2DP sink" << std::endl;

  Bluetooth Bluetooth;
  Bluetooth.Bluetooth_a2dp_sink_init("Smart_Sound_BT");


  std::cout << "Success" << std::endl;
  const TickType_t xDelay = 500 / portTICK_PERIOD_MS;
  while(1){
    vTaskDelay(xDelay);
  }


}

//End extern
}
