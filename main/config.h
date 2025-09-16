/*
 * config.h
 */

#ifndef MAIN_CONFIG_H_
#define MAIN_CONFIG_H_

// --- Wi-Fi Configuration ---
// Set the SSID and password of the Wi-Fi network you want to connect to.
#define WIFI_SSID               "TP-LINK_46DC"
#define WIFI_PASSWORD           "itrlab125"

// --- UDP Configuration ---
// The IP address of the computer running the ground control station.
#define UDP_TARGET_IP           "10.1.1.100"
// The port on the ground control station to send data to.
#define UDP_TARGET_PORT         14554
// The local port on the ESP32 to listen for incoming UDP data.
#define UDP_LOCAL_PORT          14550

// --- UART Configuration ---
// The UART port to use.
#define UART_NUM                UART_NUM_1
// The baud rate for the UART communication.
#define UART_BAUD_RATE          921600
// The GPIO pins for UART. Change these to match your hardware.
#define UART_TX_PIN             3
#define UART_RX_PIN             2

// --- Bridge Task Configuration ---
// Max UDP payload size. 1472 is a safe value for typical Wi-Fi/Ethernet MTU (1500) to avoid IP fragmentation.
#define RX_BUF_SIZE             176
// UART RX timeout threshold (in byte-times). Triggers a UART_DATA event even if buffer is not full.
#define UART_RX_TIMEOUT_THRESH  3
#define TASK_STACK_SIZE         4096  // Stack size for the bridge tasks.
#define TASK_PRIORITY           5     // Priority of the bridge tasks.

#endif /* MAIN_CONFIG_H_ */
