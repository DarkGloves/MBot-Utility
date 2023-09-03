<h1 align="center">MBot Utility🤖</h1>
<div align="center">
<i>Something like a "toolbox" for the MBot, trying to use some of its features.</i>
</div>

## ⭐ Requierements
* An MBot ***`V1.1`***
* MBot's IR controller
* Modules
    * Ultrasonic sensor
    * Line Follower

## 🚀 Installation


1. Download and install Arduino IDE from the official page: <br>https://www.arduino.cc/en/software<br>
The installation process may vary depending on your OS, so you can follow these guides:  <br>
> > [Windows installation](https://docs.arduino.cc/software/ide-v1/tutorials/Windows)  
> > [macOS installation](https://docs.arduino.cc/software/ide-v1/tutorials/macOS)  
> > [Linux installation](https://docs.arduino.cc/software/ide-v1/tutorials/Linux) 


2. Download the `MBot-Utility.ino` file from the [lastest release](https://github.com/DarkGloves/MBot-Utility/releases/latest/download/main.ino) of this repo.

3. Download the MakeBlock Libraries from [MakeBlock Libs Github Repo](https://github.com/Makeblock-official/Makeblock-Libraries)<br>*[Direct download](https://codeload.github.com/Makeblock-official/Makeblock-Libraries/zip/master)*

4. Open the Arduino IDE and click on `File > Open` and select the `.ino` file you downloaded at step 2.

5. Now click `Sketch > Include Library > Add .ZIP library` and select the MakeBlock Libraries you downloaded previously.

6. Turn on your MBot and connect it to your device via the *serial cable* it provided.<br>On Arduino IDE click `Tools > Board > Arduino AVR Boards` and select **Arduino UNO** from the list.<br>Then go  `Tools > Port` and select the serial port that corresponds to your MBot

7. Finally upload the file to your MBot clicking the **Upload** button. 

## 🎮 Usage

```
This script adds different functionalities to the MBot, that can be easily switched with the IR Controller
```
### 🎨 Colors
During the experience, the MBot's led will turn to different colors depending on the mode you are in:

<div align=center>

| Mode | Color |
|:-:|:-:|
|Main Menu|![#00ff7f](https://placehold.co/15x15/00ff7f/00ff7f.png)
|Mode A|![#ff0000](https://placehold.co/15x15/ff0000/ff0000.png) 
|Mode B|![#ffff00](https://placehold.co/15x15/ffff00/ffff00.png) 
|Mode C|![#00ff00](https://placehold.co/15x15/00ff00/00ff00.png) 
|Mode D|![#00ffff](https://placehold.co/15x15/00ffff/00ffff.png) 
|Mode E|![#0000ff](https://placehold.co/15x15/0000ff/0000ff.png) 

</div>

### 🏡 Main Menu
When the MBot starts up, you will be taken to the Main Menu.  
From here, you can enter any mode pressing its respective button in the IR controller:

<div align='center'>

| Mode | Button |
|:----:|:-----:|
|Mode A|![A](https://placehold.co/25x25/000/0FF?text=A)|
|Mode B|![B](https://placehold.co/25x25/000/0FF?text=B)|
|Mode C|![C](https://placehold.co/25x25/000/0FF?text=C)|
|Mode D|![D](https://placehold.co/25x25/000/0FF?text=D)|
|Mode E|![E](https://placehold.co/25x25/000/0FF?text=E)|
  
</div>

### ![A](https://placehold.co/15x15/000/0FF?text=A) Mode A

In this mode, you will be able to move your MBot with your IR controller, as if it was RC car.

For this you can press these buttons:

<div align=center>

| Button | Action |
|:----:|:-----:|
|A|Return to the main menu|
|▲|Go forward|
|▼|Go backwards|
|◀|Turn left|
|▶|Turn right|
|1 ~ 9| Modify the speed|

</div>

### ![B](https://placehold.co/15x15/000/0FF?text=B) Mode B

> [!IMPORTANT]  
> Make sure to connect the Ultrasonic sensor to port 2.

> [!WARNING]  
> It's potentially dangerous to place your MBot in an elevated position on this mode, **It could fall over!**

In this mode, your MBot will change its path each time it detects an object in front of it.<br><br>
Actions:

<div align=center>

| Button | Action |
|:----:|:-----:|
|A|Return to the main menu|
|1 ~ 9| Modify the speed|

</div>

### ![C](https://placehold.co/15x15/000/0FF?text=C) Mode C

> [!IMPORTANT]  
> Make sure to connect the line follower sensor to port 3.

In this mode, your MBot will act as a *line follower*.  
If you want toplay with it, you will need tracks. If you don't own any line-follower tracks, you can take a look at these [free printable tracks.](https://github.com/DarkGloves/MBot-Utility/tree/main/resources/printable_tracks)   

Once you have a track, you just need to place the line follower module above the black path and it will automatically start following it.  

Actions:

<div align=center>

| Button | Action |
|:----:|:-----:|
|A|Return to the main menu|
|1 ~ 9| Modify the speed|

</div>

### ![D](https://placehold.co/15x15/000/0FF?text=D) Mode D

In this mode, your MBot will be restricted to an area, and each time it touches a corner, it will change its path randomly.  

For specifying the area, you can use black tape: mark the boundaries with a line. Then, place the MBot in the center, and each time it touches the tape, it will change its path  

Actions:

<div align=center>

| Button | Action |
|:----:|:-----:|
|A|Return to the main menu|
|1 ~ 9| Modify the speed|

</div>

### ![E](https://placehold.co/15x15/000/0FF?text=E) Mode E

In this mode, you are able to listen to music. There are actually 2 avaiable tracks, hope you like them!

<div align=center>

| Button | Action / Song|
|:----:|:-----:|
|A|Return to the main menu|
|⚙|Pause the music
|1| Play *Solfeggietto - C.P.E Bach*|
|2| Play *Rondo Alla Turca - Amadeus Mozart*|

</div>
<br>

## 📦 Restoring the default program
For restoring MBot's default program, you can just flash the `mbot_factory_firmware.ino` file from the [lastest release](https://github.com/DarkGloves/MBot-Utility/releases/latest/download/mbot_factory_firmware.ino), extracted from the MBlock 3 software, al credits to [Makeblock-official](https://github.com/Makeblock-official).