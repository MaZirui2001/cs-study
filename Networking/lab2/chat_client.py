from tkinter import *
import time
from socket import *
from threading import Thread as th
from tkinter.simpledialog import askstring 
HOST = gethostname()
PORT = 12000
# client object
class client:
    def __init__(self, sok, server, account, target, buf_size: int = 2048):
        self.sok        = sok
        self.server     = server
        self.buf_size   = buf_size
        self.account    = account
        self.target     = target
    
    def login(self):
        msg = self.account + "\n\t\r\n\t\r\n"
        msg = msg.encode("utf-8")
        self.sok.sendto(msg, self.server)
    
    def send(self, msg):
        if type(msg) is str:
            msg = (self.account + "\n\t\r" + self.target + "\n\t\r" + msg).encode('utf-8')
        self.sok.sendto(msg, self.server)
    
    def recv(self):
        msg, addr = self.sok.recvfrom(self.buf_size)
        msg = msg.decode('utf-8').split("\n\t\r")
        return msg[0], msg[2]

def send_process(event):
    msgcontent = '我: ' + time.strftime ("%Y-%m-%d %H:%M:%S", time.localtime()) + '\n'
    text_msglist.insert (END, msgcontent , 'green')
    msg = text_msg.get('0.0', END).strip() + '\n'
    text_msglist.insert (END, msg)
    text_msg.delete('0.0', END)
    trans.send(msg)

def recv_process(trans):
    while True:
        try: 
            src, msg = trans.recv()
            msgcontent = src + ": "  + time.strftime ("%Y-%m-%d %H:%M:%S", time.localtime()) + '\n'
            text_msglist.insert (END, msgcontent, 'green')
            text_msglist.insert (END, msg, 'black')
        except:
            pass

# change chat object
def change_client(name):
    trans.target = name
    text_msg.delete('0.0', END)
    root.title(trans.account + "与" + trans.target + "聊天中")

# exit the chatroom
def on_closing():
    change_client("#server")
    trans.send("#exit")
    root.destroy()

def draw():
    text_msglist.tag_config('green', foreground='#008B00')
    # set the location of frames
    frame_left_top.grid(row = 0, column = 0, columnspan = 2)
    frame_left_center.grid(row = 1, column = 0, columnspan = 2)
    frame_right_bottom.grid(row = 2, column = 1)
    frame_left_bottom.grid(row = 2, column = 0)
    frame_left_top.grid_propagate (0)
    frame_left_center.grid_propagate (0)
    frame_right_bottom.grid_propagate (0)
    frame_left_bottom.grid_propagate (0)
    
    # fill the elems to frame
    text_msglist.grid()
    text_msg.grid()
    button_sendmsg.grid(sticky = W)
    button_chcln.grid(sticky = E)

sok = socket(AF_INET, SOCK_DGRAM)

root = Tk ()
root.title("聊天室")
root.bind('<Return>', send_process)

frame_left_top = Frame (width=380, height=300, bg='white')
frame_left_center = Frame (width=380, height=130, bg='white')
frame_right_bottom = Frame (width=190,height=30)
frame_left_bottom = Frame(width=190, height=30)

text_msglist = Text(frame_left_top)
text_msg = Text(frame_left_center)
button_sendmsg = Button(frame_right_bottom, text = ("发送消息") , command = lambda: send_process(0))
button_chcln = Button(frame_left_bottom, text = ("更改聊天对象"), command = lambda:change_client(text_msg.get('0.0', END).strip()))
draw()
account = askstring(title = "登录", prompt = "请输入你的聊天账号: ")
target = askstring(title = "登录", prompt = "请输入你的聊天对象账号: ")
trans = client(sok, (HOST, PORT), account, target)
root.title(trans.account + "与" + trans.target + "聊天中")
root.resizable(False, False)

recv_trd = th(target = recv_process, args = (trans, ))
recv_trd.daemon = True
recv_trd.start()
trans.login()
root.protocol('WM_DELETE_WINDOW', on_closing)
root.mainloop()