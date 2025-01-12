#include <Keypad.h>

// Definimos el tamaño del teclado 4x4
const byte ROW_NUM    = 4;  // Cuatro filas
const byte COLUMN_NUM = 4;  // Cuatro columnas

// Mapa de teclas del teclado numérico 4x4
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Definimos los pines de filas y columnas
byte pin_rows[ROW_NUM] = {2, 3, 4, 5};
byte pin_column[ COLUMN_NUM] = {6, 7, 8, 9};

// Crear el objeto Keypad
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

// Definir la contraseña correcta (en este caso "1234")
const String correctPassword = "1234";
String enteredPassword = "";

void setup(){
  Serial.begin(9600);  // Inicializamos la comunicación serial
  Serial.println("Por favor ingresa la contraseña:");
}

void loop(){
  char key = keypad.getKey();  // Leer la tecla presionada

  if (key) {  // Si se presionó una tecla
    if (key == '#') {  // Si se presiona el botón '#' (para enviar la contraseña)
      if (enteredPassword == correctPassword) {
        Serial.println("Contraseña correcta!");
      } else {
        Serial.println("Contraseña incorrecta. Intenta de nuevo.");
      }
      enteredPassword = "";  // Reiniciar la contraseña ingresada
    } 
    else if (key == '*') {  // Si se presiona '*' (para borrar un caracter)
      if (enteredPassword.length() > 0) {
        enteredPassword.remove(enteredPassword.length() - 1);
        Serial.print("Contraseña ingresada: ");
        Serial.println(enteredPassword);  // Muestra la contraseña ingresada hasta el momento
      }
    } 
    else {  // Si se presiona cualquier número
      enteredPassword += key;  // Agregar la tecla a la contraseña ingresada
      Serial.print("Contraseña ingresada: ");
      Serial.println(enteredPassword);  // Muestra la contraseña ingresada hasta el momento
    }
  }
}
