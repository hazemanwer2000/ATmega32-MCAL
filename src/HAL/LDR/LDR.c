/*************************************************************
 * 
 * Filename: LDR.c
 * Description: Source file of the LDR driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "LDR_Cfg.h"
#include "LDR_Priv.h"
#include "LDR.h"
#include "ADC.h"


/*************************************************************
 * Description: Get value (0-500 degrees celsius).
 * Parameters:
 *      [1] Sensor index/alias.
 *      [2] Address to data, to read into.
 * Return:
 *      value.
 *************************************************************/
LDR_tenuErrorStatus LDR_enuGetValue(LDR_tenuSensor Cpy_enuSensor, double *Add_doubleReading)
{
    LDR_tenuErrorStatus Loc_enuErrorStatus = LDR_enuOk;
    ADC_tenuErrorStatus Loc_enuADCErrorStatus = ADC_enuOk;
    u16 Loc_u16Data;

    if (Cpy_enuSensor < 0 || Cpy_enuSensor >= LDR_SENSOR_COUNT) {
        Loc_enuErrorStatus = LDR_enuDoesNotExist;
    } else if (Add_doubleReading == NULL) {
        Loc_enuErrorStatus = LDR_enuNullPointer;
    } else {
        ADC_voidConfigureInputChannel(LDR_strucSensorCfgs[Cpy_enuSensor].inputChannel);
        Loc_enuADCErrorStatus = ADC_enuStartConversionAndWait(&Loc_u16Data);
        if (Loc_enuADCErrorStatus != ADC_enuOk) {
            Loc_enuErrorStatus = LDR_enuFailedToRead;
        } else {
            *Add_doubleReading = (1-(Loc_u16Data/1023.0)) * 99;
        }
    }

    return Loc_enuErrorStatus;
}