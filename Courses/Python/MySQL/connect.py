import mysql.connector

conn = mysql.connector.connect(
    host = "arorms.cn",
    user = "python",
    password = "123",
    database = "python"
)

print(conn)

mycursor = conn.cursor()
mycursor.execute("SELECT * FROM customers")

myresult = mycursor.fetchall()

for x in myresult:
  print(x)