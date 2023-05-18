from socket import *
HOST = gethostname()
PORT = 12000
MAX_CONNECTION = 4

class server:
    def __init__(self, sok):
        self.sok = sok
        self.accounts = {}
        self.sep = "\n\t\r"
    
    def welcome(self, cln_name):
        print("%s加入了聊天室" % (cln_name))
        wel = "server"+ self.sep + self.sep + "欢迎 " + cln_name + " 加入聊天室\n"
        wel = wel.encode('utf-8')
        for account in self.accounts:
            self.sok.sendto(wel, self.accounts[account])
    
    def bye(self, cln_name):
            print("%s离开了聊天室" % (cln_name))
            bye = "server"+ self.sep + self.sep + cln_name + " 离开了聊天室\n"
            bye = bye.encode('utf-8')
            for account in self.accounts:
                self.sok.sendto(bye, self.accounts[account])
            
    def add_account(self, account, addr):
        self.accounts[account] = addr
        
    def del_account(self, account):
        self.accounts.pop(account)
        
    def recog(self, msg):
        rev = msg.decode('utf-8').split(self.sep)
        return rev[0], rev[1], rev[2]
    def encrypt(self, sender, receiver, data):
        return (sender + self.sep + receiver + self.sep + data).encode('utf-8')
    
    def send(self, account, msg):
        if msg: self.sok.sendto(msg, self.accounts[account])
        
        
def main():
    print("sever is online...")
    sok = socket(AF_INET, SOCK_DGRAM)
    sok.bind((HOST, PORT))
    sv = server(sok)
    while True:
        msg, addr = sok.recvfrom(2048)
        sender, receiver, data = sv.recog(msg)
        if sender not in sv.accounts:
            sv.add_account(sender, addr)
            sv.welcome(sender)
        # broadcast
        if receiver == "#all":
            broadcast = sv.encrypt(sender + " to all", receiver, data)
            for account in sv.accounts:
                if sender != account: sv.send(account, broadcast)
            continue
        # point to point
        if receiver in sv.accounts:
            sv.send(receiver, msg)
        # exit
        if data == "#exit": 
            sv.del_account(sender)
            sv.bye(sender)
main()
        