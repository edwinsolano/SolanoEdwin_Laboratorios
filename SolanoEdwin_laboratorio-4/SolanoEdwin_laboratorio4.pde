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
import processing.serial.*;

Serial port;
float datoEstatura;
float auxEstatura=0;
float datoPeso;
int aux=0;
float valor;
String dato;

void setup (){
  port= new Serial(this, "COM10",9600);//comunicacion con el puerto COM virtual
  size(1000,600); // tamaño cuadro
  background(#43EEFF); //color de fondo
   ejes();//llamar al metodo para graficar los ejes X y Y
   verticales();//llamar para graficar las lineas verticales
   horizontales();//llamar al metodo para graficar las lineas horizontales
   valorXY();//agreagr el texto de los datos 
   texto();//impresion en el fondo
}

void serialEvent(Serial port){
  datoEstatura=port.read();//leer el puerto si existe dato
  auxEstatura=int(datoEstatura); //cambier tipo de dato
  println("ESTATURA: ");//texto 
  println(datoEstatura);//imprimir el valor
  datoPeso=datoEstatura*(1.1797)-133.39;//formula para calcular el peso
  println("PESO: ");//texto
  println(datoPeso);//imprimir el valor 
   
}

void draw(){  
  if(datoPeso>0){
  stroke(#FC0015);
  strokeWeight(2);
  fill(#FC0015);
  ellipse((datoEstatura*15)-2200,450-(datoPeso)*5,10,10);
  }
     puntos();
  
  stroke(#000AFA);
  strokeWeight(1);
  line(150*15-2200,450-43.565*5,(190*15)-2200,450-90.753*5); //pendiente
  
  if(datoEstatura>0 && datoPeso>0){
  textSize(20);
  fill(0);
  text(datoEstatura,700,175);
  text(datoPeso,700,200);
  }
}
void ejes(){
  stroke(0);
  strokeWeight(1);
  line(50,5,50,450);
  line(50,450,650,450);
  line(50,450,650,450);
}
void puntos(){
  stroke(#000000);
  strokeWeight(2);
  fill(#DD77DE);
  ellipse((170*15)-2200,450-67*5,5,5); //graficacion del punto 
  ellipse((180*15)-2200,450-80*5,5,5); //graficacion del punto 
  ellipse((170*15)-2200,450-65*5,5,5); //graficacion del punto 
  ellipse((178*15)-2200,450-75*5,5,5); //graficacion del punto 
  ellipse((160*15)-2200,450-55*5,5,5); //graficacion del punto 
  ellipse((163*15)-2200,450-60*5,5,5); //graficacion del punto 
  ellipse((165*15)-2200,450-63*5,5,5); //graficacion del punto 
  ellipse((170*15)-2200,450-70*5,5,5); //graficacion del punto 
  ellipse((164*15)-2200,450-62*5,5,5); //graficacion del punto 
  ellipse((176*15)-2200,450-77*5,5,5); //graficacion del punto 
  ellipse((164*15)-2200,450-60*5,5,5); //graficacion del punto 
  ellipse((170*15)-2200,450-76*5,5,5); //graficacion del punto 
  ellipse((170*15)-2200,450-56*5,5,5); //graficacion del punto 
  ellipse((168*15)-2200,450-60*5,5,5); //graficacion del punto 
}

void verticales(){
  stroke(#F20000);
  strokeWeight(1);
  line(125,5,125,450);//graficacion de la linea vertical
  line(200,5,200,450);//graficacion de la linea vertical
  line(275,5,275,450);//graficacion de la linea vertical
  line(350,5,350,450);//graficacion de la linea vertical
  line(425,5,425,450);//graficacion de la linea vertical
  line(500,5,500,450);//graficacion de la linea vertical
  line(575,5,575,450);//graficacion de la linea vertical
  line(650,5,650,450);//graficacion de la linea vertical
}
void horizontales(){
 line(50,400,650,400);//graficacion de la linea horizontal
 line(50,375,650,375);//graficacion de la linea horizontal
 line(50,350,650,350);//graficacion de la linea horizontal
 line(50,325,650,325);//graficacion de la linea horizontal
 line(50,300,650,300);//graficacion de la linea horizontal
 line(50,275,650,275);//graficacion de la linea horizontal
 line(50,250,650,250);//graficacion de la linea horizontal
 line(50,225,650,225);//graficacion de la linea horizontal
 line(50,200,650,200);//graficacion de la linea horizontal
 line(50,175,650,175);//graficacion de la linea horizontal
 line(50,150,650,150);//graficacion de la linea horizontal
 line(50,125,650,125);//graficacion de la linea horizontal
 line(50,100,650,100);//graficacion de la linea horizontal
 line(50,75,650,75);//graficacion de la linea horizontal
 line(50,50,650,50);//graficacion de la linea horizontal
 line(50,25,650,25);//graficacion de la linea horizontal
  }
  
  void valorXY(){
  textSize(20);
  fill(0);
  //datos del eje y
  text("0",25,450);
  text("5",25,425);
  text("10",25,400);
  text("15",25,375);
  text("20",25,350);
  text("25",25,325);
  text("30",25,300);
  text("35",25,275);
  text("40",25,250);
  text("45",25,225);
  text("50",25,200);
  text("55",25,175);
  text("60",25,150);
  text("65",25,125);
  text("70",25,100);
  text("75",25,75);
  text("80",25,50);
  text("85",25,25);
  //datos en el eje x
  text("150",50,470);
  text("155",125,470);
  text("160",200,470);
  text("165",275,470);
  text("170",350,470);
  text("175",425,470);
  text("180",500,470);
  text("185",575,470);
  text("190",650,470);
  }
  
  void texto(){
  textSize(20);
  fill(0);
  text("UTN_FICA_CITEL",750,50);
  text("LAB 4_SOLANO EDWIN",725,75);
  text("y=1.1797x-133.39",750,100);
  text("PESO-ESTATURA",700,150);
  text("GRAFICA EN FUNCION DEL PESO Y LA ESTATURA",80,520);
  }
