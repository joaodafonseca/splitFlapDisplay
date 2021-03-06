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

aaaaaaaa1 aaaaaaaa2 aaaaaaaa3 aaaaaaaa4 aaaaaaaa5 aaaaaaaa6 aaaaaaaa7 aaaaaaaa8 aaaaaaaa9 

 */


#define incomingStringLength 20

/* Includes ------------------------------------------------------------------*/  
#include "application.h"
//#include "SparkTime.h"

#include "flashee-eeprom.h"

using namespace Flashee;


//FUNCION DECLARATION
int resetDisplay(String command);
int updateMessageVariable(String command);
void turnOnDisplay();
void turnOffDisplay();
void writeText(String word);
void writeChar(int pos, char symbol);
void displayText();


//VARIABLES
FlashDevice* flash;


bool DEBUG=false;
bool isDisplayEmpty=false;

int messageSize=0;
int messageBlockLocation=0;
bool shouldDisplayText=false;

float messageBlocks=0;
bool isDisplayingMessage;


String message="Hello everybody, im a sf display!";

int ledPin=7;
int relayPin=6;
int counter=0;
bool isDisplayOn;
bool displayMeetingMessage;

long textTimer=0;
long relayOffTimer=0;
long oldMillis=0;

SYSTEM_MODE(AUTOMATIC);


char charPosition[90]={0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,
	                     0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,0x12,0x13,0x14,
	                     0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,
	                     0x1f,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,
                         0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,0x30,0x31,0x32,
	                     0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,
	                     0x3d,0x3e,0x3f,0x40,0x41,0x42,0x43,0x44,0x45,0x46,
	                     0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,0x50,
	                     0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a
                       };


/* This function is called once at start up ---------------------------------------------------------------------------*/
void setup()
{

	Spark.function("resetDis", resetDisplay);
	Spark.function("updateMsgVar", updateMessageVariable);

	pinMode(ledPin, OUTPUT);
	pinMode(relayPin, OUTPUT);


	flash = Devices::createWearLevelErase();
	flash->eraseAll();

	isDisplayingMessage=false;
 	if(DEBUG)Serial.begin(9600); // this serial is for debug over usb
 	Serial1.begin(4800,SERIAL_8E2);

 	Time.zone(+2);
 	resetDisplay("0");
 	displayMeetingMessage=false;


 	//digitalWrite(relayPin, HIGH);


 }


/* This function loops forever ----------------------------------------------------------------------------------------*/
 void loop()
 {

 	if(shouldDisplayText)counter=0;
//Serial.println(counter);
//Serial.print(Time.hour());
//Serial.print(":");
//Serial.println(Time.minute());

 	if(Time.hour()==10 && Time.minute()==30 && !displayMeetingMessage){

 		displayMeetingMessage=true;

 		updateMessageVariable("0_meeting time, everybody!");
 		updateMessageVariable("[messageEnd]");

 	}
 	else if(!(Time.hour()==10 && Time.minute()==30)) {

 		if(displayMeetingMessage){
 			displayMeetingMessage=false;
 			resetDisplay("0");

 		}

 	}

 	if(relayOffTimer>60000){
 		turnOffDisplay();

 	}



 	if(shouldDisplayText)displayText();


 	//keep track of Time for text;
 	textTimer+=abs(millis()-oldMillis);
  //keep track of Time for turn off relay;
  relayOffTimer+=abs(millis()-oldMillis);
 	oldMillis=millis();


	//if(DEBUG)Serial.println(textTimer);

 }

  //----------------------------------------------------------------------------------------------------- TURN DISPLAY ON
 void turnOnDisplay(){
 	relayOffTimer=0;
 	isDisplayingMessage=true;
 	if(!isDisplayOn){
 		digitalWrite(relayPin, HIGH);
 		delay(5000);
    textTimer=0;
   // counter=0;
 		isDisplayOn=true;

    if(DEBUG)Serial.println("on");

 	}
 }

 //----------------------------------------------------------------------------------------------------- TURN DISPLAY OFF
 void turnOffDisplay(){

 	if(isDisplayOn  && !shouldDisplayText){
 		//delay(5000);
 		digitalWrite(relayPin, LOW);
 		isDisplayOn=false;
    if(DEBUG)Serial.println("off");
 	}
 }

 //----------------------------------------------------------------------------------------------------- Write text
 void writeText(String word){

	//int position=0;
  //if(word.length()<30)position=(90/2)-(word.length()/2);
 	
  //word.toUpperCase();


 	resetDisplay("0");
 	for (int i = 0; i<int(word.length());i++){

 		writeChar(0+i, word.charAt(i));

 	}

 	if(DEBUG)Serial.println();

 }

 //----------------------------------------------------------------------------------------------------- Write Single Char
 void writeChar(int pos, char symbol) {


  Serial1.write(0x88);    //start signal
 // delay(2);
  Serial1.write(charPosition[pos]);
  //delay(2);
  //if(DEBUG)Serial.print(posChar);
  //if(DEBUG)Serial.print(" - ");



  if(symbol==188)Serial1.write(0x3c);  // ü                              
  else if(symbol==164)Serial1.write(0x3f);   // ä 
  else if(symbol==182)Serial1.write(0x3b);  // ö  
  else if(symbol==172)Serial1.write(0x3e);  // €  

  else Serial1.write(symbol);

  

  /*

  if (symbol =='ä')myPort.write(0x3f);
  if (symbol =='ö')myPort.write(0x3b);
  if (symbol =='ü')myPort.write(0x3c);
  if (symbol =='-')myPort.write(0x2d);
  if (symbol =='.')myPort.write(0x2e);
  if (symbol =='(')myPort.write(0x28);
  if (symbol ==')')myPort.write(0x28);
  if (symbol =='!')myPort.write(0x21);
  if (symbol ==':')myPort.write(0x3a);
  if (symbol =='/')myPort.write(0x2f);
  if (symbol =='"')myPort.write(0x22);
  if (symbol =='\'')myPort.write(0x2c);
  if (symbol =='=')myPort.write(0x3d);
  if (symbol =='€')myPort.write(0x3e);
  if (symbol =='@')myPort.write(0x40);
  */
  
  Serial1.write(symbol);
  //delay(2);
  //if(DEBUG)Serial.println(symbol);
  Serial1.write(0x81);     //end signal
  //delay(2);
  //delay(20);


  if(DEBUG)Serial.print(pos);
  if(DEBUG)Serial.print(" -" );
  if(DEBUG)Serial.println(symbol);

}

 //----------------------------------------------------------------------------------------------------- display text on sf display

void displayText(){


	turnOnDisplay();
	digitalWrite(ledPin, HIGH);


//
	if(messageBlockLocation<messageBlocks){


	if(textTimer>=8000){
		textTimer=0;

		char buf[messageSize];
		memset(buf, 5, sizeof(buf));

		flash->read(buf, 0, messageSize);

		int bufSize=sizeof(buf);


		String temp="";

		if(DEBUG)Serial.print("mSize: ");
		if(DEBUG)Serial.print(bufSize);
		if(DEBUG)Serial.print(" | block: ");
		if(DEBUG)Serial.print(messageBlockLocation);
		if(DEBUG)Serial.print(" | bgn: ");
		if(DEBUG)Serial.print(messageBlockLocation*90);
		if(DEBUG)Serial.print(" | end :");
		if(DEBUG)Serial.println((messageBlocks*90)-(((messageBlocks-(messageBlockLocation+1))*90)));


		for(int p = messageBlockLocation*90; p < (messageBlocks*90)-(((messageBlocks-(messageBlockLocation+1))*90)); p++){

			if(p<bufSize)temp+=buf[p];

		}


      //Serial.println(temp);
		relayOffTimer=0;
		writeText(temp);
		messageBlockLocation++;
		//if(messageBlocks>0)delay(8000);
	}

	}else{

		isDisplayingMessage=false;
		shouldDisplayText=false;
		messageSize=0;
		messageBlocks=0;
		flash->eraseAll();
		digitalWrite(ledPin, LOW);

	}

//
}


/* ---------------------------------------------------------------------------------------------------------------- COMMUNICATION PROTOCOL*/



/* DISPLAY TEXT FUNCTION --------------------------------------------*/
int updateMessageVariable(String command){


	if(!shouldDisplayText){

//Serial.print("command size");
//Serial.println(command.length());

	isDisplayingMessage=true;
	if(command && command!="[messageEnd]"){


		digitalWrite(ledPin, HIGH);


		String temp="";
		int messageStart=0;
		for(int i=0; i < 5; i++){

			if(command.charAt(i)!='_'){
				temp+=command.charAt(i);
			}
			else{

				messageStart=i+1;
				break;
			}


		}
		int stringLocation=temp.toInt();
  //int stringLocation=command.substring(0, 1).toInt();
		String finalString=command.substring(messageStart, command.length());

  finalString.toUpperCase();


		if(DEBUG){
			Serial.print("stringLocation: ");
			Serial.print(stringLocation*incomingStringLength);
			Serial.print(" | finalStringSize: ");
			Serial.print(finalString.length());
			Serial.print(" | finalString: ");
			Serial.print(finalString);
			Serial.println();
		}
 
    //////CHECK FOR SPECIAL CHARACTERS

    for(int i = 0; i < (int)finalString.length();i++){


        if(finalString.charAt(i)==195){   // ü  

        finalString.remove(i, 1);

    }



        if(finalString.charAt(i)==226){

        finalString.remove(i, 2);

      }
   }

 //////////




		char charBuf[finalString.length()+1];
		finalString.toCharArray(charBuf, finalString.length()+1);


		flash->writeString(charBuf, (stringLocation)*incomingStringLength,false);

		messageSize+=finalString.length();



		digitalWrite(ledPin, LOW);
		return 1;

	}else if(command=="[messageEnd]"){

		messageBlockLocation=0;
		messageBlocks=round(((float(messageSize)-1.0f)/90.0f)+0.5);
		shouldDisplayText=true;
		Serial.print("messageBlockLocation: ");
		Serial.print(messageBlockLocation);
		Serial.print(" | messageBlocks: ");
		Serial.print(messageBlocks);
		Serial.println();


  //turnOffDisplay();
		return 2;

	}

	else return 0;

}
return -5;
}



/* RESET FUNCTION ---------------------------------------------------*/
int resetDisplay(String command){

	turnOnDisplay();

  //if(DEBUG){

    //return -2;
  //}else{

  if(command=="0"){           //_________________________________________ RESET
  	counter=0;
  	Serial1.write(0x82);
  	isDisplayEmpty=true;
    // messageSize=0;
    // messageBlocks=0;
    // flash->eraseAll();
    //turnOffDisplay();
    //delay(4000);
  	isDisplayingMessage=false;
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

}else {

    //turnOffDisplay();
	return 0;

}
//}

}

