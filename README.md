qtar8200
========

Description
-----------

The goal of this project is to attempt to be the most feature-rich gui controller for the AOR AR8200 communications receiver.

Beyond just controlling the radio, it allows automated/unattended logging of found frequencies, 
and recording audio while running unattended. Everything is logged to a MySQL database, thus allowing the possibility
to have multiple receivers connected to multiple computers log to a central database.

Current state
-------------

I initially started this as a very quick and dirty application to satisfy my own needs since I was not too happy with existing 
AR8200 frontends. I kept adding features, and it eventually started to resemble somthing other people could make use of.
At present it's not really fit yet for public consumption. Many things are missing such as configuration dialogs to select
the serial port settings and what not. (These are now just hardcoded to what works on my system). Some features are also not yet 
fully implemented. The codebase is also pretty ugly compared to what I'm used to write. Before finishing the implementation of any missing features and configuration dialogs and what not, I want to first reorganize the code a bit to make things a bit. I do eventually plan to make this fit for public use :)

Screenshots
-----------

Here's some screenshots of qtar8200 in action so far:

![qtar8200 frequency database](http://linkerror.com/stuff/qtar8200_2.png)

![qtar8200 VFO scan](http://linkerror.com/stuff/qtar8200_3.png)

![qtar8200 logger](http://linkerror.com/stuff/qtar8200_5.png)
