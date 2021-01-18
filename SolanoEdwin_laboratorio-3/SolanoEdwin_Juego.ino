/*
 * UTN-FICA-CITEL
 * sistemas embebidos 
 * objetivo: concetar pines y cx para enviar datos a procesing
 * Nombre: Solano Edwin
 */
 const int boton1=3;//inicio de pin
const int boton2=4;//inicio de pin
const int boton3=5;//inicio de pin
void setup() {
 Serial.begin(9600);//comunicacion con CX
 pinMode(boton1,INPUT);//pin 3 como entrada de datos
 pinMode(boton2,INPUT);//pin 3 como entrada de datos
 pinMode(boton3,INPUT);//pin 3 como entrada de datos
}
void loop() {
 if(digitalRead(boton1)==HIGH){//cuadno se lea el boton 1 en alto
  Serial.println("1");//mandar mensaje 
  delay(40);//temporizador
 }
 if(digitalRead(boton2)==HIGH){//cuadno se lea el boton 2 en alto
  Serial.println("2");//mandar mensaje 
  delay(40);//temporizador
 }
 if(digitalRead(boton3)==HIGH){//cuadno se lea el boton 3 en alto
  Serial.println("3");//mandar mensaje 
  delay(40);//temporizador
 }
 if(digitalRead(boton1)==LOW && digitalRead(boton2)==LOW && digitalRead(boton3)==LOW){//cuando no haya ningun boton precionado
  Serial.println("9");
  delay(40);//temporizador
 }
}
