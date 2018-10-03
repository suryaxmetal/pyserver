import socket

client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

client.connect(('127.0.0.1',4444))

data = client.recv(1024)

print(data)

