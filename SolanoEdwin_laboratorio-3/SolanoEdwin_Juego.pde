/*
*UTN-FICA-CITEL7
*SISTEMAS EMBEBIDOS
*OBJETIVO: diseñar un juego de atari
*Nombre: Solano Ediwn
*/
import ddf.minim.*;
import processing.serial.*;//obtener los datos por counicacion serial
Serial puerto;//nombre del puerto 
PImage img;//variable para ingresar imagen
int x=100;//posicion inicial en x
int y=100; //posicion inicial en y
int velX=3;//velocidad inicial de la pelota en x
int velY=3;//velocidad inicial de la pelota en y
int posicionX;//posiicon del la barra
String dato="";//cadena de caracteres se inicializa con una variable vacia 
float valor; //para obtener los datos 
int Xini; //posicion inicial
int cont=0;//contador de puntos
boolean gameOver=false;//variable para reiniciar juego
Minim finJuego;
AudioPlayer play1;

void setup(){
size(600,450);//tamaño de la pantalla
finJuego=new Minim(this);

img=loadImage("12.jpg");//cargamos la imagen
image(img,0,0);//posicion de la imagen
puerto=new Serial(this,"COM10",9600);//comunicacion con el arduino virtual

}

void draw(){
if(puerto.available()>0){//verificar si el puerto esta disponible
dato=puerto.readStringUntil('\n');
if(dato==null){//verificar si el dato no contiene nada
return;//volver a verficar el dato
}
valor=float(dato);//guardar el dato en una variable flotante
}
if(valor==1){//moverse a la izquierda
  posicionX-=10;//mover la barra a la izquierda
}
else if(valor==2 ){//moverse a la derecha
posicionX+=10;//mover la barra a la derecha
}
println(valor);//ver dato en la consola
background(99,99,99);//color de fondo
Xini=200+posicionX;//inicializacion de la barra 
image(img,0,0);//cargar imagen en la posicion
fill(#1FDFFF);//color del rectangulo
rect(Xini,420,180,30);//creacion e posicion
fill(#14FF00);//color de la bola
ellipse(x,y,40,40);//creasion y posiicion
x+=velX;//velocidad de la vola en x
if(x>580||x<20){//cuadno choca con las paredes
  velX=velX*-1;//aumenta la velocidad
}
y+=velY;//velocidad de la bola en y
if(y>height || y<0){//cuando choca 
velY=velY*-1;//aumento de velocidad
}

if(y>=410 && (x<Xini+180) && (x>Xini)){//cuando la barra topa
velY=-(velY+1);//aumentar velocidad
velX+=1;//aumentar velocidad
cont++;//sumar la puntuacion
}
textSize(10);//tamaño de texto
text("PUNTUACION: ",30,30);//mensaje de la puntuacion
text(cont,120,30);//contador de la puntuacion

if(y>=450){//cuadno no se halla la bola
    fill(#FFFAFF);
    textSize(40);
     play1=finJuego.loadFile("sonidoFin.wav");
     text("GAME OVER",200,250);
     gameOver=true;
}
if (gameOver==true) {//reinicio de juego
restart();//llamar al metodo
    } 
}

void restart(){//reiniciar juego
gameOver=false;//reinicio de variables
x=100;
y=100;
velX=3;
velY=3;
cont=0;
}
