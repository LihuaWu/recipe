#!/usr/bin/env python2.7
#coding: utf-8

###�ο�����###
#https://www.ibm.com/developerworks/cn/linux/l-cn-pexpect1/
#http://www.ibm.com/developerworks/cn/linux/l-cn-pexpect2/index.html
#http://www.noah.org/wiki/pexpect

import os
import sys
import traceback
import pexpect

SERVER = {
        "master":["22","root","192.168.188.130","budong"],
        "slave":["22","root","192.168.188.131","budong"],
        "will":["22","root","10.11.207.94","will"],
         }

def auto_connect():
    """SSH�Զ���¼�ű�"""
    if len(sys.argv) == 2:
        remote_server = sys.argv[1]
    else:
        print "ʹ�÷�����\n./pexpect_ssh.py ��������"
        sys.exit(1)

    if remote_server in SERVER:
        SSH = "ssh -p %s %s@%s " % (SERVER[remote_server][0],SERVER[remote_server][1],SERVER[remote_server][2])
    else:
        print "��������һ���������������"
        sys.exit(1)

    try:
        child = pexpect.spawn(SSH)
        index = child.expect(['password:','continue connecting (yes/no)?',pexpect.EOF, pexpect.TIMEOUT])
        if index == 0:
            child.sendline(SERVER[remote_server][3])
            child.interact()
        elif index == 1:
            child.sendline('yes')
            child.expect(['password:'])
            child.sendline(SERVER[remote_server][3])
            child.interact()
        elif index == 2:
            print "�ӳ����쳣���˳�!"
            child.close()
        elif index == 3:
            print "���ӳ�ʱ"
    except:
        traceback.print_exec()

if __name__ == '__main__':
    auto_connect()
