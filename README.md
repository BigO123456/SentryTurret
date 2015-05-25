# SentryTurret

This project licensed under GNU GENERAL PUBLIC LICENSE
https://www.gnu.org/licenses/gpl.txt

Attach the Raspberry pi servo hat to the Raspberry pi, x-axis servo on 0 and y-axis servo on 3 

connect the relay board to gnd and vin and gpio 24

![Raspberry pi and Relay](http://i.imgur.com/LZkYvNJ.jpg "Connected") 
![Side View](http://i.imgur.com/b4JQwYZ.jpg "side view")

A sentry turret style robot which will detect motion, then track and fire at the object. The robot's "turret" is rotated by two servos (X/pan axis and Y/tilt axis). The "eye"(webcam) and "gun" of the robot should be mounted on the turret. 

![Raspberry pi Display](http://i.imgur.com/XBFRPyV.jpg "Display") 

When activated, the robot will initialize an average image and wait to detect motion above a threshold size. It will target the mean HSV of a moving object and begin blob detection to center the camera's view (using turret servos) on the object. When the object is centered, it will fire by using a relay board.

See main.py for further comments.

To run with display: $python main.py 1

The program starts a thread for the turret which is continually updated with target coordinates by the OpenCV frame processing. A separate thread handles terminal keyboard input:

- q = quit
- ' ' = reset
- 1 = start motion detect
- 2 = sample center for target
- f/v = +/- threshhold area
- a,s,d/z,x,c = +/- H,S,V
- p = toggle armed
- l/m = +/- target sensitivity
- f = fire

---

To use manual control run go to the driver folder and run sudo python manual.py
before you run it make sure to install motion and configure it using motion.conf provided

sudo apt-get install motion

sudo nano /etc/default/motion   set start_motion_daemon=yes

then copy the motion.conf file to /etc/motion/motion.conf

motion will run on port 8081

Manual Control for Sentry Turret

' ' = reset

w = move up

a = move left

s = move down

d = move right

f = fire

x = trigger buzzers

b = fire left

n = fire right

p = Spray

Add a joystick or xbox contoller for added enjoyment use JoyToKey http://joytokey.net/en/ 
![image](https://scontent-lga.xx.fbcdn.net/hphotos-xfp1/v/t1.0-9/10551111_10102040449359939_1193606793478368655_n.jpg?oh=4afb9d2e38645f1eda55b1fe9584a000&oe=558AADE1)

The working example was built on RaspberryPi2 with Raspian and OpenCV(python) 2.4, using GPIO pins connected to a servo hat from adafruit. https://learn.adafruit.com/adafruit-16-channel-pwm-servo-hat-for-raspberry-pi/overview . The 5v relay board is the fire control system
