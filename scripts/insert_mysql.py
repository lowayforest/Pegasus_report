import mysql.connector
import time

conn = mysql.connector.connect(
    host="localhost",
    user="root",
    password="123456",
    database="test"
)
cursor = conn.cursor()
cursor.execute("DROP TABLE IF EXISTS test_data")
cursor.execute("CREATE TABLE test_data (id INT PRIMARY KEY, value VARCHAR(255))")

start = time.time()
for i in range(1000000):
    cursor.execute("INSERT INTO test_data (id, value) VALUES (%s, %s)", (i, f"val_{i}"))
    if i % 10000 == 0:
        conn.commit()
end = time.time()

conn.commit()
cursor.close()
conn.close()

print(f"MySQL 插入 100 万条耗时：{end - start:.2f} 秒")
