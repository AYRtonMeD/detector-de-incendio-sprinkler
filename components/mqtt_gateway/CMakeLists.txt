idf_component_register(SRCS "mqtt_gateway.c"
                    INCLUDE_DIRS "include"
                    REQUIRES protocol_examples_common esp_netif mqtt esp_partition nvs_flash app_update)
