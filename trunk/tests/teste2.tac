16
8
001:   000(SP) := 1  
002:   004(SP) := 2  
003:   008(SP) := 3  
004:   012(SP) := 4  
005:   IF 000(SP) < 004(SP) GOTO _009
006:   GOTO _007
007:   IF 008(SP) > 012(SP) GOTO _009
008:   GOTO _013
009:   IF 008(SP) > 012(SP) GOTO _013
010:   GOTO _011
011:   000(SP) := 1  
012:   GOTO _014
013:   000(SP) := 0  
014:   000(Rx) := 0  
015:   PRINT 000(SP)
016:   IF 008(SP) > 012(SP) GOTO _020
017:   GOTO _018
018:   IF 000(SP) < 004(SP) GOTO _020
019:   GOTO _024
020:   IF 008(SP) < 012(SP) GOTO _024
021:   GOTO _022
022:   000(SP) := 1  
023:   GOTO _025
024:   000(SP) := 0  
025:   004(Rx) := 0  
026:   PRINT 000(SP)
