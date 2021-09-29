import processing.serial.*;
PImage img;
Serial myPort;  // Create object from Serial class

String val;     // Data received from the serial port
int x = 450;
int y = 500;

void setup()
{
  size(1000, 1000);
  img = loadImage("plane.png");
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
}



void draw()
{
  background(0);
  if ( myPort.available() > 0) 
  {  // If data is available,
    val = myPort.readStringUntil('\n');
    
      if (val != null) {
       if (int(val.trim()) == 1)
       {
         x = x+100;
         image(img, x, y, 100, 100);
      }
      else if(int(val.trim()) == 2){
        x = x-100;
        image(img, x, y, 100, 100);
      }
      else if(int(val.trim()) == 3){
        y = y+100;
        image(img, x, y, 100, 100);
      }
      else if(int(val.trim()) == 4){
        y = y-100;
        image(img, x, y, 100, 100);
      }
    }
  }

  print(val);
  image(img, x, y, 100, 100);
 
  }
