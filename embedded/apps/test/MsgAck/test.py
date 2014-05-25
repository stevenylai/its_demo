import sys
import time
from TOSSIM import *

def setup_radio(sim, count):
    noise = open("meyer-heavy.txt", "r")
    for line in noise:
      s = line.strip()
      if s:
        val = int(s)
        for i in range(count):
          sim.getNode(i).addNoiseTraceReading(val)

    for i in range(count):
      sim.getNode(i).createNoiseModel()

if __name__ == '__main__':
    t = Tossim([])
    r = t.radio()
    t.addChannel("Boot", sys.stdout)
    t.addChannel("Timer", sys.stdout)
    #t.addChannel("MsgList", sys.stdout)
    t.addChannel("MsgAck", sys.stdout)
    #t.addChannel("MsgAckTest", sys.stdout)

    r.add(0, 1, -60.0)
    r.add(1, 0, -60.0)
    setup_radio(t, 4)

    for i in range(0, 2):
        m = t.getNode(i)
        m.bootAtTime((31 + t.ticksPerSecond() / 10) * i + 1)

    while True:
        t.runNextEvent()
        time.sleep(0.1 )
