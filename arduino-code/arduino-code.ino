//#include <ros.h>
//#include <DynamixelWorkbench.h>
//
//#define DEVICE_NAME "1"               //Dynamixel on Serial1 (OpenCM9.04)
//#define DEVICE_BAUDRATE 1000000       //Baudrate for XL320 communication
//
//#define NUMBER_OF_SERVOS 16           //Number of Servos
//#define NUMBER_OF_CONTROL_ITEMS 31    //Number of Control Items in XL320 register
//#define NUMBER_OF_USED_CONTROL_ITEMS 9
//float xl320[NUMBER_OF_SERVOS][NUMBER_OF_USED_CONTROL_ITEMS];  //Array Containing info of all XL320's
//
//DynamixelWorkbench dxl_wb;
//bool result = false;                  //Var for showing result of actions
//const char *logs = NULL;              //Var for showing logs
//uint8_t get_id[16];
//uint8_t scan_cnt = 0;
//float presentPosition=0.0;
//
////----Functions & Methods----
//void SetAngleAndVelocity(int id,int angle,int velocity){
//  float angle_rad = AngleToRadian(angle);
//  if (velocity != 0)
//    dxl_wb.goalVelocity(id,velocity,&logs);
//
//  dxl_wb.goalPosition(id,angle_rad,&logs);
//}
//
//float AngleToRadian(float angle){
//  float rad =  (angle * 71.0) / 4068.0;
//  return rad;
//}
//
//float RadianToAngle(float radian){
//  float angle =  (radian * 4068.0) / 71.0;
//  return angle;
//}
//
//void Read_Control_Tables() {
////----EXECUTE FOLLOWING CODE ON ALL SERVOs-----
//
//  for (int i = 0; i < NUMBER_OF_SERVOS; i++) { //NUMBER_OF_SERVOS
//    const ControlItem *control_item =  dxl_wb.getControlTable(i+1);     //getting Control Table of XL320 with ID i+1
//
//    uint16_t last_register_addr = control_item[NUMBER_OF_CONTROL_ITEMS-1].address;
//    uint16_t last_register_addr_length = control_item[NUMBER_OF_CONTROL_ITEMS-1].data_length;
//    uint32_t getAllRegisteredData[last_register_addr+last_register_addr_length];
//
//    if (control_item != NULL){
//      result = dxl_wb.readRegister(i+1, (uint16_t)0, last_register_addr+last_register_addr_length, getAllRegisteredData, &logs);
//      if (result == false){
//        Serial.print(i+1);Serial.print("=ID |----------------------------------| ");Serial.println(logs);
//        return;
//      }
//      else
//      {
//        //----GET DATA FROM SPECIFIC CONTROL ITEMS----
//        xl320[i][0] = getAllRegisteredData[control_item[2].address];   //ITEM 2
//        xl320[i][1] = getAllRegisteredData[control_item[14].address];  //ITEM 14
//
//        result = dxl_wb.getRadian(i+1,&presentPosition,&logs);         //ITEM 22
//        xl320[i][2] = RadianToAngle(presentPosition);
//
//        xl320[i][3] = getAllRegisteredData[control_item[23].address];  //ITEM 23
//        xl320[i][4] = getAllRegisteredData[control_item[24].address];  //ITEM 24
//        xl320[i][5] = getAllRegisteredData[control_item[25].address];  //ITEM 25
//        xl320[i][6] = getAllRegisteredData[control_item[26].address];  //ITEM 26
//        xl320[i][7] = getAllRegisteredData[control_item[15].address];  //ITEM 15
//        xl320[i][8] = getAllRegisteredData[control_item[29].address];  //ITEM 29
//        delayMicroseconds(100); // make sure it doesn't read to fast from servo register and give txrx error
//      }
//    }
//  }
//}

int counter=0;

void setup() {
  //Serial.begin(9600);
  //Serial1.begin(1000000);

//  //----START CONNECTION TO SERVO's----
//  delay(2500);                                          //Waiting 2.5 seconds for servos to boot
//
//  result = dxl_wb.init(DEVICE_NAME, DEVICE_BAUDRATE);
//  if (result == false){
//    Serial.println(logs);
//    Serial.println("Failed to init");
//  }
//
//  //-----------------------------------
//  //----SCAN CONNECTED SERVO's----
//  result = dxl_wb.scan(get_id, &scan_cnt, 253);
//  if (result == false){
//    Serial.println(logs);
//    Serial.println("Failed to scan");
//  }
//  //-----------------------------------
}

void loop() {
//  Serial.println("180 degrees");
//  dxl_wb.goalPosition(2,180,&logs);
//  delay(1500);
//  Serial.println("160 degrees");
//  dxl_wb.goalPosition(2,160,&logs);
//  delay(1500);
//
  //Serial.print("Test"); Serial.println(counter);
  //counter++;
  //Serial1.print(counter);
  //delay(1000);
}
