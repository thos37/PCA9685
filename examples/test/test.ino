#include <Wire.h>
#include <PCA9685.h>

PCA9685 ledDrive(0x41);

void setup()
{
  ledDrive.begin();
  Serial.begin(9600);

  ledDrive.setPWMFrequency(200);
  Serial.print("PWM Frequency: ");
  Serial.println(ledDrive.getPWMFrequency());

  //turn everything off  
  ledDrive.PWMSame(0, 15, 0);  
}

void loop()
{
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < 6) {
    j = 0;
    while (j <= 255) {
      ledDrive.PWM(i, j);
      j++;
    }
    i++;
  }

  while (i >= 0) {
    j = 255;
    while (j >= 0) {
      ledDrive.PWM(i, j);
      j--;
    }
    i--;
  }
  
  Serial.println(ledDrive.getPWM(0));

  delay(500);

  while (k <= 255) {
    ledDrive.PWM(0, k);
    k++;
  }
  
  Serial.println(ledDrive.getPWM(0));

  delay(1000);
  
  while (k >= 0) {
    ledDrive.PWM(0, k);
    k--;
  }
  
  Serial.println(ledDrive.getPWM(0));

  delay(500);
}
