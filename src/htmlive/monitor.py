import os
import sys
import subprocess
from time import sleep

if __name__ == '__main__':
    child = subprocess.Popen(sys.argv[1],stdin=subprocess.PIPE,stdout=subprocess.PIPE)
    try:
        debug = sys.argv[2]
    except:
        debug = None
    last_change = ''
    while 1:
        try:
            stats = os.stat('ready')
            if stats.st_ctime != last_change:
                last_change = stats.st_ctime
                fl = open('in.txt','r')
                for l in fl.readlines():
                    if len(l) > 0:
                        child.stdin.write(l)
                        if debug:
                            print child.stdout.readline().strip()
                fl.close()
            sleep(0.5)
        except KeyboardInterrupt:
            break
