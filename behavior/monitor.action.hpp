#include "Cat/model/action.hpp"
#include <fstream>
#include "../models/apnum.model.hpp"
#include "esp_wifi.h"
#include "esp_log.h"

class MonitorAction : public CAT::Action {

public:

    void act(CAT::Element * element) override {
        
        wifi_scan_config_t scan_config = {};
        scan_config.ssid = 0;
        scan_config.bssid = 0;
        scan_config.channel = 0;
        scan_config.show_hidden = true;
        scan_config.scan_type = WIFI_SCAN_TYPE_ACTIVE;
        scan_config.scan_time.active.min = 3500;
        scan_config.scan_time.active.max = 4000;

        esp_wifi_scan_start(&scan_config, true);
        vTaskDelay(pdMS_TO_TICKS(2000));  

        uint16_t ap_num = 0;
        esp_wifi_scan_get_ap_num(&ap_num);
        wifi_ap_record_t ap_records[ap_num];
        esp_wifi_scan_get_ap_records(&ap_num, ap_records);

        for (int i = 0; i < ap_num; i++) {
            printf("SSID: %s, RSSI: %d\n", ap_records[i].ssid, ap_records[i].rssi);
        }

        printf("Redes Detectadas: %d\n", ap_num);
        printf("================================================================\n");

        auto apnum = std::make_shared<AP_NUM>();
        apnum->ap_num = ap_num;

        element->getLocalKnowledge()->setCurrentState(apnum);
    }

};