# from tkinter import *
# import time
# from socket import *
# from threading import Thread as th
# HOST = gethostname()
# PORT = 12000
# class transer:
#     def __init__(self, cln, server, account, target, buf_size: int = 2048):
#         self.cln        = cln
#         self.server     = server
#         self.buf_size   = buf_size
#         self.account    = account
#         self.target     = target
#     def login(self):
#         msg = self.account + "#*##*#\n"
#         msg = msg.encode("utf-8")
#         self.cln.sendto(msg, self.server)
#     def send(self, msg):
#         if type(msg) is str:
#             msg = (self.account + "#*#" + self.target + "#*#" + msg).encode('utf-8')
#         self.cln.sendto(msg, self.server)
#     def recv(self):
#         msg, addr = self.cln.recvfrom(self.buf_size)
#         msg = msg.decode('utf-8').split("#*#")
#         return msg[0], msg[2]

# def send_process():
#     msgcontent = '我: ' + time.strftime ("%Y-%m-%d %H:%M:%S", time.localtime()) + '\n'
#     text_msglist.insert (END, msgcontent , 'green')
#     msg = text_msg.get('0.0', END)
#     text_msglist.insert (END, msg)
#     text_msg.delete('0.0', END)
#     trans.send(msg)

# def recv_process(trans):
#     while True:
#         try: 
#             src, msg = trans.recv()
#             msgcontent = src + ": "  + time.strftime ("%Y-%m-%d %H:%M:%S", time.localtime()) + '\n'
#             text_msglist.insert (END, msgcontent, 'green')
#             text_msglist.insert (END, msg, 'black')
#         except:
#             pass
# def change_client(name):
#     trans.target = name
#     text_msg.delete('0.0', END)
#     root.title('与' + trans.target + '聊天中')
# def on_closing():
#     change_client("server")
#     trans.send("#exit")
#     root.destroy()

# def draw():
#     text_msglist.tag_config('green', foreground='#008B00')
#     #使用grid设置各个容器的位置
#     frame_left_top.grid(row = 0, column = 0, columnspan = 2, padx = 2, pady = 5)
#     frame_left_center.grid(row = 1, column = 0, columnspan = 2,)
#     frame_right_bottom.grid(row = 2, column = 1)
#     frame_left_bottom.grid(row = 2, column = 0)
#     frame_left_top.grid_propagate (0)
#     frame_left_center.grid_propagate (0)
#     frame_right_bottom.grid_propagate (0)
#     frame_left_bottom.grid_propagate (0)
    
#     #把元素填充进frame
#     text_msglist.grid()
#     text_msg.grid()
#     button_sendmsg.grid(sticky = W)
#     button_chcln.grid(sticky = E)

# cln = socket(AF_INET, SOCK_DGRAM)
# account = input("请输入聊天账号: ")
# target = input("请输入聊天对象：")
# trans = transer(cln, (HOST, PORT), account, target)

# root = Tk ()
# root.title('与' + target + '聊天中')

# frame_left_top = Frame (width=380, height=270, bg='white')
# frame_left_center = Frame (width=380, height=130, bg='white')
# frame_right_bottom = Frame (width=190,height=30)
# frame_left_bottom = Frame(width=190, height=30)

# text_msglist = Text(frame_left_top)
# text_msg = Text(frame_left_center)
# button_sendmsg = Button(frame_right_bottom, text=("发送消息") , command = send_process)
# button_chcln = Button(frame_left_bottom, text = ("更改聊天对象"), command = lambda:change_client(text_msg.get('0.0', END).strip()))
# draw()

# recv_trd = th(target = recv_process, args = (trans, ))
# recv_trd.daemon = True
# recv_trd.start()
# trans.login()
# root.protocol('WM_DELETE_WINDOW', on_closing)
# root.mainloop()

# import sys
# from socket import *
# from threading import Thread as th

# HOST = gethostname()
# PORT = 12000

# class transer:
#     def __init__(self, cln, server, account, buf_size: int = 2048):
#         self.cln        = cln
#         self.server     = server
#         self.buf_size   = buf_size
#         self.account    = account
#     def login(self):
#         msg = self.account + "#*##*#"
#         msg = msg.encode("utf-8")
#         self.cln.sendto(msg, self.server)
#     def send(self, msg, target):
#         if type(msg) is str:
#             msg = (self.account + "#*#" + target + "#*#" + msg).encode('utf-8')
#         self.cln.sendto(msg, self.server)
#     def recv(self):
#         msg, addr = self.cln.recvfrom(self.buf_size)
#         msg = msg.decode('utf-8').split("#*#")
#         return msg[0], msg[2]
    

# def send_process(trans, msg, target):
#     trans.send(msg, target)

# def recv_process(trans):
#     while True:
#         try: 
#             src, msg = trans.recv()
#             print("%s: %s" % (src, msg))
#         except:
#             pass
    
# def main():
#     cln = socket(AF_INET, SOCK_DGRAM)
#     account = input("请输入聊天账号: ")
#     trans = transer(cln, (HOST, PORT), account)
    
#     recv_trd = th(target = recv_process, args = (trans, ))
#     recv_trd.daemon = True
#     recv_trd.start()
#     trans.login()
#     target = input("请输入聊天对象的账号: ")
#     print("当前聊天对象为: %s" % (target))
#     while True:
#         msg = input()
#         if not msg: continue
#         if msg == "#chcln":
#             target = input("请输入聊天对象的账号: ")
#             print("当前聊天对象为: %s" % (target))
#             continue
#         send_trd = th(target = send_process, args = (trans, msg, target, ))
#         send_trd.start()
#         if msg == "#exit": 
#             sys.exit(0)
# main()