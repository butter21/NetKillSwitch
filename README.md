# NetKillSwitch
Network Kill Switch. Press button to turn on or off(all or most of the network interfaces on your pc)
Default interface: enp4s0
For now only available for use with one interface at a time. 
**_Needs sudo!!_**
Only works on: **_Linux and MacOS_**

Install and Compile:

Download file.

Download gtk3:

For apt systems:
      **sudo apt-get install libgtk-3-dev**
      
Fedora:
      **sudo dnf install gtk3-devel**
      
Arch(or arch based):
      **sudo pacman -S gtk3**
      
macOS:
      **brew install gtk+3**
      

compile with: **_gcc -o nks nks.c `pkg-config --cflags --libs gtk+-3.0`_**

run: **_sudo ./nks_**
