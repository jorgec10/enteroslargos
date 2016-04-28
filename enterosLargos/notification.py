from pushbullet.pushbullet import PushBullet

apyKey = "APYKEY"

p = PushBullet(apyKey) 

fileHandle = open ( "resultados.txt", "r")
lineList = fileHandle.readlines()
fileHandle.close()

p.pushNote("adrymyry@gmail.com", lineList[-1], "", recipient_type='email')

print lineList[-1]
