/*
 * File:   main.c
 * Author: Phil Glazzard
 *
 * Created on 13 November 2020, 18:52
 */


#include "config.h"
#include "configPorts.h"
#include "configOsc.h"
#include "configSPI.h"
#include "configTMR1.h"
#include "configTMR0.h"
#include "init1_max7219.h"
#include "init2Max7219.h"
#include "configUsart.h"
#include "sendSPIbyte.h"
#include "sendNoSPIbyte.h"
#include "clearScreen.h"
#include "splashScreen.h"
#include "arrays.h"
#include "gameState.h"
#include "pong.h"
#include "writeMatrix.h"
#include "paddleMove.h"
void main(void) 
{
   
   
    configPorts();
    configOsc();
    configSPI();
    init1_max7219();
    init2Max7219();
    configUsart();
    configTMR1();
    configTMR0();
    
    uchar paddlePos = 3;// paddlePos can be 1-6, low lowest position, 6 highest position
    printf("Hello Phil\n");
    
    clearScreen();
 
while(1)
    {
        //state = gameState(state);
        //printf("gameState %d\n", state);
        paddleMove(paddlePos);
        if(RPB ==LO && LPB==HI && paddlePos<6 && paddlePos>=0)
        {
            while(RPB!=HI);
            paddlePos++;            // paddle moves up
        }
        else if(LPB ==LO && RPB==HI && paddlePos<=6 && paddlePos>1)
        {
            while(LPB!=HI);
            paddlePos--;            // paddle moves down
        }

     //printf("%d\n",paddlePos);   
    }
}
    

   
