/**
 ******************************************************************************
 ******************************************************************************
 * @file    application.cpp
 * @authors João Fonseca - onformative
 * @version V0.0.1
 * @date    28-APRIL-2015
 * @brief   Split Flap Display Interface
 ******************************************************************************
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/  
#include "application.h"

bool DEBUG=true;
bool isDisplayEmpty=false;

String message="Hello everybody, im a sf display!";
int updateDisplay(String command);
int updateMessageVariable(String command);




SYSTEM_MODE(AUTOMATIC);

/* This function is called once at start up ----------------------------------*/
void setup()
{

	Spark.function("updateDis", updateDisplay);
	Spark.function("updateMsgVar", updateMessageVariable);


if(DEBUG)Serial.begin(9600); // this serial is for debig over usb
 Serial1.begin(4800,SERIAL_8E2);
  

	//displayText("hello everybody"); 

  updateDisplay("1");
	delay(10000);
	updateDisplay("0");


}

/* This function loops forever --------------------------------------------*/
void loop()
{

}

void writeChar(int pos, char symbol) {


  Serial1.write(0x88);    //start signal

  //position
  if (pos==0)Serial1.write(0x01);
  if (pos==1)Serial1.write(0x02);
  if (pos==2)Serial1.write(0x03);
  if (pos==3)Serial1.write(0x04);
  if (pos==4)Serial1.write(0x05);
  if (pos==5)Serial1.write(0x06);
  if (pos==6)Serial1.write(0x07);
  if (pos==7)Serial1.write(0x08);
  if (pos==8)Serial1.write(0x09);
  if (pos==9)Serial1.write(0x0a);
  if (pos==10)Serial1.write(0x0b);
  if (pos==11)Serial1.write(0x0c);
  if (pos==12)Serial1.write(0x0d);
  if (pos==13)Serial1.write(0x0e);
  if (pos==14)Serial1.write(0x0f);
  if (pos==15)Serial1.write(0x10);
  if (pos==16)Serial1.write(0x11);
  if (pos==17)Serial1.write(0x12);
  if (pos==18)Serial1.write(0x13);
  if (pos==19)Serial1.write(0x14);
  if (pos==20)Serial1.write(0x15);
  if (pos==21)Serial1.write(0x16);
  if (pos==22)Serial1.write(0x17);
  if (pos==23)Serial1.write(0x18);
  if (pos==24)Serial1.write(0x19);
  if (pos==25)Serial1.write(0x1a);
  if (pos==26)Serial1.write(0x1b);
  if (pos==27)Serial1.write(0x1c);
  if (pos==28)Serial1.write(0x1d);
  if (pos==29)Serial1.write(0x1e);
  if (pos==30)Serial1.write(0x1f);
  if (pos==31)Serial1.write(0x20);
  if (pos==32)Serial1.write(0x21);
  if (pos==33)Serial1.write(0x22);
  if (pos==34)Serial1.write(0x23);
  if (pos==35)Serial1.write(0x24);
  if (pos==36)Serial1.write(0x25);
  if (pos==37)Serial1.write(0x26);
  if (pos==38)Serial1.write(0x27);
  if (pos==39)Serial1.write(0x28);
  if (pos==40)Serial1.write(0x29);
  if (pos==41)Serial1.write(0x2a);
  if (pos==42)Serial1.write(0x2b);
  if (pos==43)Serial1.write(0x2c);
  if (pos==44)Serial1.write(0x2d);
  if (pos==45)Serial1.write(0x2e);
  if (pos==46)Serial1.write(0x2f);
  if (pos==47)Serial1.write(0x30);
  if (pos==48)Serial1.write(0x31);
  if (pos==49)Serial1.write(0x32);
  if (pos==50)Serial1.write(0x33);
  if (pos==51)Serial1.write(0x34);
  if (pos==52)Serial1.write(0x35);
  if (pos==53)Serial1.write(0x36);
  if (pos==54)Serial1.write(0x37);
  if (pos==55)Serial1.write(0x38);
  if (pos==56)Serial1.write(0x39);
  if (pos==57)Serial1.write(0x3a);
  if (pos==58)Serial1.write(0x3b);
  if (pos==59)Serial1.write(0x3c);
  if (pos==60)Serial1.write(0x3d);
  if (pos==61)Serial1.write(0x3e);
  if (pos==62)Serial1.write(0x3f);
  if (pos==63)Serial1.write(0x40);
  if (pos==64)Serial1.write(0x41);
  if (pos==65)Serial1.write(0x42);
  if (pos==66)Serial1.write(0x43);
  if (pos==67)Serial1.write(0x44);
  if (pos==68)Serial1.write(0x45);
  if (pos==69)Serial1.write(0x46);
  if (pos==70)Serial1.write(0x47);
  if (pos==71)Serial1.write(0x48);
  if (pos==72)Serial1.write(0x49);
  if (pos==73)Serial1.write(0x4a);
  if (pos==74)Serial1.write(0x4b);
  if (pos==75)Serial1.write(0x4c);
  if (pos==76)Serial1.write(0x4d);
  if (pos==77)Serial1.write(0x4e);
  if (pos==78)Serial1.write(0x4f);
  if (pos==79)Serial1.write(0x50);
  if (pos==80)Serial1.write(0x51);
  if (pos==81)Serial1.write(0x52);
  if (pos==82)Serial1.write(0x53);
  if (pos==83)Serial1.write(0x54);
  if (pos==84)Serial1.write(0x55);
  if (pos==85)Serial1.write(0x56);
  if (pos==86)Serial1.write(0x57);
  if (pos==87)Serial1.write(0x58);
  if (pos==88)Serial1.write(0x59);
  if (pos==89)Serial1.write(0x5a);

bool noSymbol=false;

  if (symbol ==' ')Serial1.write(0x20);
  else if (symbol =='0')Serial1.write(0x30);
  else if (symbol =='1')Serial1.write(0x31);
  else if (symbol =='2')Serial1.write(0x32);
  else if (symbol =='3')Serial1.write(0x33);
  else if (symbol =='4')Serial1.write(0x34);
  else if (symbol =='5')Serial1.write(0x35);
  else if (symbol =='6')Serial1.write(0x36);
  else if (symbol =='7')Serial1.write(0x37);
  else if (symbol =='8')Serial1.write(0x38);
  else if (symbol =='9')Serial1.write(0x39);
  

  else if (symbol =='a' || symbol =='A')Serial1.write(0x41);
  else if (symbol =='b' || symbol =='B')Serial1.write(0x42);
  else if (symbol =='c' || symbol =='C')Serial1.write(0x43);
  else if (symbol =='d' || symbol =='D')Serial1.write(0x44);
  else if (symbol =='e' || symbol =='E')Serial1.write(0x45);
  else if (symbol =='f' || symbol =='F')Serial1.write(0x46);
  else if (symbol =='g' || symbol =='G')Serial1.write(0x47);
  else if (symbol =='h' || symbol =='H')Serial1.write(0x48);
  else if (symbol =='i' || symbol =='I')Serial1.write(0x49);
  else if (symbol =='j' || symbol =='J')Serial1.write(0x4a);
  else if (symbol =='k' || symbol =='K')Serial1.write(0x4b);
  else if (symbol =='l' || symbol =='L')Serial1.write(0x4c);
  else if (symbol =='m' || symbol =='M')Serial1.write(0x4d);
  else if (symbol =='n' || symbol =='N')Serial1.write(0x4e);
  else if (symbol =='o' || symbol =='O')Serial1.write(0x4f);
  else if (symbol =='p' || symbol =='P')Serial1.write(0x50);
  else if (symbol =='q' || symbol =='Q')Serial1.write(0x51);
  else if (symbol =='r' || symbol =='R')Serial1.write(0x52);
  else if (symbol =='s' || symbol =='S')Serial1.write(0x53);
  else if (symbol =='t' || symbol =='T')Serial1.write(0x54);
  else if (symbol =='u' || symbol =='U')Serial1.write(0x55);
  else if (symbol =='v' || symbol =='V')Serial1.write(0x56);
  else if (symbol =='w' || symbol =='W')Serial1.write(0x57);
  else if (symbol =='x' || symbol =='X')Serial1.write(0x58);
  else if (symbol =='y' || symbol =='Y')Serial1.write(0x59);
  else if (symbol =='z' || symbol =='Z')Serial1.write(0x5a);
  

   else if (int(symbol) == 164)Serial1.write(0x3f);// ä
   else if (int(symbol) == 182)Serial1.write(0x3b);// ö
   else if (int(symbol) == 188)Serial1.write(0x3c);// ü
   else if (int(symbol) == 45)Serial1.write(0x2d);// -
   else if (int(symbol) == 46)Serial1.write(0x2e);// .
   else if (int(symbol) == 40)Serial1.write(0x28);// (
   else if (int(symbol) == 41)Serial1.write(0x29);// )
   else if (int(symbol) == 33)Serial1.write(0x21);// !
   else if (int(symbol) == 58)Serial1.write(0x3a);// :
   else if (int(symbol) == 47)Serial1.write(0x2f);// /
   else if (int(symbol) == 34)Serial1.write(0x22);// "
   else if (int(symbol) == 44)Serial1.write(0x2c);// , 
   
   else if (int(symbol) == 61)Serial1.write(0x3d); // =
   else if (int(symbol) == 172)Serial1.write(0x3e);// €
   else if (int(symbol) == 64)Serial1.write(0x40);//ß @
   else{

      noSymbol=true;

   }
   

  if(!noSymbol){
   Serial.println(int(symbol));
  
  Serial1.write(0x81);     //end signal
  
}
}

/* writeText FUNCTION -----------------------------------------------*/
void writeText(String word){

	//int position=(90/2)-(word.length()/2);
updateDisplay("0");
	 for (int i = 0; i<int(word.length());i++){

	 	writeChar(0+i, word.charAt(i));
	 	
  }
	
}






/* -------------------------------------------------------------------------------- COMMUNICATION PROTOCOL*/

// /* DISPLAY TEXT FUNCTION --------------------------------------------*/
// int displayText(String command){
// 	if(!isDisplayEmpty)resetDisplay("0");
// 	writeText(command);
// 	isDisplayEmpty=false;
	
// 	return command.length();

// }


/* DISPLAY TEXT FUNCTION --------------------------------------------*/
int updateMessageVariable(String command){

 if(command){

  message+=command;

   //delay(10000);

  return 1;
 }
 else return 0;

}



/* RESET FUNCTION ---------------------------------------------------*/
int updateDisplay(String command){

  //if(DEBUG){

    //return -2;
  //}else{

  if(command=="0"){           //_________________________________________ RESET
    Serial1.write(0x82);
    isDisplayEmpty=true;
    message="";
    return 1;

}else if(command=="1"){       //_________________________________________ update message
//Serial.println(message);
  /*
  int messageSize=round((message.length()/90)+0.5);
  String messageContainers[messageSize];
  Serial.println(messageSize);
  */
//  delay(5000);

  writeText(message);
  message="";

    return 2;

  }else return 0;
//}

}

