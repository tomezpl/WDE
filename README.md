# WDE
## Web-based Desktop Environment

### About WDE
WDE is a desktop environment for GNU/Linux. Its graphical user interface uses HTML and CSS, as well as JavaScript to provide interactivity. The back-end is written in C++ and is based on GTK+2.0 and WebKitGTK+. It is currently in the works.

### Building
#### Dependencies
WDE requires GTK+3.0 and WebKit2GTK+3.0.
If you're on a Debian system, you'll probably need these packages:
* libgtk-3-dev
* libwebkit2gtk-3.0-dev

To install the dependencies using apt in Debian-based distros, run this command:
`apt-get install libgtk-3-dev libwebkit2gtk-3.0-dev`

You may need to run this as root, in which case run `su` and log into the root account with a password, or use `sudo apt-get install libgtk-3-dev libwebkit2gtk-3.0-dev` if you have `sudo` installed.

#### Compiling and linking
WDE uses GNU make to produce binaries. 

Compiling and linking is done with G++.
G++ 4.8 has been used throughout the development and it should work.

To perform a full build, simply run:
`make all`

If you only want to compile objects, take a look at the **Makefile**.

### Usage
#### WDE Desktop (wdesktop)
The **wdesktop** module provides a desktop session.

To start it, you need to provide the name of the HTML file with the desktop.

For example, if the HTML for the desktop is stored in a file **desktop.html**, you'd run

`./bin/wdesktop desktop.html`



Note that by default, **wdesktop** will load it from the local server.

To update your local server files, run:

`sudo ./scripts/updatehtml.sh`

### Licensing and contributing
WDE uses the MIT license; take a look at the **LICENSE** file.
You are more than welcome to contribute to the project, if you wish to do so.
