

const int ledRPin = 2;//GPIO No.
const int ledYPin = 15;   //GPIO No.         
const int ledGPin = 13;//GPIO No.
void pin_setup()
{
  
  pinMode(ledRPin,OUTPUT);         //定义引脚为输出模式
  pinMode(ledGPin,OUTPUT);
  pinMode(ledYPin,OUTPUT);
}
void OpenLight(int lightPin)
{
   digitalWrite(lightPin,HIGH);
   delay(500); 

}
void CloseLight(int lightPin)
{
   digitalWrite(lightPin,LOW);
   delay(500); 

}

boolean handle_command(char* cmd)
{
	if(cmd[0]!='\0'){ 
    Serial.print(cmd);
    String msgString(cmd);
    if (msgString == "red") OpenLight(ledRPin); // red
    if (msgString == "cred") CloseLight(ledRPin); //   
    if (msgString == "green") OpenLight(ledGPin); //green
    if (msgString == "cgreen") CloseLight(ledGPin); //   
    if (msgString == "yellow") OpenLight(ledYPin); // yellow 
    if (msgString == "cyellow") CloseLight(ledYPin); //  
    return true;
  }
  return false;
}



