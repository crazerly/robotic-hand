# Robotic Hand
A basic robotic hand controlled by a glove using Velostat pressure sensors. Most materials are common or can be substituted, apart from the Velostat and copper tape, making the total price ~$15.

## Materials
 - 5 micro servos
 - glove
 - ~1m of string
 - Velostat
 - copper tape
 - 3D printed parts for hand
 - Arduino or other microcontroller
 - 50kΩ resistors
 - sturdy base for arm (e.g. cardboard)

## Tools
 - 3D printer
 - soldering iron

## Overview
The bend of each finger is quantified by a pressure sensor, which converts the measurement into an angle for the corresponding servo. The servo then turns to this angle, pulling the attached string which raises or lowers a finger on the robotic hand.
This is shown in the diagram below:  
<div align="center">
  <img src="https://github.com/crazerly/robotic-hand/blob/main/imgs/diagram.png" width="600"/>
</div>
<br />

## Making the robotic hand
<div align="center">
  <img src="https://github.com/crazerly/robotic-hand/blob/main/imgs/robotic_hand.jpg" width="500">
</div>
<br />

The file for the 3d printed hand is from [here](https://www.viralsciencecreativity.com/post/arduino-flex-sensor-controlled-robot-hand), but I have not used any other part of their project.
My initial design was to attach the string to the end of each finger, but for this model the string is threaded through each joint.  
I tied the string to a metal ring to prevent it from being pulled out, and threaded rope through the two other holes in the fingers to fix the joints in place.
I then glued the four servos to a cardboard base and attached the string tightly so that when the servo turned 180° the finger fully curled.  
I could only find five servos and one was broken, so instead of getting another I've left the thumb out.

## Making the glove
<div align="center">
  <img src="https://github.com/crazerly/robotic-hand/blob/main/imgs/glove_hand.jpg" width="400">
</div>
<br />

Thicker gloves are recommended as rubber gloves crease and expand more when you put them on, which can affect readings from the pressure sensors. However, I only had rubber gloves which were accurate enough once with precise calibration.  
The pressure sensors were made out of Velostat and copper tape, which is a cheap alternative to pressure or flex sensor components.
To make the sensor, I stuck a strip of copper tape to each side of the Velostat and soldered wires on each side for 5V and GND. Here is the schematic for the sensor:
<div align="center">
  <img src="https://github.com/crazerly/robotic-hand/blob/main/imgs/schematic.png" width="400">
</div>
<br />

When you push down on or bend the Velostat, its carbon particles are pushed closer together, creating more pathways for the electrical current. This decreases the resistance, which can be measured via a voltage divider.  

## The code
The code simply maps the values from the pressure sensor to the servo's angle, between 0-180°, but could be improved with per-finger range calibration and software fixes for the sensor's noise.  
Because the circuit measures voltage _drop_, angle values are inverted before they are sent to the servo.

## Demo
The first clip shows the first test, which had a lot of noise (causing servos to randomly turn) and the 3rd servo wasn't connected properly.  
In the second clip I fixed the wiring and reduced the range of the sensors, although the servos sometimes pause when I unbend my fingers.  
<a href="https://www.youtube.com/watch?v=jolHgBBG1go" align="center">
  <img src="https://github.com/crazerly/robotic-hand/blob/main/imgs/Robotic%20Hand.png" width="600">
</a>
