#include "xparameters.h"
#include "xgpio.h"
#include "xutil.h"
//#include "xscutimer.h"
  

//====================================================


int main (void) 
{

    XGpio dip ,diode ,push;
	int i, psb_check, dip_check, diode_check, find, psb_check1;
	
    xil_printf("-- Start of the Program --\r\n");
 
    XGpio_Initialize(&dip, XPAR_SW_4BIT_DEVICE_ID);
	XGpio_SetDataDirection(&dip, 1, 0xffffffff);
	
	XGpio_Initialize(&push, XPAR_BTN_4BIT_DEVICE_ID);
	XGpio_SetDataDirection(&push, 1, 0xffffffff);
	
	XGpio_Initialize(&diode, XPAR_DIODE_0_DEVICE_ID);
	XGpio_SetDataDirection(&diode, 1, 0x00000000);

//	XscuTimer_LoadTimer(TimerInstancePtr, *psb_check);
//	XscuTimer_EnableAutoReload(TimerInstancePtr);

	while (1)
	{
	//XGpio_DiscreteWrite(&diode, 1, 0x00000000);
	  //diode_check = XGpio_DiscreteRead(&diode, 1);
	  //xil_printf("diode Status %x \r\n", diode_check);
	  psb_check = XGpio_DiscreteRead(&push, 1);
	  if(psb_check == 1 )
	  {
		  while(1)
		  {
		  	  XGpio_DiscreteWrite(&diode, 1, 0x00020f03);
		  	  for (i=0; i<99999999; i++);
		  	psb_check = XGpio_DiscreteRead(&push, 1);
		  	if(psb_check == 2)
		  		break;
		  	XGpio_DiscreteWrite(&diode, 1, 0x00020600);
			  for (i=0; i<99999999; i++);
				psb_check = XGpio_DiscreteRead(&push, 1);
				if(psb_check == 2)
					break;
				XGpio_DiscreteWrite(&diode, 1, 0x00020b05);
			  for (i=0; i<99999999; i++);
				psb_check = XGpio_DiscreteRead(&push, 1);
				if(psb_check == 2)
					break;
			  XGpio_DiscreteWrite(&diode, 1, 0x00020f04);
			  for (i=0; i<99999999; i++);
				psb_check = XGpio_DiscreteRead(&push, 1);
				if(psb_check == 2)
					break;
			  XGpio_DiscreteWrite(&diode, 1, 0x08000606);
			  for (i=0; i<99999999; i++);
				psb_check = XGpio_DiscreteRead(&push, 1);
				if(psb_check == 2)
					break;
			  XGpio_DiscreteWrite(&diode, 1, 0x01000d06);
			  for (i=0; i<99999999; i++);
				psb_check = XGpio_DiscreteRead(&push, 1);
				if(psb_check == 2)
					break;
			  XGpio_DiscreteWrite(&diode, 1, 0x01000d07);
			  for (i=0; i<99999999; i++);
				psb_check = XGpio_DiscreteRead(&push, 1);
				if(psb_check == 2)
					break;
			  XGpio_DiscreteWrite(&diode, 1, 0x01000700);
			  for (i=0; i<99999999; i++);
				psb_check = XGpio_DiscreteRead(&push, 1);
				if(psb_check == 2)
					break;
			  XGpio_DiscreteWrite(&diode, 1, 0x01000f07);
			  for (i=0; i<99999999; i++);
				psb_check = XGpio_DiscreteRead(&push, 1);
				if(psb_check == 2)
					break;
			  XGpio_DiscreteWrite(&diode, 1, 0x08000f06);
			  for (i=0; i<99999999; i++);
				psb_check = XGpio_DiscreteRead(&push, 1);
				if(psb_check == 2)
					break;
		  }
	  }

//	  else
//	  {
//		  XGpio_DiscreteWrite(&diode, 1, 0x00000000);
//	  }
//	  xil_printf("Push Buttons Status %x\r\n", psb_check);
//	  dip_check = XGpio_DiscreteRead(&dip, 1);
//	  xil_printf("DIP Switch Status %x\r\n", dip_check);
//
	  for (i=0; i<9999999; i++);
	}
 
}
 
