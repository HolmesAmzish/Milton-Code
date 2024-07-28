import socket

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect(("127.0.01", 5432))
    s.sendall(b"Hello, World!")
    data = s.recv(1024)
    print("Recevied:", repr(data))