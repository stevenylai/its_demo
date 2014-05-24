import sys
import time
from TOSSIM import *

if __name__ == '__main__':
    t = Tossim([])
    t.addChannel("Boot", sys.stdout)
    t.addChannel("Timer", sys.stdout)
    t.addChannel("MsgList", sys.stdout)
    m = t.getNode(32)
    m.bootAtTime(45654)
    while True:
        t.runNextEvent()
        time.sleep(1)
