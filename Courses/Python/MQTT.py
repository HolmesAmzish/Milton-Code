import hashlib
import hmac

def calculate_mqtt_password(product_key, device_name, timestamp, device_secret):
    data = f"clientId{device_name}deviceName{device_name}productKey{product_key}timestamp{timestamp}"
    signature = hmac.new(device_secret.encode(), data.encode(), hashlib.sha1).hexdigest()
    return signature

product_key = "qwdj89"
device_name = "MyDevice"
timestamp = "20200210"
device_secret = "pomhUHhj"

mqtt_password = calculate_mqtt_password(product_key, device_name, timestamp, device_secret)
print("MQTT密码是:", mqtt_password)