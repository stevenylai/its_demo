import sys
import time
from TOSSIM import *

if __name__ == '__main__':
    t = Tossim([])
    t.addChannel("Boot", sys.stdout)
    t.addChannel("Timer", sys.stdout)
    t.addChannel("MsgList", sys.stdout)
    t.addChannel("MsgAck", sys.stdout)
    t.addChannel("MsgAckTest", sys.stdout)
    receiver = t.getNode(0)
    receiver.bootAtTime(45654)
    sender = t.getNode(1)
    sender.bootAtTime(45654)
    while True:
        t.runNextEvent()
        time.sleep(0.1)
