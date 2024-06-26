/* 
  Compuertas Lógicas - ARDUINO UNO R3
  Benjamin Hernández Herrera
*/


int option = 0;

// Declaración de las Compuertas Lógicas

void not_bit(int in, int out);
void and_bit(int in_a, int in_b, int out);
void nand_bit(int in_a, int in_b, int out);
void or_bit(int in_a, int in_b, int out);
void nor_bit(int in_a, int in_b, int out);
void xor_bit(int in_a, int in_b, int out);
void xnor_bit(int in_a, int in_b, int out);

void setup()
{
    // Entradas y salidas de las compuertas lógicas
    pinMode(2, INPUT);
    pinMode(3, INPUT);
    pinMode(4, OUTPUT);
  
    // Entradas binarias de selección
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    pinMode(10, INPUT);

    // Se inicializa el puerto Serial
    Serial.begin(9600);
}

void loop()
{
    //Se lee de forma binaria la entrada del DIP-SWITCH

    option = digitalRead(8) + 2*digitalRead(9) + 4*digitalRead(10);
    Serial.println(option);

    // En base a la opción se escoge la compuerta lógica
    switch(option){
        case 0: 
            Serial.println("Compuerta Logica - NOT");
            not_bit(3, 4);
        break;
        case 1:
            Serial.println("Compuerta Logica - AND");
            and_bit(2,3,4);
        break;
        case 2:
            Serial.println("Compuerta Logica - NAND");
            nand_bit(2,3,4);
        break;
        case 3:
            Serial.println("Compuerta Logica - OR");
            or_bit(2,3,4);
        break;
        case 4:
            Serial.println("Compuerta Logica - NOR");
            nor_bit(2,3,4);
        break;
        case 5:
            Serial.println("Compuerta Logica - XOR");
            xor_bit(2,3,4);
        break;
        case 6:
            Serial.println("Compuerta Logica - XNOR");
            xnor_bit(2,3,4);
        break;
        default:
            Serial.println("Opcion NO VALIDA");
        break;
    }
}

// Definición de las Compuertas Lógicas

// NOT - La salida es el valor contrario a la entrada
void not_bit(int in, int out){
    if (digitalRead(in) == HIGH){
        digitalWrite(out, LOW);
    }
    else{
        digitalWrite(out, HIGH);
    }
}

//AND - La salida es alta si ambas entradas son altas
void and_bit(int in_a, int in_b, int out){
    if (digitalRead(in_a) == HIGH && digitalRead(in_b) == HIGH){
        digitalWrite(out, HIGH);
    }
    else{
        digitalWrite(out, LOW);
    }
}

//NAND - La salida es alta si ambas entradas son altas
void nand_bit(int in_a, int in_b, int out){
    if (digitalRead(in_a) == HIGH && digitalRead(in_b) == HIGH){
        digitalWrite(out, LOW);
    }
    else{
        digitalWrite(out, HIGH);
    }
}

//OR - La salida es alta si alguna o todas las entradas son altas
void or_bit(int in_a, int in_b, int out){
    if (digitalRead(in_a) == HIGH || digitalRead(in_b) == HIGH){
        digitalWrite(out, HIGH);
    }
    else{
        digitalWrite(out, LOW);
    }
}

//NOR - La salida es baja si alguna o todas las entradas son altas
void nor_bit(int in_a, int in_b, int out){
    if (digitalRead(in_a) == HIGH || digitalRead(in_b) == HIGH){
        digitalWrite(out, LOW);
    }
    else{
        digitalWrite(out, HIGH);
    }
}

//XOR - La salida es alta si solo una entrada es alta
void xor_bit(int in_a, int in_b, int out){
    if (digitalRead(in_a) == digitalRead(in_b)){
        digitalWrite(out, LOW);
    }
    else{
        digitalWrite(out, HIGH);
    }
}

//XNOR - La salida es baja si solo una entrada es alta
void xnor_bit(int in_a, int in_b, int out){
    if (digitalRead(in_a) == digitalRead(in_b)){
        digitalWrite(out, HIGH);
    }
    else{
        digitalWrite(out, LOW);
    }
}
