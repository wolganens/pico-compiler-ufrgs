16
16
001:   000(SP) := 2  
002:   004(SP) := 1  
003:   008(SP) := 1  
004:   012(SP) := 1  
005:   IF 008(SP) < 5 GOTO _007
006:   GOTO _018
007:   IF 000(SP) > 004(SP) GOTO _010
008:   GOTO _009
009:   GOTO _010
010:   GOTO _011
011:   000(Rx) := 008(SP) ADD 1
012:   008(SP) := 000(Rx)  
013:   GOTO _016
014:   004(Rx) := 012(SP) SUB 1
015:   012(SP) := 004(Rx)  
016:   008(Rx) := 0  
017:   GOTO _005
018:   012(Rx) := 0  
019:   PRINT 008(SP)
