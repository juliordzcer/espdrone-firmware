/**
 * ESP-Drone NVIC Configuration (WiFi Only)
 * 
 * Configuración de prioridades de interrupción optimizada para ESP32
 * con comunicación exclusiva por WiFi
 */

#ifndef NVIC_CONF_H_
#define NVIC_CONF_H_

/*
 * Organización de prioridades de interrupción para ESP32:
 *
 * En ESP32 (basado en Xtensa), las prioridades de interrupción funcionan diferente
 * a Cortex-M. Los números más bajos indican mayor prioridad (0 = más alta).
 * El rango típico es de 1 a 7 para prioridades configurables.
 *
 * Interrupciones que llaman funciones FreeRTOS FromISR deben tener prioridades
 * por encima del nivel configMAX_SYSCALL_INTERRUPT_PRIORITY.
 *
 * 4 niveles de interrupción están definidos:
 *  - NVIC_VERY_HIGH_PRI (crítico para el vuelo)
 *  - NVIC_HIGH_PRI (funciones esenciales)
 *  - NVIC_MID_PRI (comunicaciones y periféricos)
 *  - NVIC_LOW_PRI (tareas no críticas)
 */

// Niveles estándar de interrupción (adaptados para ESP32)
#define NVIC_VERY_HIGH_PRI    1  // Prioridad máxima (sensor IMU, control)
#define NVIC_HIGH_PRI         2  // Funciones críticas de vuelo
#define NVIC_MID_PRI          3  // Comunicaciones WiFi y periféricos
#define NVIC_LOW_PRI          4  // Tareas de bajo prioridad

// Prioridades específicas para periféricos
#define NVIC_IMU_PRI          NVIC_VERY_HIGH_PRI  // BMI088/MPU9250
#define NVIC_WIFI_PRI         NVIC_MID_PRI        // Stack WiFi
#define NVIC_UDP_PRI          NVIC_MID_PRI        // Comunicación UDP
#define NVIC_UART_PRI         NVIC_MID_PRI        // UART debug
#define NVIC_I2C_PRI          NVIC_HIGH_PRI       // Sensores I2C
#define NVIC_SPI_PRI          NVIC_HIGH_PRI       // SPI para IMU
#define NVIC_ADC_PRI          NVIC_LOW_PRI        // Lectura ADC
#define NVIC_PWM_PRI          NVIC_HIGH_PRI       // Control de motores

// Prioridades para interrupciones externas (GPIO)
#define EXTI0_PRI             NVIC_HIGH_PRI       // GPIO críticos
#define EXTI1_PRI             NVIC_HIGH_PRI
#define EXTI2_PRI             NVIC_HIGH_PRI
#define EXTI3_PRI             NVIC_HIGH_PRI
#define EXTI4_PRI             NVIC_MID_PRI        // Flow control
#define EXTI9_5_PRI           NVIC_MID_PRI        // Periféricos varios
#define EXTI15_10_PRI         NVIC_LOW_PRI        // Sensores/decks no críticos

// Configuraciones específicas para ESP32
#define NVIC_WS2812_PRI       NVIC_LOW_PRI        // LEDs (si se usan)
#define NVIC_USB_PRI          NVIC_MID_PRI        // USB (si se usa)

#endif /* NVIC_CONF_H_ */