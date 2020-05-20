import socket
import codecs
serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.bind(('localhost', 9874))
serv.listen(5)
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('localhost', 9875))
while True:
	conn, addr = serv.accept()
	while True:
		data = conn.recv(4096)
		if not data: break
		temp = str(codecs.encode(data,"hex")) + "\n"
		client.send(temp)
	conn.close()
client.close()
