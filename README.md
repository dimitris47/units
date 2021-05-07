# Units

- WINDOWS SYSTEMS:

Run the latest <code>.exe</code> file.
If after the installation the program doesn't start, install <code>vc_redist.exe</code> from the installation folder.


- UNIX SYSTEMS:

a. from source:

1. Donwload the code or clone the repo
2. Open extracted directory in terminal and run:
   <code>qmake Units.pro CONFIG+=release && make && sudo make install && make clean</code>
   
You might need to install <code>libqt5gui5</code>, <code>g++</code> and <code>make</code> packages to your system before compiling.


b. Debian & Debian-based systems:

Download the latest <code>.deb</code> file from releases and run it with your package manager.

c. RPM-based systems:

Download the latest <code>.rpm</code> file and run it with your package manager.

You might need to have <code>libqt5gui5</code> installed before running the binary.
