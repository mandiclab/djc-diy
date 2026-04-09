# *DJC-DIY - The World's First DIY DJ Controller*
DJC-DIY is an open-source DJ controller that you can make at home without special tools, skill or knowledge.  
It works with [Mixxx](https://mixxx.org/) (open-source DJ software).  

![Hot Pic](https://github.com/mandiclab/djc-diy/blob/main/assets/djc-diy.webp?raw=true)


## ▶️ Video Preview & Tutorial
👀 **[Preview](https://youtu.be/gbPC8Bg0U9I?si=byUlCWdjjWGdwAEo)**  
🎓 **[Tutorial](https://youtu.be/pAYhAsbDP9I?si=Bvd1b9u0WtWM_3as)**

## 👥 Community
☕ Support by donating on **[Ko-fi](https://ko-fi.com/mandiclab)**.  
🚀 Join the community on **[Discord](https://discord.gg/aApBQxZUcu)**.  
📱 Subscribe on  **[YouTube](https://youtube.com/@mandiclab)** and follow on **[Instagram](https://instagram.com/mandiclab)**.

## 📁 Project Files

🧊 **3D Models** - *.stl (mesh files for 3D printing), .FCStd (FreeCad source files)*  
⚙️ **Firmware** - *here's the firmware*  
🎛️ **Mixxx Mapping Files** - *and here are the mapping files*

## ⬇️ Download

Download latest stable release from **[releases](https://github.com/mandiclab/djc-diy/releases)**. 

>[!WARNING]
>*If you download the whole repo, there's a chance that you'll download files in the middle of the update process and get incomplete version.*

## 🔩 Parts List

### 3D Printed Parts
| **🔢 Quantity** | **🧊 Part** | **📄 File Name** |
|:---:|:---|:---|
| x1 | Case | case.stl |
| x1 | Front Panel | front-panel.stl |
| x1 | Arduino Spring | arduino-spring.stl |
| x2 | Jog Wheel | jog-wheel.stl |
| x2 | Play/Pause | play-pause.stl |
| x2 | Cue | cue.stl |
| x4 | Performance Pad | performance-pad.stl |
| x1 | Crossfader | crossfader.stl |
| x2 | Tempo Fader | tempo-fader.stl |
| x4 | Knob | knob.stl |
| x4 | Feet | feet.stl |

### 📦 Order 3D Printed Parts From PCBWay 
Thanks to our sponsor **[PCBWay](https://www.pcbway.com/)**, you can now order all 3D printed parts and have them delivered to your door.  
Not having access to a 3D printer is no longer a problem.  

🛒 **[ORDER ALL 3D PRINTED PARTS](https://www.pcbway.com/rapid-prototyping/manufacture/?type=3&reffercode=Project&projectattid=78823)**  
🔎 **[SEE THE WHOLE PROJECT](https://www.pcbway.com/project/shareproject/DIY_DJ_Controller_DJC_DIY_adac65c3.html)**  

*By ordering through PCBWay, you’re also supporting the project and helping future development.*  

### Electronic Components  
| **🔢 Quantity** | **🧩 Component** | **📄 Description** |
|:---:|:---|:---|
| x1 | 🧠 Microcontroller | Arduino Pro Micro - ATmega32U4 - USB Type C |
| x8 | 🔘 Buttons | B3F-4055 - 12x12x7.3mm |
| x4 | 🎛️ Rotary Potentiometers | R0902N - B103 - 10kΩ - 23mm shaft lenght - D shaft |
| x3 | 🎚️ Slide Potentiometers | 60mm - B103 - 10kΩ - 15mm handle lenght |
| x2 | 🔄 Rotary Encoders | EC11 - 15mm shaft lenght - D shaft - without push button |
| x4 | ➖ Resistor | 1/4W - 10kΩ |
|  | 🔌 Wires | 24 AWG - Red, Black, Blue, Green, Yellow|

## 💻 Required Software
**Download and install required software**  

**Arduino IDE** - *an open-source development environment for programming Arduino boards* - **[DOWNLOAD](https://www.arduino.cc/en/software/)**  
**Mixxx** - *an open source DJ software* - **[DOWNLOAD](https://mixxx.org/download/)** 


## 🛠️ Assembly Guide

### 1. Acquire electronic components  
Acquire all electronic components from the electronic components list.  
I personally bought everything from Aliexpress and had no problems.

### 2. 3D print parts  
3D print all parts from the 3D printed parts list.  
I used max speed, 15% infill, .2mm layer height. Use support where needed.  
If something can't be pulled onto a part, try printing it at 105% scale.  

### 3. Wire electronics in the case  
Here you can see an illustrated schematic.  
Solder everything as shown.  


This is the layout of the electronic components.  
![Hot Pic](https://github.com/mandiclab/djc-diy/blob/main/assets/illustrated%20schematic/00.webp)  


First solder left rotary encoder.  
At the beginning, solder the pins from the bottom side of the Arduino.  
Use this opportunity to leave more space on the top side for later, because once several electronic components are soldered in place, the Arduino will no longer be movable, and soldering from the bottom side of the pins will no longer be possible.  
![Hot Pic](https://github.com/mandiclab/djc-diy/blob/main/assets/illustrated%20schematic/01.webp)  


Then solder right rotary encoder.  
Also solder the pins from the bottom side.  
![Hot Pic](https://github.com/mandiclab/djc-diy/blob/main/assets/illustrated%20schematic/02.webp)  


Next are buttons for the left deck.  
![Hot Pic](https://github.com/mandiclab/djc-diy/blob/main/assets/illustrated%20schematic/03.webp)  


Then buttons for the right deck.  
![Hot Pic](https://github.com/mandiclab/djc-diy/blob/main/assets/illustrated%20schematic/04.webp)  


And the last are potentiometers.
![Hot Pic](https://github.com/mandiclab/djc-diy/blob/main/assets/illustrated%20schematic/05.webp)  


It should look like this when everything is soldered.
![Hot Pic](https://github.com/mandiclab/djc-diy/blob/main/assets/illustrated%20schematic/06.webp)  



### 4. Install firmware  
Open firmwar.ino with Arduino IDE.  
Select your board (some Pro Micro clones can only be used stably as Arduino Leonardo boards).  
Install MIDIUSB library from Gary Grewal.  
Then upload the code.  

### 5. Install mapping files  
Copy ”DJC-DIY.xml” and ”DJC-DIY-scripts.js” to  
”C:\Users\username\AppData\Local\Mixxx\controllers”.  
Select mapping files by going to the preferences. (Options > Preferences or Ctrl + P)  
Go to the controllers tab and choose something like Arduino/ProMicro/Leonardo.  
Then go to the load mapping and select DJC-DIY.  

### 6. Test the device 
Test your device before assembling rest 3D printed parts.  

### 7. Assemble the rest 3D printed parts  
Assemble the rest 3D printed parts.  
Feel free to use glue where needed.  

## ❓ FAQ

**Q:** Is it for sale?  
**A:** For now, we're not selling the device or DIY kit.

**Q:** Does it work with other DJ software such as Virtual DJ, Rekordbox or Traktor?  
**A:** Currently out of the box it only works with Mixxx, but the controller sends standard MIDI messages, so it can be manually mapped to other software.

## ⚖️ Licenses
**💻 Software** *(.ino, .xml, .js)*  
  Licensed under the [GPL-3.0](LICENSE-SOFTWARE.txt)

**🔩 Hardware** *(.FCStd, .stl)*  
  Licensed under the [CERN-OHL-S-2.0](LICENSE-HARDWARE.txt)
