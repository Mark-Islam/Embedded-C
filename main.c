/**
**************************************
*Keypad Interfacing
*Mark (Majhar) Islam
**************************************
**/

#include <stdio.h>
#include <stdint.h>
//Peripheral Register Address
#define DELAY                       300000
#define MODE_REG                    (uint32_t*)(0x40020C00+0x00)
#define INPUT_DATA_REG              (uint32_t*)(0x40020C00+0x10)
#define OUTPUT_DATA_REG             (uint32_t*)(0x40020C00+0x14)
#define CLOCK_CTR_REG               (uint32_t*)(0x40023800+0x30)
#define PULLUP_DOWN_REG             (uint32_t*)(0x40020C00+0x0C)

void delay (void);

int main (void)
{
//Pointer variables for 32 bit registers
uint32_t volatile *const pGPIOModeReg = MODE_REG;
uint32_t volatile *const pInputDataReg = INPUT_DATA_REG;
uint32_t volatile *const pOutputDataReg = OUTPUT_DATA_REG;
uint32_t volatile *const pClockCtrReg = CLOCK_CTR_REG;
uint32_t volatile *const pPullupDownReg = PULLUP_DOWN_REG;

//Enabling the peripheral clock for the GPIOD peripheral
*pClockCtrReg |= (1<<3);
//Configure output (PD0-PD3) pins
*pOutputDataReg &= ~(0xFF); //Clear
*pOutputDataReg |= (0x55); // Set

//Configure input (PD8-PD11) pins
*pInputDataReg &= ~(0xFF << 16);
// Enabling internal pullup registers for inputs (PD8 - PD11)
*pPullupDownReg &= ~(0xFF << 16); // Clear
*pPullupDownReg |= (0x55 << 16); // set

While (1)
{

    *pOutputDataReg |= (0x0F); //Make all outputs high
    *pOutputDataReg &= ~(0x1 << 0); // first output low
    //scan the columns
    if (!(*pInputDataReg |= (0x1 << 8)))
    {
        delay (); \\ key pressed
        printf ("1\n");
    }
    if (!(*pInputDataReg & (0x1<<9)))
    {
        delay(); \\key pressed
        printf ("2\n");
    }
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("3\n");
    }

    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("A\n");
    }


    //make all rows HIGH
     *pOutPutDataReg |= 0x0f;
    //make Output2 LOW(PD1)
    *pOutputDataReg &= ~(0x1 <<1);

    //scan the columns
    //check C1(PD8) low or high
    if(!(*pInPutDataReg & ( 1 << 8))){
    	//key is pressed
    	delay();
    	printf("4\n");
    }

    //check C2(PD9) low or high
    if(!(*pInPutDataReg & ( 1 << 9))){
    	//key is pressed
    	delay();
    	printf("5\n");
    }

    //check C3(PD10) low or high
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("6\n");
    }

    //check C4(PD11) low or high
    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("B\n");
    }

    //make all rows HIGH
     *pOutPutDataReg |= 0x0f;
    //make R3 LOW(PD2)
    *pOutPutDataReg &= ~( 1 << 2);

    //scan the columns
    //check C1(PD8) low or high
    if(!(*pInPutDataReg & ( 1 << 8))){
    	//key is pressed
    	delay();
    	printf("7\n");
    }

    //check C2(PD9) low or high
    if(!(*pInPutDataReg & ( 1 << 9))){
    	//key is pressed
    	delay();
    	printf("8\n");
    }

    //check C3(PD10) low or high
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("9\n");
    }

    //check C4(PD11) low or high
    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("C\n");
    }

    //make all rows HIGH
     *pOutPutDataReg |= 0x0f;
    //make R4 LOW(PD2)
    *pOutPutDataReg &= ~( 1 << 3);

    //scan the columns
    //check C1(PD8) low or high
    if(!(*pInPutDataReg & ( 1 << 8))){
    	//key is pressed
    	delay();
    	printf("*\n");
    }

    //check C2(PD9) low or high
    if(!(*pInPutDataReg & ( 1 << 9))){
    	//key is pressed
    	delay();
    	printf("0\n");
    }

    //check C3(PD10) low or high
    if(!(*pInPutDataReg & ( 1 << 10))){
    	//key is pressed
    	delay();
    	printf("#\n");
    }

    //check C4(PD11) low or high
    if(!(*pInPutDataReg & ( 1 << 11))){
    	//key is pressed
    	delay();
    	printf("D\n");
    }

}


return 0;

}

void delay (void)
{
    for (uint32_t i =0; i <DELAY; i++);
}
