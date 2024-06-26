#include <ArduinoBLE.h>
#include  <SoftwareSerial.h>
SoftwareSerial Extrude(4, 5); // RX, TX
SoftwareSerial Spool(21, 22);
// SERVICES
 
// notify value to the app
BLEService filamentizeStatusNotifyService("dcc3a689-02c2-4bb9-a1b6-e1e2b5b907f9");
BLEService filamentizeNotifyService("19B10010-E8F2-537E-4F6C-D104768A1214");
BLEService filamentizeNotifyTwoService("304fbc9f-cf0c-4b00-b225-caef4659afb7");
BLEService filamentizeNotifyThreeService("a4d81339-57f8-44ce-891b-da595a64054a");
 
// receive value from the app
BLEService filamentizeStatusService("be521797-74c2-44c4-bc3b-e09a595099ba");
BLEService filamentizeStatusTwoService("0e282f24-39be-42cd-ac48-103cc9873b66");
BLEService spoolService("33421725-32cd-41b9-9391-e21e7351efb1");
BLEService resetspoolService("74245475-0323-44b0-9da0-03752f3e2a68");
BLEService stepperService("f7edc684-511a-4bc2-9996-26770c647faa");
BLEService extruderService("261ca617-7b54-4005-aec6-206380460110");
BLEService vibratorService("1425a1a0-ecc3-4333-85a3-b453fa00362c");
BLEService colorService("6bd9066f-304e-48d1-8fe5-e4a2c80b383a");
 
// ONE
 
// services
BLEService coolingFanOneService("8678e46d-2eb1-4c53-ba7e-cff66baebcc4");
BLEService tempOneService("fda1ccbf-c272-42d4-adbc-35455fb6a350");
 
// characteristics
BLEStringCharacteristic coolingFanOneWriteCharacteristic("8678e46d-2eb1-4c53-ba7e-cff66baebcc4", BLEWrite, 6);
BLEStringCharacteristic tempOneWriteCharacteristic("fda1ccbf-c272-42d4-adbc-35455fb6a350", BLEWrite, 6);
 
// descriptors
BLEDescriptor coolingFanOneWriteLabel("8678e46d-2eb1-4c53-ba7e-cff66baebcc4", "cooling fan01 write");
BLEDescriptor tempOneWriteLabel("fda1ccbf-c272-42d4-adbc-35455fb6a350", "temp01 write");
 
// TWO
 
// services
BLEService coolingFanTwoService("f95755bb-7823-4b8d-afc9-9aefede3e458");
BLEService tempTwoService("b03f93bb-0003-4e10-b364-e3a49cfaf5e2");
 
// characteristics
BLEStringCharacteristic coolingFanTwoWriteCharacteristic("f95755bb-7823-4b8d-afc9-9aefede3e458", BLEWrite, 6);
BLEStringCharacteristic tempTwoWriteCharacteristic("b03f93bb-0003-4e10-b364-e3a49cfaf5e2", BLEWrite, 6);
 
// descriptors
BLEDescriptor coolingFanTwoWriteLabel("f95755bb-7823-4b8d-afc9-9aefede3e458", "cooling fan02 write");
BLEDescriptor tempTwoWriteLabel("b03f93bb-0003-4e10-b364-e3a49cfaf5e2", "temp02 write");
 
// other characteristics
BLEStringCharacteristic filamentizeStatusNotifyCharacteristic("dcc3a689-02c2-4bb9-a1b6-e1e2b5b907f9", BLENotify, 20);
 
BLEStringCharacteristic filamentizeNotifyCharacteristic("19B10012-E8F2-537E-4F6C-D104768A1214", BLENotify, 20);
 
BLEStringCharacteristic filamentizeNotifyTwoCharacteristic("304fbc9f-cf0c-4b00-b225-caef4659afb7", BLENotify, 20);
 
BLEStringCharacteristic filamentizeNotifyThreeCharacteristic("a4d81339-57f8-44ce-891b-da595a64054a", BLENotify, 20);
 
BLEStringCharacteristic filamentizeStatusCharacteristic("be521797-74c2-44c4-bc3b-e09a595099ba", BLEWrite, 6);
 
BLEStringCharacteristic filamentizeStatusTwoCharacteristic("0e282f24-39be-42cd-ac48-103cc9873b66", BLEWrite, 15);
 
BLEStringCharacteristic spoolWriteCharacteristic("33421725-32cd-41b9-9391-e21e7351efb1", BLEWrite, 6);
 
BLEStringCharacteristic resetspoolWriteCharacteristic("74245475-0323-44b0-9da0-03752f3e2a68", BLEWrite, 6);
 
BLEStringCharacteristic stepperWriteCharacteristic("f7edc684-511a-4bc2-9996-26770c647faa", BLEWrite, 6);
 
BLEStringCharacteristic extruderWriteCharacteristic("261ca617-7b54-4005-aec6-206380460110", BLEWrite, 6);
 
BLEStringCharacteristic vibratorWriteCharacteristic("1425a1a0-ecc3-4333-85a3-b453fa00362c", BLEWrite, 6);
 
BLEStringCharacteristic colorWriteCharacteristic("6bd9066f-304e-48d1-8fe5-e4a2c80b383a", BLEWrite, 6);
 
// other descriptors
 
BLEDescriptor filamentizeStatusNotifyLabel("dcc3a689-02c2-4bb9-a1b6-e1e2b5b907f9", "filamentizeStatusNotify");
 
BLEDescriptor testNotifyLabel("19B10011-E8F2-537E-4F6C-D104768A1214", "filamentizeOne notify");
 
BLEDescriptor filamentizeNotifyTwoLabel("304fbc9f-cf0c-4b00-b225-caef4659afb7", "filamentizeTwo notify");
 
BLEDescriptor filamentizeNotifyThreeLabel("304fbc9f-cf0c-4b00-b225-caef4659afb7", "filamentizeThree notify");
 
BLEDescriptor filamentizeStatusLabel("be521797-74c2-44c4-bc3b-e09a595099ba", "filamentizeStatus write");
 
BLEDescriptor filamentizeStatusTwoLabel("0e282f24-39be-42cd-ac48-103cc9873b66", "filamentizeStatusMode write");
 
BLEDescriptor spoolWriteLabel("33421725-32cd-41b9-9391-e21e7351efb1", "spool write");
 
BLEDescriptor resetspoolWriteLabel("74245475-0323-44b0-9da0-03752f3e2a68", "reset spool write");
 
BLEDescriptor stepperWriteLabel("f7edc684-511a-4bc2-9996-26770c647faa", "stepper write");
 
BLEDescriptor extruderWriteLabel("261ca617-7b54-4005-aec6-206380460110", "extruder write");
 
BLEDescriptor vibratorWriteLabel("1425a1a0-ecc3-4333-85a3-b453fa00362c", "vibrator write");
 
BLEDescriptor colorWriteLabel("6bd9066f-304e-48d1-8fe5-e4a2c80b383a", "color write");
 
unsigned long previousMillis = 0;
const long interval = 1000;
 
int Bit = 0;
 
String deviceStatus = "Off";
String deviceMode = "Filamentize";
 
// rl temp
int rlTemp01 = 0;
int rlTemp02 = 0;
 
// set temp
int temp01 = 0;
int temp02 = 0;
 
// rl cooling fans
int rlCoolingFan01 = 0;
int rlCoolingFan02 = 0;
 
// cooling fans
int coolingFan01 = 0;
int coolingFan02 = 0;
 
// percent
int spoolMotor = 0;
int resetspoolMotor = 0;
int extruder = 0;
int windingStepper = 0;
int vibrator = 0;
 
int spoolReset = 0;
 
int Color1 = 12;
int Color2 = 14;
int Color3 = 27;
int Color4 = 26;
 
// color
String selectedColor = "";


void setup() {
  Serial.begin(115200);
  pinMode(Color1, OUTPUT);
  pinMode(Color2, OUTPUT);
  pinMode(Color3, OUTPUT);
  pinMode(Color4, OUTPUT);
  initExtrude();
  initSpool();
  while (!Serial);
 
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
 
    while (1);
  }
 
  // set device, local name
  BLE.setDeviceName("Filamentize#ABC1");
  BLE.setLocalName("Filamentize#ABC1");
 
  // advertise all services
  BLE.setAdvertisedService(filamentizeStatusNotifyService);
  BLE.setAdvertisedService(filamentizeNotifyService);
  BLE.setAdvertisedService(filamentizeNotifyTwoService);
  BLE.setAdvertisedService(filamentizeNotifyThreeService);
  BLE.setAdvertisedService(filamentizeStatusService);
  BLE.setAdvertisedService(filamentizeStatusTwoService);
  BLE.setAdvertisedService(spoolService);
  BLE.setAdvertisedService(resetspoolService);
  BLE.setAdvertisedService(stepperService);
  BLE.setAdvertisedService(extruderService);
  BLE.setAdvertisedService(vibratorService);
  BLE.setAdvertisedService(colorService);
 
  // coolingfan01 + temp01
  BLE.setAdvertisedService(coolingFanOneService);
  BLE.setAdvertisedService(tempOneService);
 
  // coolingfan02 + temp02
  BLE.setAdvertisedService(coolingFanTwoService);
  BLE.setAdvertisedService(tempTwoService);
 
  // add descriptors
 
  filamentizeStatusNotifyCharacteristic.addDescriptor(filamentizeStatusNotifyLabel);
 
  filamentizeNotifyCharacteristic.addDescriptor(testNotifyLabel);
 
  filamentizeNotifyTwoCharacteristic.addDescriptor(filamentizeNotifyTwoLabel);
 
  filamentizeNotifyThreeCharacteristic.addDescriptor(filamentizeNotifyThreeLabel);
 
  filamentizeStatusCharacteristic.addDescriptor(filamentizeStatusLabel);
 
  filamentizeStatusTwoCharacteristic.addDescriptor(filamentizeStatusTwoLabel);
  spoolWriteCharacteristic.addDescriptor(spoolWriteLabel);
 
  resetspoolWriteCharacteristic.addDescriptor(resetspoolWriteLabel);
 
  stepperWriteCharacteristic.addDescriptor(stepperWriteLabel);
 
  coolingFanOneWriteCharacteristic.addDescriptor(coolingFanOneWriteLabel);
  tempOneWriteCharacteristic.addDescriptor(tempOneWriteLabel);
 
  coolingFanTwoWriteCharacteristic.addDescriptor(coolingFanTwoWriteLabel);
  tempTwoWriteCharacteristic.addDescriptor(tempTwoWriteLabel);
 
  extruderWriteCharacteristic.addDescriptor(extruderWriteLabel);
 
  vibratorWriteCharacteristic.addDescriptor(vibratorWriteLabel);
 
  colorWriteCharacteristic.addDescriptor(colorWriteLabel);
 
  // add characteristics to services
 
  filamentizeStatusNotifyService.addCharacteristic(filamentizeStatusNotifyCharacteristic);
 
  filamentizeNotifyService.addCharacteristic(filamentizeNotifyCharacteristic);
 
  filamentizeNotifyTwoService.addCharacteristic(filamentizeNotifyTwoCharacteristic);
 
  filamentizeNotifyThreeService.addCharacteristic(filamentizeNotifyThreeCharacteristic);
 
  filamentizeStatusService.addCharacteristic(filamentizeStatusCharacteristic);
 
  filamentizeStatusTwoService.addCharacteristic(filamentizeStatusTwoCharacteristic);
 
  spoolService.addCharacteristic(spoolWriteCharacteristic);
 
  resetspoolService.addCharacteristic(resetspoolWriteCharacteristic);
 
  stepperService.addCharacteristic(stepperWriteCharacteristic);
 
  tempOneService.addCharacteristic(tempOneWriteCharacteristic);
  coolingFanOneService.addCharacteristic(coolingFanOneWriteCharacteristic);
 
  tempTwoService.addCharacteristic(tempTwoWriteCharacteristic);
  coolingFanTwoService.addCharacteristic(coolingFanTwoWriteCharacteristic);
 
  extruderService.addCharacteristic(extruderWriteCharacteristic);
 
  vibratorService.addCharacteristic(vibratorWriteCharacteristic);
 
  colorService.addCharacteristic(colorWriteCharacteristic);
 
  // add services to ble
 
  BLE.addService(filamentizeStatusNotifyService);
  BLE.addService(filamentizeNotifyService);
  BLE.addService(filamentizeNotifyTwoService);
  BLE.addService(filamentizeNotifyThreeService);
  BLE.addService(filamentizeStatusService);
  BLE.addService(filamentizeStatusTwoService);
  BLE.addService(spoolService);
  BLE.addService(resetspoolService);
  BLE.addService(stepperService);
  BLE.addService(extruderService);
  BLE.addService(vibratorService);
  BLE.addService(colorService);
 
  BLE.addService(coolingFanOneService);
  BLE.addService(tempOneService);
 
  BLE.addService(coolingFanTwoService);
  BLE.addService(tempTwoService);
 
  // write started value
 
  filamentizeNotifyCharacteristic.writeValue("0");
 
  filamentizeStatusNotifyCharacteristic.writeValue("0");
 
  filamentizeNotifyTwoCharacteristic.writeValue("0");
 
  filamentizeNotifyThreeCharacteristic.writeValue("0");
 
  coolingFanOneWriteCharacteristic.writeValue("0");
  tempOneWriteCharacteristic.writeValue("0");
 
  coolingFanTwoWriteCharacteristic.writeValue("0");
  tempTwoWriteCharacteristic.writeValue("0");
 
  spoolWriteCharacteristic.writeValue("0");
  resetspoolWriteCharacteristic.writeValue("0");
 
  extruderWriteCharacteristic.writeValue("0");
 
  stepperWriteCharacteristic.writeValue("0");
 
  vibratorWriteCharacteristic.writeValue("0");
 
  filamentizeStatusCharacteristic.writeValue("Off");
 
  filamentizeStatusTwoCharacteristic.writeValue("Filamentize");
 
  colorWriteCharacteristic.writeValue("0");
 
  BLE.advertise();
 
  Serial.println("Bluetooth® device active, waiting for connections...");
}
void loop() {
  BLE.poll();
 
  digitalWrite(Color1, LOW);
  digitalWrite(Color2, LOW);
  digitalWrite(Color3, LOW);
  digitalWrite(Color4, LOW);
 
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
 
    // prepare filamentize status notify string
    String statusNotifyValue = deviceStatus + "/" + deviceMode + "/" + spoolReset;
 
    // prepare filamentize notify one string
    String tempNotifyValue = String(rlTemp01) + "/" + String(rlTemp02) + "/" + String(temp01) + "/" + String(temp02);
 
    // prepare filamentize notify two string
    String coolingFansNotifyValue = String(rlCoolingFan01) + "/" + String(rlCoolingFan02) + "/" + String(coolingFan01) + "/" + String(coolingFan02);
 
    // prepare filamentize notify three string
    String percentNotifyValue = String(spoolMotor) + "/" + String(extruder) + "/" + String(windingStepper) + "/" + String(vibrator) + "/" + selectedColor;
 
    // notify all value to the app
    filamentizeStatusNotifyCharacteristic.writeValue(statusNotifyValue);
 
    filamentizeNotifyCharacteristic.writeValue(tempNotifyValue);
 
    filamentizeNotifyTwoCharacteristic.writeValue(coolingFansNotifyValue);
 
    filamentizeNotifyThreeCharacteristic.writeValue(percentNotifyValue);
 
    sentData(temp01, temp02, coolingFan01, coolingFan02, extruder, vibrator);
    sentDataSpool(windingStepper, resetspoolMotor);
    Serial.println("<---------------------->");
    Serial.println("Device Status : " + deviceStatus);
    Serial.println("Device Mode : " + deviceMode);
    Serial.println("temp01 : " + String(temp01));
    Serial.println("temp02 : " + String(temp02));
    Serial.println("rlTemp01 : " + String(rlTemp01));
    Serial.println("rlTemp02 : " + String(rlTemp02));
    Serial.println("cooling fan01 : " + String(coolingFan01));
    Serial.println("cooling fan02 : " + String(coolingFan02));
    Serial.println("rl cooling fan01 : " + String(rlCoolingFan01));
    Serial.println("rl cooling fan02 : " + String(rlCoolingFan02));
    Serial.println("extruder : " + String(extruder));
    Serial.println("winding stepper : " + String(windingStepper));
    Serial.println("spool motor : " + String(spoolMotor));
    Serial.println("RESET spool : " + String(spoolReset));
    Serial.println("vibrator : " + String(vibrator));
    Serial.println("color : " + (Bit));
  }
 
  if (BLE.central()) {
    BLE.advertise();
  }
 
  // change variables value to the value that app sent
  if (filamentizeStatusCharacteristic.written()) {
    if (filamentizeStatusCharacteristic.value() == "Off") {
      deviceStatus = "Off";
      temp01 = 0;
      temp02 = 0;
      rlTemp01 = 0;
      rlTemp02 = 0;
      coolingFan01 = 0;
      coolingFan02 = 0;
      rlCoolingFan01 = 0;
      rlCoolingFan02 = 0;
      extruder = 0;
      windingStepper = 0;
      spoolMotor = 0;
      vibrator = 0;
      selectedColor = 1;
    } else if (filamentizeStatusCharacteristic.value() == "On") {
      deviceStatus = "On";
      temp01 = 0;
      temp02 = 0;
      rlTemp01 = 0;
      rlTemp02 = 0;
      coolingFan01 = 60;
      coolingFan02 = 60;
      rlCoolingFan01 = 0;
      rlCoolingFan02 = 0;
      extruder = 0;
      windingStepper = 0;
      spoolMotor = 0;
      vibrator = 0;
      selectedColor = 1;
    }
  }
 
 
  // change variables value to the value that app sent
  if (coolingFanOneWriteCharacteristic.written()) {
    coolingFan01 = coolingFanOneWriteCharacteristic.value().toInt();
  }
  if (coolingFanTwoWriteCharacteristic.written()) {
    coolingFan02 = coolingFanTwoWriteCharacteristic.value().toInt();
  }
  if (tempOneWriteCharacteristic.written()) {
    temp01 = tempOneWriteCharacteristic.value().toInt();
  }
  if (tempTwoWriteCharacteristic.written()) {
    temp02 = tempTwoWriteCharacteristic.value().toInt();
  }
  if (spoolWriteCharacteristic.written()) {
    spoolMotor = spoolWriteCharacteristic.value().toInt();
  }
  if (resetspoolWriteCharacteristic.written()) {
    resetspoolMotor = resetspoolWriteCharacteristic.value().toInt();
  }
  if (extruderWriteCharacteristic.written()) {
    extruder = extruderWriteCharacteristic.value().toInt();
  }
  if (stepperWriteCharacteristic.written()) {
    windingStepper = stepperWriteCharacteristic.value().toInt();
  }
  if (vibratorWriteCharacteristic.written()) {
    vibrator = vibratorWriteCharacteristic.value().toInt();
  }
  if (colorWriteCharacteristic.written()) {
    selectedColor = colorWriteCharacteristic.value().toInt();
  }
 
  Bit = selectedColor.toInt();
  if (selectedColor != 0) {
    printBinary(Bit);
    delay(10);
  }
 
  getdatFromExtrude();
  rlTemp01 = rlTempMID_Value();
  rlTemp02 = rlTempEND_Value();
  rlCoolingFan01 = rpm_Fan1();
  rlCoolingFan02 = rpm_Fan2();
 
 
  getdat2FromSpool();
  spoolMotor = SpoolPercent_Value();
}