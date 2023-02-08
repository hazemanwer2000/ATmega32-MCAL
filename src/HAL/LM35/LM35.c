/*************************************************************
 * 
 * Filename: LM35.c
 * Description: Source file of the LM35 driver.
 * Author: Eng. Hazem Anwer
 * Github: https://github.com/hazemanwer2000
 * 
 *************************************************************/

#include "LM35_Cfg.h"
#include "LM35_Priv.h"
#include "LM35.h"
#include "ADC.h"


/*************************************************************
 * Description: Get value (0-500 degrees celsius).
 * Parameters:
 *      [1] Sensor index/alias.
 *      [2] Address to data, to read into.
 * Return:
 *      value.
 *************************************************************/
LM35_tenuErrorStatus LM35_enuGetValue(LM35_tenuSensor Cpy_enuSensor, double *Add_doubleReading)
{
    LM35_tenuErrorStatus Loc_enuErrorStatus = LM35_enuOk;
    ADC_tenuErrorStatus Loc_enuADCErrorStatus = ADC_enuOk;
    u16 Loc_u16Data;

    if (Cpy_enuSensor < 0 || Cpy_enuSensor >= LM35_SENSOR_COUNT) {
        Loc_enuErrorStatus = LM35_enuDoesNotExist;
    } else if (Add_doubleReading == NULL) {
        Loc_enuErrorStatus = LM35_enuNullPointer;
    } else {
        ADC_voidConfigureInputChannel(LM35_strucSensorCfgs[Cpy_enuSensor].inputChannel);
        Loc_enuADCErrorStatus = ADC_enuStartConversionAndWait(&Loc_u16Data);
        if (Loc_enuADCErrorStatus != ADC_enuOk) {
            Loc_enuErrorStatus = LM35_enuFailedToRead;
        } else {
            *Add_doubleReading = Loc_u16Data * 500.0 / 1024;
        }
    }

    return Loc_enuErrorStatus;
}