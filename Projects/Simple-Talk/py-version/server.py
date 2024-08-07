import socket

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind(("0.0.0.0", 5432))
    s.listen()
    c, addr = s.accept()
    with c:
        print(addr, "connect.")

        while True:
            data = c.recv(1024)
            if not data:
                break
            c.sendall(data)