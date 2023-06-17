#include "mqtt_gateway.h"

typedef struct Response_Data {
  mqtt_response_t* response;
  char* data;
} response_data_t;

response_data_t* build_response_data_struct();
int get_response(response_data_t* response_data);
void init_mqtt(response_data_t* response_data);

void subscribe();