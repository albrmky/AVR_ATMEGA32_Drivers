/*
 * ADC_configuration.h
 *
 *  Created on: Jan 17, 2022
 *      Author: noureldeen albrmky
 */

#ifndef INCLUDE_MCAL_ADC_ADC_CONFIGURATION_H_
#define INCLUDE_MCAL_ADC_ADC_CONFIGURATION_H_


/**********************************************************
 Select the reference voltage

 options:
 ADC_VREF_AREF			//AREF pin used and internal Vref if off
 ADC_VREF_AVCC 			//AVCC with external capacitor at AREF pin
 ADC_VREF_INTERNAL		//Internal 2.56 voltage with external capacitor at AREF pin
 **********************************************************/
#define ADC_VOLTAGE_REFERENCE		ADC_VREF_AVCC


/***********************************************************
 choose the type of the adjustment
 options:
 ADC_LEFT_ADJUSTMENT
 ADC_RIGHT_ADJUSTMENT
 ***********************************************************/
#define ADC_ADJUSTMENT_TYPE			ADC_LEFT_ADJUSTMENT


/*****************************************************
 select the input channel and the gain selection
 options:

 // single//
 ADC_SINGLE_ADC0  		ADC_SINGLE_ADC4
 ADC_SINGLE_ADC1   		ADC_SINGLE_ADC5
 ADC_SINGLE_ADC2   		ADC_SINGLE_ADC6
 ADC_SINGLE_ADC3   		ADC_SINGLE_ADC7
 ADC_SINGLE_V_BAND_GAB	ADC_SINGLE_GND


 // differential //
 P0: positive input is ADC0
 N0: negative input is ADC0

 ADC_DIFF_P0_N0_G10		ADC_DIFF_P1_N0_G10
 ADC_DIFF_P0_N0_G200		ADC_DIFF_P1_N0_G200

 ADC_DIFF_P2_N2_G10		ADC_DIFF_P3_N2_G10
 ADC_DIFF_P2_N2_G200		ADC_DIFF_P3_N2_G200

 ADC_DIFF_P0_N1			ADC_DIFF_P4_N1
 ADC_DIFF_P1_N1			ADC_DIFF_P5_N1
 ADC_DIFF_P2_N1			ADC_DIFF_P6_N1
 ADC_DIFF_P3_N1			ADC_DIFF_P7_N1

 ADC_DIFF_P0_N2			ADC_DIFF_P3_N2
 ADC_DIFF_P1_N2			ADC_DIFF_P4_N2
 ADC_DIFF_P2_N2			ADC_DIFF_P5_N2




 *****************************************************/
#define ADC_INPUT_CHANNEL_GAIN_SEL		ADC_SINGLE_ADC0


/*******************************************************
 choose if the ADC is enable or not
 options:
 ADC_ENABLE
 ADC_DISABLE
 ********************************************************/
#define ADC_ENABLE_STATE	 ADC_ENABLE



/*********************************************************************
 choose if auto triggering by external source is enabled or not
 then choose the source

 note: must be enable for free running mode
 note: if auto trigger disabled then the source field has no effect

 ADC_ENABLE
 ADC_DISABLE

 source options:
 ADC_TSOURCE_FREE_RUNNING
 ADC_ANALOG_COMPARATOR
 ADC_EXTINT0
 ADC_TIMER0_COMPARE_MATCH
 ADC_TIMER0_OVERFLOW
 ADC_TIMER1_COMPARE_MATCHB
 ADC_TIMER1_OVERFLOW
 ADC_TIMER1_CAPTURE_EVENT
 *********************************************************************/
#define ADC_AUTO_TRIGGER	ADC_DISABLE
#define ADC_TRIGGRE_SOURCE	ADC_TSOURCE_FREE_RUNNING


/*******************************************************
 choose if interrupt is enable or nor
 Note: general interrupt must be also enable
 ADC_ENABLE
 ADC_DISABLE
 ********************************************************/
#define ADC_INTERRUPT_STATE		ADC_DISABLE



/***************************************************************
 The pre-scaler for the option
 options
 ADC_DIVIDE_2      	ADC_DIVIDE_32
 ADC_DIVIDE_4       ADC_DIVIDE_64
 ADC_DIVIDE_8       ADC_DIVIDE_128
 ADC_DIVIDE_16
 ****************************************************************/
#define ADC_PRESCALER		ADC_DIVIDE_128


#endif /* INCLUDE_MCAL_ADC_ADC_CONFIGURATION_H_ */
