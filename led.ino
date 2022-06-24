

const int r_led = 3;
const int g_led = 5;
const int b_led = 6;


void setup() {
Serial.begin(9600);
pinMode(r_led, OUTPUT);
pinMode(g_led, OUTPUT);
pinMode(b_led, OUTPUT);

// Making Sure that the leds are off
analogWrite(r_led,0);
analogWrite(g_led,0);
analogWrite(b_led,0);
}

void loop() {
  
// getting the value from the mobile
if(Serial.available() > 0){
int r_value = Serial.parseInt();
int g_value = Serial.parseInt();
int b_value = Serial.parseInt();

// print values of rgb
Serial.print(r_value);
Serial.print(", ");
Serial.print(g_value);
Serial.print(", ");
Serial.println(b_value);

// for The common cathod buld
r_value = 255 - constrain(r_value, 0, 255);
g_value = 255 - constrain(g_value, 0, 255);
b_value = 255 - constrain(b_value, 0, 255);


// Writting the values in the rgb leds
analogWrite(r_led,r_value);
analogWrite(g_led,g_value);
analogWrite(b_led,b_value);

// This is for getting rid of zeroes because of new line
if(Serial.read() == '\n'){
}

  
}}
