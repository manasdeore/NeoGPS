#ifndef GPSport_h
#define GPSport_h

//  Copyright (C) 2014-2017, SlashDevin
//
//  This file is part of NeoGPS
//
//  NeoGPS is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  NeoGPS is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with NeoGPS.  If not, see <http://www.gnu.org/licenses/>.

//-----------------------------------------------------------
//  There are 2 ways this file can be used:
//
//  I.  AS IS, which tries to *guess* which port a beginner should use.
//      If you include <SoftwareSerial.h>, <NeoSWSerial.h>, <AltSoftSerial.h>,
//      <NeoICSerial.h>  *OR*  <NeoHWSerial.h> before this file (in the INO)
//      or on line 152 below, one of those ports will be used for the GPS.
//      This file cannot always guess what you want, so you may need to use it
//      in the 2nd way...
//
//  II. *REPLACE EVERYTHING* in this file to *specify* which port and
//      which library you want to use for that port.  Just declare the
//      port here.  You must declare three things:
//
//         1) the "gpsPort" variable (used by all example programs),
//         2) the string for the GPS_PORT_NAME (displayed by all example programs), and
//         3) the DEBUG_PORT to use for Serial Monitor print messages (usually Serial).
//
//      The examples will display the device you have selected during setup():
//
//         DEBUG_PORT.println( F("Looking for GPS device on " GPS_PORT_NAME) );
//
//      Choosing the serial port connection for your GPS device is probably
//      the most important design decision, because it has a tremendous impact
//      on the processor load.  Here are the possible configurations,
//      from BEST to WORST:
//
// ---  The BEST choice is to use a HardwareSerial port. You could use Serial
//      on any board, but you will have to disconnect the Arduino RX pin 0
//      from the GPS TX pin to upload a new sketch over USB.  This is a very
//      reliable connection:
//
//             #define gpsPort Serial
//             #define GPS_PORT_NAME "Serial"
//             #define DEBUG_PORT Serial
//
//      If you have a Mega, Leo or Due board, you could use Serial1,
//      Serial2 or Serial3:
//
//             #define gpsPort Serial1
//             #define GPS_PORT_NAME "Serial1"
//             #define DEBUG_PORT Serial
//
//      These extra ports do not have to be disconnected to upload new
//      sketches over USB.
//
//      Use NeoHWSerial if you want to handle GPS characters
//      in an Interrupt Service Routine (see NMEA_isr.INO).
//      Also uncomment NMEAGPS_INTERRUPT_PROCESSING in NMEAGPS_cfg.h.
//
//             #include <NeoHWSerial.h>
//             #define gpsPort NeoSerial
//             #define GPS_PORT_NAME "NeoSerial"
//             #define DEBUG_PORT NeoSerial
//
//      Note that the DEBUG_PORT must be NeoSerial, not Serial
//      (see NeoHWSerial documentation for additional requirements).
//
// ---  The SECOND BEST choice is AltSoftSerial.  It uses 10x to 500x
//      more processor time than a HardwareSerial port, but it is the BEST
//      *software* serial port library.  It only works on two specific pins
//      (see the AltSoftSerial documentation).
//
//             #include <AltSoftSerial.h>
//             AltSoftSerial gpsPort; // 8 & 9 for an UNO
//             #define GPS_PORT_NAME "AltSoftSerial"
//             #define DEBUG_PORT Serial
//
//      Use NeoICSerial if you want to handle GPS characters
//      in an Interrupt Service Routine (see NMEA_isr.INO).
//      Also uncomment NMEAGPS_INTERRUPT_PROCESSING in NMEAGPS_cfg.h.
//
//             #include <NeoICSerial.h>
//             NeoICSerial gpsPort; // 8 & 9 for an UNO
//             #define GPS_PORT_NAME "NeoICSerial"
//             #define DEBUG_PORT Serial
//
// ---  The THIRD BEST choice is NeoSWSerial.  It is almost as efficient as
//      AltSoftSerial, but it only supports baud rates 9600, 19200 or 38400.
//
//             #include <NeoSWSerial.h>
//             NeoSWSerial gpsPort(3, 2);
//             #define GPS_PORT_NAME "NeoSWSerial(3,2)"
//             #define DEBUG_PORT Serial
//
//      NeoSWSerial supports handling GPS characters in an Interrupt Service
//      Routine (see NMEA_isr.INO).  If you want to do that, also uncomment
//      NMEAGPS_INTERRUPT_PROCESSING in NMEAGPS_cfg.h.
//
// ---  The WORST choice is SoftwareSerial.  IT IS NOT RECOMMENDED because
//      it disables interrupts for the entire time a character is sent OR
//      received.  This interferes with other parts of your sketch or with
//      other libraries.  It prevents receiving or sending data on any other
//      port.  It cannot transmit and receive at the same time.  95% of the
//      CPU time will be spent twiddling its thumbs.  It may support 57600,
//      but 115200 is rarely reliable.
//
//             #include <SoftwareSerial.h>
//             SoftwareSerial gpsPort(2,3);
//             #define GPS_PORT_NAME "SoftwareSerial(8,9)"
//             #define DEBUG_PORT Serial
//
//      You should *seriously* consider using other pins or lower baud rates,
//      so that you could use one of the other recommended ports.
//-----------------------------------------------------------

// DEFAULT file contents:
//   *GUESS* which port should be used.  If you know what port you want to use,
//             *DELETE* the rest of this file and declare your own GPS port variable,
//             GPS port name string, and debug print port variable (see above).

#define gpsPort Serial2
#define GPS_PORT_NAME "Serial2"
#define DEBUG_PORT Serial

// End of guessing game.
//------------------------

#endif
