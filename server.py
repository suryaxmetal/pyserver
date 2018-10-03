import socket

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

h = '127.0.0.1'
p = 4444

server.bind((h,p))

server.listen(4444)

print("Listening on port : 4444")

while(True):
  conn,addr = server.accept()

  conn.send(b"hello !")

  conn.close()

  break



server.close()

  