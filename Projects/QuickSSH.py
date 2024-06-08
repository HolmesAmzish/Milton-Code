import paramiko
import getpass

def read_server_info(file_path):
    servers = []
    with open(file_path, 'r') as file:
        for line in file:
            parts = line.strip().split()
            if len(parts) == 3:
                servers.append({
                    'hostname': parts[0],
                    'username': parts[1],
                    'password': parts[2]
                })
    return servers

def connect_to_server(server_info):
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    try:
        ssh.connect(
            hostname=server_info['hostname'],
            username=server_info['username'],
            password=server_info['password']
        )
        print(f"Connected to {server_info['hostname']}")
        
        
    except paramiko.AuthenticationException:
        print("Authentication failed")
    except paramiko.SSHException as sshException:
        print(f"Unable to establish SSH connection: {sshException}")
    except Exception as e:
        print(f"Exception in connecting to SSH: {e}")

def main():
    file_path = 'devices.txt'
    servers = read_server_info(file_path)
    
    if not servers:
        print("No server information found in the file.")
        return

    print("Available servers:")
    for i, server in enumerate(servers):
        print(f"{i + 1}: {server['hostname']} ({server['username']})")

    try:
        choice = int(input("Choose a server to connect to (by number): ")) - 1
        if 0 <= choice < len(servers):
            connect_to_server(servers[choice])
        else:
            print("Invalid choice")
    except ValueError:
        print("Invalid input")

if __name__ == '__main__':
    main()
