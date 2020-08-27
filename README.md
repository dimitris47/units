# Units

WINDOWS SYSTEMS:

Run the UnitsInstaller.exe file.


LINUX SYSTEMS:

a. Compile from source:

1. Extract archive
2. Open extracted directory with Terminal
3. Run the following:
   <code>qmake Units.CPP CONFIG+=release && make && sudo make install && make clean</code>
   
You might need to install <code>libqt5gui5</code>, <code>g++</code> and <code>make</code> packages to your Linux system before compiling.


b. Debian systems:

Navigate to downloads directory and run:
<code>sudo dpkg -i units-1.2.deb</code>.
You might need to install the libqt5gui5 package before running the .deb file.

