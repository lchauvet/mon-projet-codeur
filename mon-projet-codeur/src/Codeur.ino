/**************************************************************************************
  Rotary Encoder E38S6G5-600B-G24N
  Edited: 25/03/2025: by LCT
  Description : Les codeurs incrémentaux sont des capteurs électroniques largement
				utilisés dans les applications industrielles pour le contrôle des 
				mouvements rotatifs ou linéaires. Ils permettent de mesurer la distance,
				la position, la vitesse et ou encore l’accélération d'un objet. 
 **************************************************************************************/

#define INT0_number	 0
#define INT1_number	 1

#define INT0_pin	 2	 /* Port D[2] (Arduino digital pin 2) */
#define INT1_pin	 3   /* Port D[3] (Arduino digital pin 3) */

volatile long x , counter = 0; 

/**************************************************************************************
  ISR_PHASE_A
 **************************************************************************************/
void ISR_PHASE_A() {
  if(digitalRead(3)==LOW) {
  counter++;  /* CW  */
  }else{
  counter--;  /* CCW */
  }
}

/**************************************************************************************
  ISR_PHASE_B
 **************************************************************************************/
void ISR_PHASE_B() {
  if(digitalRead(2)==LOW) {
  counter--; /* CW  */
  }else{
  counter++; /* CCW */
  }
}

/**************************************************************************************
  setup
 **************************************************************************************/
void setup() {
  Serial.begin (9600);
  Serial.println("Codeur incremental E38S6G5-600B-G24N");
   
  pinMode(INT0_pin, INPUT_PULLUP);
  pinMode(INT1_pin, INPUT_PULLUP); 
  attachInterrupt(0, ISR_PHASE_A, RISING); /* Interruption externe */
  attachInterrupt(1, ISR_PHASE_B, RISING); /* Interruption externe */
}

/**************************************************************************************
  loop
 **************************************************************************************/
 void loop() {
   // Send the value of counter
   if( counter != x ){
    Serial.println (counter);
    x = counter;
  }
}