1 Print Tab(26); "CONDOT"
2 Print Tab(20); "CREATIVE COMPUTING"
3 Print Tab(18); "MORRISTOWN, NEW JERSEY": Print
4 Print
5 Print
6 Print "THIS PROGRAM WILL PLAY CONNECT THE DOTS UNH YOU."
7 Print "THE GAME IS PLAYED ON A 4 X 4 ARRAY. WHEN"
8 Print "YOU WANT TO MAKE A MOVE YOU MUST TYPE IN"
9 Print "THE COORDINATES OF THE SPACE BETUEEN THE TWO DOTS YOU"
10 Print "WANT TO CONNECT. ENTER EACH OF YOUR MOVES BY TYPING"
11 Print "THE ROW NUMBER, A COMMA AND THE COLUMN NUMBER."
12 Print "THE UPPER LEFT HAND CORNER OF THE ARRAY IS 1,1."
13 Print "HERE WE GO."
20 Dim A(12, 12)
30 V = 0
40 For R = 1 To 12
    50 For C = 1 To 12
        60 If R / 2 = Int(R / 2) Then 100
        70 If C / 2 = Int(C / 2) Then 100
        80 A(R, C) = -50
        90 GoTo 110
        100 A(R, C) = 0
    110 Next C
120 Next R
200 GoSub 1000

210 Print "YOUR MOVE";
220 Input X, Y
230 If X = Int(X) Then 260
240 Print "YOU REALLY DON'T WANT TO PUT A LINE THERE!!!!"
250 GoTo 210
260 If (X - 1) * (X - 7) > 0 Then 240
265 X = X + 2
270 If (Y - 1) * (Y - 7) > 0 Then 240
272 Y = Y + 2
280 If (X + Y + 1) / 2 <> Int((X + Y + 1) / 2) Then 240
290 If A(X, Y) <> 0 Then 240
300 A(X, Y) = 50



310 If X / 2 = Int(X / 2) Then 380
320 If A(X - 2, Y) + A(X - 1, Y + 1) + A(X - 1, Y - 1) <> 150 Then 350
330 P = 1
340 A(X - 1, Y) = 1
350 If A(X + 2, Y) + A(X + 1, Y + 1) + A(X + 1, Y - 1) <> 150 Then 440
360 A(X + 1, Y) = 1
370 GoTo 200
380 If A(X, Y - 2) + A(X + 1, Y - 1) + A(X - 1, Y - 1) <> 150 Then 410
390 A(X, Y - 1) = 1
400 P = 1
410 If A(X, Y + 2) + A(X + 1, Y + 1) + A(X - 1, Y + 1) <> 150 Then 440
420 A(X, Y + 1) = 1
430 GoTo 200
440 If P = 1 Then 200
450 GoSub 1000



460 Print "MY MOVE"
470 For R = 4 To 10 Step 2
    480 For C = 4 To 10 Step 2
        490 If A(R - 1, C) + A(R + 1, C) + A(R, C - 1) + A(R, C + 1) <> 150 Then 680
        500 A(R, C) = -1
        510 If A(R - 1, C) <> 0 Then 550
        520 A(R - 1, C) = 50
        530 If A(R - 3, C) + A(R - 2, C - 1) + A(R - 2, C + 1) <> 150 Then 450
        540 Let A(R - 2, C) = -1
        550 If A(R + 1, C) <> 0 Then 590
        560 A(R + 1, C) = 50
        570 If A(R + 3, C) + A(R + 2, C - 1) + A(R + 2, C + 1) <> 150 Then 450
        580 A(R + 2, C) = -1
        590 If A(R, C - 1) <> 0 Then 630
        600 A(R, C - 1) = 50
        610 If A(R, C - 3) + A(R - 1, C - 2) + A(R + 1, C + 2) <> 150 Then 450
        620 A(R, C - 2) = -1
        630 If A(R, C + 1) <> 0 Then 450
        640 A(R, C + 1) = 50
        650 If A(R, C + 3) + A(R - 1, C + 2) + A(R + 1, C + 2) <> 150 Then 450
        660 A(R, C + 2) = -1
        670 GoTo 450
    680 Next C
690 Next R

692 If E > 1 Then 730
700 If A(12 - X, 12 - Y) <> 0 Then 730
710 A(12 - X, 12 - Y) = 50
712 If E > 1 Then 870
720 GoTo 200
730 For R = 3 To 9
    740 For C = 3 To 9
        750 If (R + C) / 2 = Int((R + C) / 2) Then 850
        760 If A(R, C) <> 0 Then 850
        780 If R / 2 = Int(R / 2) Then 830
        790 If A(R - 2, C) + A(R - 1, C - 1) + A(R - 1, C + 1) = 100 Then 850
        800 If A(R + 2, C) + A(R + 1, C - 1) + A(R + 1, C + 1) = 100 Then 850
        810 A(R, C) = 50
        820 GoTo 200
        830 If A(R, C - 2) + A(R - 1, C - 1) + A(R + 1, C - 1) = 100 Then 850
        840 If A(R, C + 2) + A(R - 1, C + 2) + A(R + 1, C + 1) <> 100 Then 810
    850 Next C
860 Next R
862 If E > 1 Then 700

870 R = Int(Rnd(1) * 7) + 3
880 C = Int(Rnd(1) * 7) + 3
881 If R / 2 = Int(R / 2) Then 885
882 If C / 2 = Int(C / 2) Then 900
883 GoTo 870
885 If C / 2 <> Int(C / 2) Then 900
886 GoTo 870
900 If A(R, C) <> 0 Then 870
910 A(R, C) = 50
920 GoTo 200
930 Print "DO YOU WANT TO PLAY AGAIN (TYPE 1 FOR YES OR 2 FOR NO)"
940 Input B
950 If B = 1 Then 40
960 End

1000 P = 0
1010 D = 0
1020 E = 0
1030 For R = 3 To 9
    1040 For C = 3 To 9
        1050 If A(R, C) <> 0 Then 1080
        1060 Print "   ";
        1070 GoTo 1240
        1080 If A(R, C) <> -50 Then 1110
        1090 Print " . ";
        1100 GoTo 1240
        1110 If A(R, C) <> -1 Then 1140
        1120 Print " C ";
        1130 GoTo 1170
        1140 If A(R, C) <> 1 Then 1200
        1150 Print " H ";
        1170 D = D + A(R, C)
        1180 E = E + 1
        1190 GoTo 1240
        1200 If R / 2 = Int(R / 2) Then 1230
        1210 Print " - ";
        1220 GoTo 1240
        1230 Print " : ";
    1240 Next C
    1245 Print
1250 Next R
1255 Print E
1257 Print D
1260 If E >= 9 Then 1280
1270 Return
1280 If D > 0 Then 1310
1290 Print "I WON"
1300 GoTo 930
1310 Print "YOU WON!!!"
1320 GoTo 930
1400 End
