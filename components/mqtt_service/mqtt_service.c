#include <stdio.h>
#include "mqtt_service.h"
#include "mqtt_client.h"

static esp_mqtt_client_handle_t client;

response_data_t* build_response_data_struct() {
  response_data_t* response_data = (response_data_t*)malloc(sizeof(response_data_t));
  response_data->response = NULL;
  response_data->data = (char *)malloc(16 * sizeof(char));

  response_data->response = build_mqtt_response_struct(response_data->response);

  return response_data;
}

int get_response(response_data_t* response_data) {
  printf("%d\n", !strcmp(response_data->response->data, "incendio"));
  return !strcmp(response_data->response->data, "incendio");
}

void init_mqtt(response_data_t* response_data) {
  build_response_data_struct(response_data);
  mqtt_setup();

  client = mqtt_app_start(response_data->response);
}

void subscribe() {
  esp_mqtt_client_subscribe(client, "/incendio", 2);
}
