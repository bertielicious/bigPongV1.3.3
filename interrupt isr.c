#include "config.h"
#include "arrays.h"
#include "clearScreen.h"
#include "paddleMove.h"
#include "writeMatrix.h"
#include <stdio.h>
void interrupt isr(void)
{
   if(INTCONbits.TMR0IF == HI)// && halt == LO)
   {
       char col;
       char row;
       char colSpeed, rowSpeed;
       if(col>=15)
       {
           col = 1;
          // col = 7; // avoids col value being 15 to 255 which are col values off the playing screen
         //  row = 4;
       }
       
           if(col<=1 && (gameArray[row][0]==HI))//||(gameArray[row+1][0]==HI)||(gameArray[row-1][0]==HI))
            {
                colSpeed = 1;
                printf("r %d  c %d\n",row, col);
                //increase score by 1 of left hand player
            }
           
         //  else if(col<=1 && (gameArray[row][0]==LO))
         //  {
         //      INTCONbits.GIE = LO;
          //     INTCONbits.TMR0IE = LO; // disable TMR0 interrupt
               //increase score by 1 of right hand player
               
               
           //}
      
       else if(col>=14 && gameArray[row][15]==HI) //ball bounce off right wall
       {
           colSpeed = -1;
       }
       
           
       
      
       if(row>=7)
       {
           rowSpeed = -1;
       }
       else if(row<1)
       {
           rowSpeed = 1;
       }
          
            col = col + colSpeed;
            row = row + rowSpeed;
           
      
       gameArray[row][col] = 1;
       printf("r %d  c %d\n",row, col);
       writeMatrix();
        
       for(irow = 0; irow<8; irow++)
            {
                for(icol=1; icol<15;icol++)
                {
                    if(gameArray[irow][icol]==1)
                    { 
                        gameArray[irow][icol] = 0x00;// clear row 0 of previous paddle position data
                    }
                    else
                    {
                        continue;
                    }
                }
            } 
       
      
        DIAGNOSTIC_LED = ~DIAGNOSTIC_LED;
        TMR0=0x00;   
        
        INTCONbits.TMR0IF = LO;
       
   }
   
    if(PIR1bits.TMR1IF==HI)// paddles
    { 
        
        for(irow = 0; irow<8; irow++)
        {
            for(icol=0; icol<1;icol++)
                {
                    if(gameArray[irow][icol]==1)
                    { 
                        gameArray[irow][icol] = 0x00;// clear row 0 of previous paddle position data
                    }
                    else
                    {
                        continue;
                    }
                }
        }
           
    
  
        
       // DIAGNOSTIC_LED = ~DIAGNOSTIC_LED;
        TMR1H = 0x7f;
                              // preload TMR1 to generate a 125ms interrupt
        TMR1L = 0x00;
       
        PIR1bits.TMR1IF = LO;   
    }   
}