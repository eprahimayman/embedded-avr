/*
 * KPD_Config.h
 *
 *  Created on: Sep 10, 2026
 *      Author: eprah
 */

#ifndef HAL_KPD_KPD_CONFIG_H_
#define HAL_KPD_KPD_CONFIG_H_

#define Kpd_ColNo  3
#define Kpd_RowNo  3

#define Kpd_R0Pin      Dio_Pin0
#define Kpd_R0Group    Dio_GroupD

#define Kpd_R1Pin      Dio_Pin1
#define Kpd_R1Group    Dio_GroupD

#define Kpd_R2Pin      Dio_Pin2
#define Kpd_R2Group    Dio_GroupD

#define Kpd_R3Pin      Dio_Pin3
#define Kpd_R3Group    Dio_GroupD

#define Kpd_RGroupConfigured {Kpd_R0Group, Kpd_R1Group, Kpd_R2Group}
#define Kpd_RPinConfigured   {Kpd_R0Pin, Kpd_R1Pin, Kpd_R2Pin}
#define Kpd_C0Pin      Dio_Pin4
#define Kpd_C0Group    Dio_GroupD

#define Kpd_C1Pin      Dio_Pin5
#define Kpd_C1Group    Dio_GroupD

#define Kpd_C2Pin      Dio_Pin6
#define Kpd_C2Group    Dio_GroupD

#define Kpd_C3Pin      Dio_Pin7
#define Kpd_C3Group    Dio_GroupD
#define Kpd_CGroupConfigured {Kpd_C0Group, Kpd_C1Group, Kpd_C2Group}
#define Kpd_CPinConfigured   {Kpd_C0Pin, Kpd_C1Pin, Kpd_C2Pin}
#define Kpd_ValuesConfigured { {'1','2','3'},\
                               {'4','5','6'},\
                               {'7','8','9'} }



#endif /* HAL_KPD_KPD_CONFIG_H_ */
