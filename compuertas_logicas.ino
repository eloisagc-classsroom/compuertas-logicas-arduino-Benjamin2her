* 
  Compuertas Lógicas - ARDUINO UNO R3
  Benjamin Hernández Herrera
*/

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
  
}

void loop()
{
    // not_bit(3, 4);
    and_bit(2,3,4);
    //nand_bit(2,3,4);
    //or_bit(2,3,4);
    //nor_bit(2,3,4);
    //xor_bit(2,3,4);
    //xnor_bit(2,3,4);
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