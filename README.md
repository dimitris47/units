# Units

WINDOWS SYSTEMS:

Run the UnitsInstaller.exe file.


LINUX SYSTEMS:

a. Compile from source:

1. Extract archive
2. Open extracted directory with Terminal
3. Run the following:
   $ mkdir ../build && cd ../build && qmake directory_of_extracted_archive/units-1.1/Units.CPP CONFIG+=release && make && sudo make install && rm -r ../build
   
You might need to install base Qt packages to your Linux system before compiling.


b. Debian systems:

Navigate to downloads directory and run:
$ sudo dpkg -i units-1.1.deb.
You might need to install the libqt5gui5 package before running the .deb file.
