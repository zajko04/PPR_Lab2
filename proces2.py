import socket
import codecs
serv = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
serv.bind(('localhost', 9874))
client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_address = ('localhost', 9875)
client.connect(server_address)
while True:
	while True:
		data = serv.recv(4096)
		if not data: break
		temp = str(codecs.encode(data,"hex")) + "\n"
		client.sendto(temp, server_address)
client.close()
