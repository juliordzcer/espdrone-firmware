/**
 * ESP-Drone Firmware Modificado (WiFi Only)
 * 
 * Configuración mínima para drone ESP32 con comunicación exclusiva por WiFi
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include "usec_time.h"
#include "sdkconfig.h"

#define PROTOCOL_VERSION 4

// Verificación de hardware
#ifdef CONFIG_TARGET_ESP32_S2_DRONE_V1_2
#ifdef CONFIG_IDF_TARGET_ESP32
#error "ESP32_S2_DRONE_V1_2 requiere ESP32S2/S3"
#endif
#endif

// Configuración específica para ESP32
#ifndef FREERTOS_HEAP_SIZE
#define FREERTOS_HEAP_SIZE CONFIG_ESP32_FREERTOS_HEAP_SIZE
#endif
#define FREERTOS_MIN_STACK_SIZE configMINIMAL_STACK_SIZE
#define configBASE_STACK_SIZE CONFIG_BASE_STACK_SIZE

// Prioridades de tareas (mayor número = mayor prioridad)
#define STABILIZER_TASK_PRI         7   // Máxima prioridad para control
#define SENSORS_TASK_PRI            6   // Lectura de sensores
#define KALMAN_TASK_PRI             5   // Filtro Kalman
#define FLOW_TASK_PRI               5   // Flujo óptico
#define PROXIMITY_TASK_PRI          5   // Sensores de proximidad
#define WIFILINK_TASK_PRI           4   // Gestión WiFi
#define UDP_TX_TASK_PRI             3   // Transmisión WiFi
#define UDP_RX_TASK_PRI             3   // Recepción WiFi
#define CMD_HIGH_LEVEL_TASK_PRI     3   // Comandos de alto nivel
#define SYSTEM_TASK_PRI             2   // Sistema principal
#define LOG_TASK_PRI                2   // Logging
#define MEM_TASK_PRI                2   // Memoria
#define PARAM_TASK_PRI              2   // Parámetros
#define PM_TASK_PRI                 1   // Gestión de energía

// Ajuste para sistemas single-core
#if CONFIG_FREERTOS_UNICORE
#undef KALMAN_TASK_PRI
#define KALMAN_TASK_PRI 2  // Prioridad reducida para single-core
#endif

// Nombres de tareas
#define SYSTEM_TASK_NAME        "SYSTEM"
#define PM_TASK_NAME            "PWRMGNT"
#define SENSORS_TASK_NAME       "SENSORS"
#define STABILIZER_TASK_NAME    "STABILIZER"
#define KALMAN_TASK_NAME        "KALMAN"
#define WIFILINK_TASK_NAME      "WIFILINK"
#define UDP_TX_TASK_NAME        "UDP_TX"
#define UDP_RX_TASK_NAME        "UDP_RX"
#define CMD_HIGH_LEVEL_TASK_NAME "CMDHL"
#define LOG_TASK_NAME           "LOG"
#define MEM_TASK_NAME           "MEM"
#define PARAM_TASK_NAME         "PARAM"
#define FLOW_TASK_NAME          "FLOW"
#define PROXIMITY_TASK_NAME     "PROXIMITY"

// Tamaños de stack (optimizados para ESP32)
#define CMD_HIGH_LEVEL_TASK_STACKSIZE (2 * configBASE_STACK_SIZE)
#define KALMAN_TASK_STACKSIZE         (3 * configBASE_STACK_SIZE)
#define LOG_TASK_STACKSIZE            (2 * configBASE_STACK_SIZE)
#define MEM_TASK_STACKSIZE            (2 * configBASE_STACK_SIZE)
#define PARAM_TASK_STACKSIZE          (2 * configBASE_STACK_SIZE)
#define PM_TASK_STACKSIZE             (3 * configBASE_STACK_SIZE)
#define SENSORS_TASK_STACKSIZE        (4 * configBASE_STACK_SIZE)
#define STABILIZER_TASK_STACKSIZE     (4 * configBASE_STACK_SIZE)
#define SYSTEM_TASK_STACKSIZE         (4 * configBASE_STACK_SIZE)
#define UDP_RX_TASK_STACKSIZE         (3 * configBASE_STACK_SIZE)
#define UDP_TX_TASK_STACKSIZE         (3 * configBASE_STACK_SIZE)
#define WIFILINK_TASK_STACKSIZE       (3 * configBASE_STACK_SIZE)
#define FLOW_TASK_STACKSIZE           (2 * configBASE_STACK_SIZE)
#define PROXIMITY_TASK_STACKSIZE      (2 * configBASE_STACK_SIZE)

// Configuraciones de vuelo
#define PROPELLER_BALANCE_TEST_THRESHOLD  2.5f
#define ACTIVATE_STARTUP_SOUND  // Sonido de inicio opcional

// Opciones de depuración
//#define DEBUG_UDP
//#define PRINT_OS_DEBUG_INFO
//#define ADC_OUTPUT_RAW_DATA

// Validaciones de configuraciones incompatibles
#if defined(ADC_OUTPUT_RAW_DATA) && defined(PRINT_OS_DEBUG_INFO)
#error "No usar ADC_OUTPUT_RAW_DATA y PRINT_OS_DEBUG_INFO simultáneamente"
#endif

#endif /* CONFIG_H_ */