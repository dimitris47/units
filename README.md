# Units

WINDOWS SYSTEMS:

Run the UnitsInstaller.exe file.


LINUX SYSTEMS:

a. Compile from source:

1. Donwload and extract archive from releases
2. Open extracted directory with Terminal and run:
   <code>qmake Units.CPP CONFIG+=release && make && sudo make install && make clean</code>
   
You might need to install <code>libqt5gui5</code>, <code>g++</code> and <code>make</code> packages to your Linux system before compiling.


b. Debian systems:

1. Download units-1.4.deb file from releases.
2. Open downloads folder with Terminal and run:
<code>sudo dpkg -i units-1.4.deb</code>

You might need to install the <code>libqt5gui5</code> package before running the .deb file.

