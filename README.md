# *DJC-DIY - The World's First DIY DJ Controller*
DJC-DIY is an open-source DJ controller that you can make at home without special tools, skill or knowledge.  
It works with [Mixxx](https://mixxx.org/) (open-source DJ software).  

![Hot Pic](https://www.mandiclab.com/assets/project-photos/djc-diy/003.webp)


## ▶️ Video Preview & Tutorial
👀 **[Preview](https://youtu.be/gbPC8Bg0U9I?si=byUlCWdjjWGdwAEo)**  
🎓 **[Tutorial](https://youtu.be/pAYhAsbDP9I?si=Bvd1b9u0WtWM_3as)**

## 👥 Community
☕ Support by donating on **[Ko-fi](https://ko-fi.com/mandiclab)**.  
🚀 Join the community on **[Discord](https://discord.gg/aApBQxZUcu)**.  
📱 Subscribe on  **[YouTube](https://youtube.com/@mandiclab)** and follow on **[Instagram](https://instagram.com/mandiclab)**.

## 📁 Project Files

🧊 **3D Models** - *.stl (mesh files for 3D printing), .FCStd (FreeCad source files)*  
⏪ **Backward Compatible** - *if you made DJC-DIY before, here you can find parts to upgrade it to a newer version*  
⚙️ **Firmware** - *here's the firmware*  
🎛️ **Mixxx Mapping Files** - *and here are the mapping files*

## ⬇️ Download

Download latest stable release from **[releases](https://github.com/mandiclab/djc-diy/releases)**. 

>[!WARNING]
>*If you download the whole repo, there's a chance that you'll download files in the middle of the update process and get incomplete version.*

## 🔩 Parts List

### 3D Printed Parts

**If you don’t have access to a 3D printer, you can order 3D printed parts from PCBWay using the link below.**  
*Using this link directly supports the development of MandićLab.* 

**[PCBWay](https://www.pcbway.com/project/shareproject/DIY_DJ_Controller_DJC_DIY_adac65c3.html)**

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

### Electronic Components  
| **🔢 Quantity** | **🧩 Component** | **📄 Description** |
|:---:|:---|:---|
| x1 | 🧠 Microcontroller | Arduino Pro Micro - ATmega32U4 |
| x8 | 🔘 Buttons | B3F-4055 - 12x12x7.3mm |
| x4 | 🎛️ Rotary Potentiometers | R0902N - B103 - 10kΩ - 23mm shaft lenght - D shaft |
| x3 | 🎚️ Slider Potentiometers | 60mm - B103 - 10kΩ - 15mm handle lenght |
| x2 | 🔄 Rotary Encoders | Encoders for knobs & jog wheels |
| x? | ➖ Resistor | 1/4W - 10kΩ |
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
Here you can see an illustrated schematic. (When I finish illustration for new design.)  
Solder everything as shown.


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
