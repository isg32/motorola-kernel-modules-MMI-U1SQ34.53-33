;--------------------------------------------------------
;Verify Existing Firmware Version
;--------------------------------------------------------
W: AA 00 01 00
C: AA 00 26 04
W: AA 00 02 00
C: AA 00 02 02
;--------------------------------------------------------
;SET_CFGUPDATE
;--------------------------------------------------------
W: AA 00 13 00
X: 1100
;--------------------------------------------------------
;Data Block
;--------------------------------------------------------
W: AA 3E 53 00
W: AA 40 27 67 11 59 DF E0 E3 E2 E0 E0 E0 E0 E1 E3 E3 E4 E5 E7 E9 E4 E4 E5 E3 F0 EF F5 F2 F7 F6 F9 F9 FA
W: AA 60 94
X: 10
W: AA 3E 53 00
C: AA 60 94
W: AA 3E 53 01
W: AA 40 FC F6 F6 F2 F1 EF F2 FE FA E0 80 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
W: AA 60 FB
X: 10
W: AA 3E 53 01
C: AA 60 FB
W: AA 3E 54 00
W: AA 40 FE 86 03 F7 ED 00 04 05 0E FF 10 03 F7 05 07 02 FE 0B 28 23 01 E1 00 16 E6 1D EE 00 F6 EB C0 9C
W: AA 60 EC
X: 10
W: AA 3E 54 00
C: AA 60 EC
W: AA 3E 54 01
W: AA 40 CD DD 1D 22 CE 52 0A 54 FA 81 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
W: AA 60 1D
X: 10
W: AA 3E 54 01
C: AA 60 1D
W: AA 3E 55 00
W: AA 40 FF 52 02 06 01 FE FE 08 03 FD 03 01 FD 04 13 45 11 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
W: AA 60 33
X: 10
W: AA 3E 55 00
C: AA 60 33
W: AA 3E 6C 00
W: AA 40 FE CA 02 02 04 01 17 EA 06 F0 FE 00 01 F9 DF AD F3 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
W: AA 60 C0
X: 10
W: AA 3E 6C 00
C: AA 60 C0
W: AA 3E 59 00
W: AA 40 00 28 00 28 00 2C 00 37 00 46 00 2A 00 32 00 2A 00 29 00 29 00 2D 00 2E 00 37 00 4E 00 A8 00 00
W: AA 60 A6
X: 10
W: AA 3E 59 00
C: AA 60 A6
W: AA 3E 6D 00
W: AA 40 05 05 0E E5 0E BA 11 59 11 27 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
W: AA 60 98
X: 10
W: AA 3E 6D 00
C: AA 60 98
;--------------------------------------------------------
;Exit CFGUPDATE
;--------------------------------------------------------
W: AA 00 00 00
W: AA 00 42 00
X: 2000
