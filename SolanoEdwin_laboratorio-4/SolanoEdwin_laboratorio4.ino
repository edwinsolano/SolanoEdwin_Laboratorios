/*
 * UTN-FICA-CITEL
 * SISTEMAS EMBEBIDOS 
 * CODIGO: APRENDIZAJE DE MAQUINA-REGRESION LINEAL
 * LABORATORIO 4
 * Nombre: Solano Edwin
 * OBJETIVO: Imprimir los puntos del conjunto de entrenamiento correspondientes a la regresion lineal
 *           Al ingresar un nuevo valor por comunicacion serial al sistema electronico, realizar el pronostico (en
 *           epedencia de la interfaz si se desea una tendencia lineal o exponencial) y graficarlo en la interfaz
 *           con un color diferente a lo ya visto del conjunto de entrenamiento.
 * 
 */
 #include <SoftwareSerial.h>//libreria que permite la coneccion serial con otros pines del arduino
#define rxCOM 5//pin 5 para recibir datos
#define txCOM 6//pin 6 para evio de datos
const int boton1=3;//inicio de pin

SoftwareSerial cxSerial =  SoftwareSerial(rxCOM, txCOM);//conexion serial con otros pines del arduino

// matriz de datos
int matriz[14][2]={
{170,67},
{180,80},
{170,65},
{178,75},
{160,55},
{163,60},
{165,63},
{170,70},
{164,62},
{176,77},
{164,60},
{170,76},
{170,56},
{168,60},
};

int col=0; //moverse en columnas
int fil=0; //moverse en filas
int Ex=0; //sumatoria x
int Ey=0; //sumatoria y
long int Exy=0; //sumatoria xy
long int Ex2=0; //sumatoria x^2
long int Ex_2=0; //sumatoria Ex^2
int n= 14; //nuemero de muestras 
float Bo; //ordenada en el origen
float m; //pendiente
String dato; //recibir estatura
int estatura; //convertir dato
float peso;//varibale para almacenar dato de peso
int m1; //auxiliar

void setup() {
  pinMode(boton1,INPUT);
  pinMode(rxCOM, INPUT);//entrada de datos
  pinMode(txCOM, OUTPUT);//salida de datos
  cxSerial.begin(9600);//conceccion con pin 5 y 6 para el puerto COM
  Serial.begin(9600);//conceccion CX
  //creacion del modelo
  for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];
    Ey=Ey+matriz[fil][1];
    Exy=Exy+(matriz[fil][0]*matriz[fil][1]);
    Ex2=Ex2+pow(matriz[fil][0],2);
  }
  Ex_2=pow(Ex,2);//elevar al cuadrado
  Bo=(float(Ex2*Ey)-float(Ex*Exy))/(float(n*Ex2-Ex_2));//calculo de la ordenada en el origen
  m1=(n*Exy)-(Ex*Ey); //auxiliar
  m=(float(m1))/(float(n*Ex2-Ex_2));//calculo de la pendiente
  Serial.println("El modelo es: ");//impresion de texto
  Serial.println(String("y= ")+String(Bo)+String("+")+String(m)+String("x"));//impresion de la pendiente
  Serial.println("Ingrese su estatura: ");//peticion de ingreso de dato

   if(digitalRead(boton1)==HIGH){//cuadno se lea el boton 1 en alto
  Serial.println("3");//mandar mensaje 
  delay(40);//temporizador
 }
}

void loop() {
  if(Serial.available()>0){//verificar si existe dato
    dato=Serial.readString();//leer dato y convertir a enterr
    estatura=dato.toInt();//guardar ese dato en la variable
    peso=m*estatura+Bo;//calcular el peso con los datos ingresados y los almacendados en el sistema
    Serial.println("");//impreison de texto
    Serial.println("UTN-FICA-CITEL");//impreison de texto
    Serial.println("calculo de peso");//impreison de texto
    Serial.println(String("Su peso es: ")+String(peso)+String("Kg"));//impreison de texto
    Serial.println("Ingrese su estatura: ");//impreison de texto
    cxSerial.write(estatura);//escribir en la comunicacion serial
  }
}
