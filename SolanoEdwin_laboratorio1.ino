/*
 * UNIVERSIDAD TÉCNICA DEL NORTE 
 * FICA_CITEL
 * SISTEMAS EMBEBIDOS
 * LABORATORIO 1
 * Nombre: Solano Edwin
 * Fecha: 24/11/2020
 * OBJETIVOS: diseñar un sistema de control de acceso por medio de una cotraseña individual 
 *            coneccion por comunicacion serial
 *            mensaje de bienbenida
 *            mostrar usuarios ya ingresados
 * librerias 
 *           Keypad.h
 *           liquidCrystal.h
 *           
 * uso teclado matricial personalizado 
 * lcd 16x2
 * arduino uno
 * 
 */
 #include <Keypad.h>     // importa libreria Keypad para el teclado matricial
 #include <LiquidCrystal.h>  // importa la libreria para el LCD

  LiquidCrystal lcd(A0,A1,13,12,11,10); // pines  lcd RS,E,D4,D5,D6,D7
  const byte FILAS = 4;     // define numero de filas para el teclado
  const byte COLUMNAS = 4;    // define numero de columnas para el teclado
  char keys[FILAS][COLUMNAS] = {    // distribucion del teclado matricial
  {'7','8','9','A'},
  {'4','5','6','C'},
  {'1','2','3','J'},
  {'*','0','E','S'}
  };
  byte pinesFilas[FILAS] = {9,8,7,6};   // pines teclado filas
  byte pinesColumnas[COLUMNAS] = {5,4,3,2}; // pines teclado columnas
  int i;
  const int btn=A2;
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  // creacion del objeto del teclado

  char tecla;       // almacena la tecla presionada
  char pass[9];        // almacena en un array 8 digitos ingresados
    const char pass_1[9] = "CA900813";   //crea un vector y almacena los datos en ese vecto pass 1
    const char pass_2[9] = "AJ881112";   //crea un vector y almacena los datos en ese vecto pass 2
    const char pass_3[9] = "JA890109";   //crea un vector y almacena los datos en ese vecto pass 3
    const char pass_4[9] = "ES960823";   //crea un vector y almacena los datos en ese vecto pass 4
      String us1 = "BIENVENIDO Carlos Arias";   //variable tipo string con el dato de bienbenida usuario 1 
      String us2 = "BIENVENIDO Andres Juarez";  //variable tipo string con el dato de bienbenida usuario 2 
      String us3 = "BIENVENIDO Javier Andrada"; //variable tipo string con el dato de bienbenida usuario 3 
      String us4 = "BIENVENIDO Edwin Solano";   //variable tipo string con el dato de bienbenida usuario 4

       String usn1 = "Carlos Arias";   //variable tipo string con el dato de bienbenida usuario 1 
      String usn2 = "Andres Juarez";  //variable tipo string con el dato de bienbenida usuario 2 
      String usn3 = "Javier Andrada"; //variable tipo string con el dato de bienbenida usuario 3 
      String usn4 = "Edwin Solano";   //variable tipo string con el dato de bienbenida usuario 4
      String dato;
      String salida;
  int tam;
  byte inicio = 0;      // indice del array
void setup() {
  pinMode(btn,INPUT);
  lcd.begin(16,2);  // tamaño del lcd 2x16
    Serial.begin(9600);  //velocidad comunicacion serial 
    Serial.println("UTN_FICA_CITEL"); //imprime en pantalla
    Serial.println("Solano Edwin - Lab. 1"); //imprime en pantalla
      lcd.clear(); //borra datos del lcd anteriores
      lcd.setCursor(1,0);//posicion del cursor para imprimr
      lcd.println("pass: "); //imprime en el lcd
        delay(500); //temporizador
    Serial.println("DIGITE SU CONTRASEÑA: "); //imprime en la terminal
}

void loop() {
 if(digitalRead(btn)==HIGH){
  mostrar();  
    }
  
  tecla = teclado.getKey();   //obtiene valor del teclado matricial
    if (tecla){        //verifica que haya un dato
      pass[inicio] = tecla;    //almacena el dato en un array
      inicio++;       //incrementa para el siguiente dato
        lcd.setCursor(0,1); //posiciona el cursor del lcd
        lcd.println(tecla); //muestra en el lcd el valor ingresado
          Serial.print(tecla);    //muestra en la terminal por comunicacion serial los datos ingresados
            if(inicio == 8){     //cuando cumpla la condicion de tener 8 digitos en el array
              if(!strcmp(pass,pass_1)||!strcmp(pass,pass_2)||!strcmp(pass,pass_3)||!strcmp(pass,pass_4)){   //compara clave ingresada con la guardada
                //valida la pass 1 con el usuario
                if(!strcmp(pass,pass_1)){  
                  Serial.println("contrasena correcta...");  //imprime en la temrminal que se a ingresado la clave correcta
                  Serial.println(" ");  // Imprime un espacio en blanco
                  Serial.println(us1);  //imrpime el mensaje de bienbenida y el usuaurio perteneciente a la contraseña
                    lcd.setCursor(0,0);   //situa el cursor en inicio
                    lcd.print(us1);   //imrpime el mesnaje en el lcd
            for(int j=0; j<29; j++){   //arreglo para texto con rotacion de datos
                    lcd.scrollDisplayLeft();   //hacer rotacion de datos hacia la izquierda
                    delay(300);
            }
                     lcd.clear();
                }
                //valida la pass 2 con el usuario
                if(!strcmp(pass,pass_2)){
                  Serial.println(" Clave Correcta"); 
                  Serial.println(" ");
                  Serial.println(us2); 
                    lcd.clear();
                    lcd.setCursor(0, 0);
                    lcd.print(us2);
            for(int j=0; j<29; j++){
                    lcd.scrollDisplayLeft();
                    delay(300);
                }
                    lcd.clear();
                  }
                //valida la pass 3 con el usuario
                if(!strcmp(pass,pass_3)){
                  Serial.println(" Clave Correcta"); 
                  Serial.println(" ");
                  Serial.println(us3); 
                    lcd.clear();
                    lcd.setCursor(0, 0);
                    lcd.print(us3);
             for(int j=0; j<29; j++){
                    lcd.scrollDisplayLeft();
                    delay(300);
              }
                    lcd.clear();
          }
                //valida la pass 4 con el usuario
                if(!strcmp(pass,pass_4)){
                  Serial.println(" Clave Correcta"); 
                  Serial.println(" ");
                  Serial.println(us4); 
                    lcd.clear();
                    lcd.setCursor(0, 0);
                    lcd.print(us4);
              for(int j=0; j<29; j++){
                    lcd.scrollDisplayLeft();
                    delay(300);
                 }
                    lcd.clear();
          }
       }
         else{
          Serial.println(" contrasena incorrecta!!");  
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("pass incorrecto!!");
          delay(300);
        }
      inicio=0;   
    }  
  }
}
void mostrar(){
 if(!strcmp(pass,pass_1)||!strcmp(pass,pass_2)||!strcmp(pass,pass_3)||!strcmp(pass,pass_4)){   //compara clave ingresada con la guardada
                //valida la pass 1 con el usuario
                if(!strcmp(pass,pass_1)){  
          
                  Serial.println(" ");  // Imprime un espacio en blanco
                  Serial.println("usuarios ingresados: ");
                  Serial.println(usn1);  //imrpime el mensaje de bienbenida y el usuaurio perteneciente a la contraseña
                   Serial.println("usuarios no ingresados: ");
                   Serial.println(usn2);
                   Serial.println(usn3);
                   Serial.println(usn4);
                  
                }
                //valida la pass 2 con el usuario
                if(!strcmp(pass,pass_2)){
               
                     Serial.println(" ");  // Imprime un espacio en blanco
                  Serial.println("usuarios ingresados: ");
                  Serial.println(usn2);  //imrpime el mensaje de bienbenida y el usuaurio perteneciente a la contraseña
                   Serial.println("usuarios no ingresados: ");
                   Serial.println(usn1);
                   Serial.println(usn3);
                   Serial.println(usn4);
               
             
                  }
                //valida la pass 3 con el usuario
                if(!strcmp(pass,pass_3)){
                 
                   Serial.println(" ");  // Imprime un espacio en blanco
                  Serial.println("usuarios ingresados: ");
                  Serial.println(usn3);  //imrpime el mensaje de bienbenida y el usuaurio perteneciente a la contraseña
                   Serial.println("usuarios no ingresados: ");
                   Serial.println(usn1);
                   Serial.println(usn2);
                   Serial.println(usn4); 
              
          }
                //valida la pass 4 con el usuario
                if(!strcmp(pass,pass_4)){
                  
                   Serial.println(" ");  // Imprime un espacio en blanco
                  Serial.println("usuarios ingresados: ");
                  Serial.println(usn4);  //imrpime el mensaje de bienbenida y el usuaurio perteneciente a la contraseña
                   Serial.println("usuarios no ingresados: ");
                   Serial.println(usn1);
                   Serial.println(usn2);
                   Serial.println(usn3);
                
          }
       }
       else{
        Serial.println("ningun usuaruo a ingresado");
        }
        inicio=0;
  }
   
