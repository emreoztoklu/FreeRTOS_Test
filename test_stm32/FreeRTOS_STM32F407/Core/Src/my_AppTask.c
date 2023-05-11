/*
 * my_AppTask.c
 *
 *  Created on: Feb 7, 2023
 *      Author: arge12
 */


#include "my_AppTask.h"

#define FALSE (1 == 0)
#define TRUE  (1 == 1)
#define NOT_PRESSED FALSE
#define PRESSED TRUE



const TickType_t xPeriod_100 = pdMS_TO_TICKS(100);
const TickType_t xPeriod_200 = pdMS_TO_TICKS(200);


uint8_t button_status_flag = NOT_PRESSED;

TaskHandle_t task1;
TaskHandle_t task2;



void vApplicationIdleHook(void){
    // send CPU to normal sleep by using CMSIS macro
    __WFI();
}


void task_100ms(void *param){
    TickType_t xLastWakeTime;

    /* Init the xLastWakeTime variable with the current time */
    xLastWakeTime = xTaskGetTickCount();

    while(1){
        if(HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == FALSE){
            // If button state is 1 then we consider not pressed
            button_status_flag = NOT_PRESSED;
        }
        else{
            // When button is pressed the state of button will be 0
            button_status_flag = PRESSED;
        }

      //  HAL_Delay(50);

        //vTaskDelay(pdMS_TO_TICKS(200));
        vTaskDelayUntil(&xLastWakeTime, xPeriod_100);
    }
}




void task_200ms(void *param){
    TickType_t xLastWakeTime;

    /* Init the xLastWakeTime variable with the current time */
    xLastWakeTime = xTaskGetTickCount();

    while(1) {
        if(button_status_flag == PRESSED) {
            // Turn ON the LED
            HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin|LD4_Pin|LD5_Pin|LD6_Pin, GPIO_PIN_SET);
        }
        else {
            // Turn OFF the LED
            HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin|LD4_Pin|LD5_Pin|LD6_Pin , GPIO_PIN_RESET);
        }

        //vTaskDelay(pdMS_TO_TICKS(100));
        vTaskDelayUntil(&xLastWakeTime, xPeriod_200);
    }
}


void vTaskFunction(void *pvParameters){
	char *pcTaskName;
	const TickType_t xDelay = xTaskGetTickCount();

	pcTaskName = (char*)pvParameters;

	while (1){
		vPrintString(pcTaskName);
		vTaskDelayUntil(&xDelay, pdMS_TO_TICKS(250));
	}
}


void vPrintString(const char *pcString){
/* Write the string to stdout, suspending the scheduler as a method of mutual
exclusion. */
	//vTaskSuspendScheduler();
		{

			//printf( "%s", pcString );
			//fflush( stdout );
		}
	//xTaskResumeScheduler();
}
