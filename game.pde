import processing.serial.*;
PImage img;
PImage img2;
PImage laser;
Serial myPort;  // Create object from Serial class

String val;     // Data received from the serial port
int x = 450;
int y = 500;
int x1 = width;
int y1 = 0;
boolean bulletShot;
float bullet_x;
float bullet_y;
float accel = map(mouseX, 0, width, 1, 8);

void setup()
{
  size(1000, 1000);
  img = loadImage("plane.png");
  img2 = loadImage("alien123.png");
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
      else if(int(val.trim()) == 5){
            bullet_x = x;
            bullet_y = y;
            bulletShot = true;
            accel = map(mouseY, 0, width, 1, 8);        
      }
    }
  }
  if (bulletShot) {
     fill(312, 53, 99);
     ellipse(bullet_x, bullet_y + 10, 20, 20); 
     bullet_y -= accel;
     if (bullet_x > width + 5) bulletShot = false;
   }
   
  x1 -= 1;
  if (x1 < 0) x1 = width;
  image(img2, x1, 250, 100, 100);



  
  print(val);
  image(img, x, y, 100, 100);
 
  }
