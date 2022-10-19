/*
DS-CO2-20二氧化碳溫感測器
pin1 to 5V
pin2 to GND
pin3 to arduino GPIO12
pin4 to arduino GPIO13
剩下的pin5~pin7不接
參考資料:https://sites.google.com/mail3.hwsh.tc.edu.tw/earth/arduinoadvanced/co2-sensor-ds-co2-20
*/
HardwareSerial myHardwareSerial(1);

static unsigned int co2 = 0;
static unsigned int ucRxBuffer[10];

void setup() {
  Serial.begin(9600);
  delay(500);
  Serial1.begin(9600);
  myHardwareSerial.begin(9600, SERIAL_8N1, 12, 13); // Serial的TX,RX
  //
}

void loop(){
  //Serial1.listen();
  byte request[] = {0x42, 0x4d, 0xe3, 0x00, 0x00, 0x01, 0x72};
  Serial1.write(request, 7);
  delay(500);
  while (Serial1.available()){
    for(int i=0; i<12; i=i+1){
      ucRxBuffer[i]=Serial1.read();
      }
    co2 = ucRxBuffer[4]*256+ucRxBuffer[5];
    Serial.print("ppm:");
    Serial.println(co2);
    
    }
  delay(1000);  
}
