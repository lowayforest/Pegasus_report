# 比武 —— Pegasus 到底强不强？
## Pegasus vs MySQL：大数据批量插入速度对比
MySQL 和 Pegasus 都支持批量写入，可以通过脚本模拟插入相同体量的数据（如百万条），用 sysbench、自定义脚本或 Pegasus 官方 Benchmark 工具进行测试。
### MySQL插入一百万条数据实验
**1. 运行脚本**
``` python
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
```
**2. 运行结果**
![insert_mysql](./images/insert_mysql.png "insert_mysql")

### Pegasus插入一百万条数据实验

**1. 运行脚本**
``` sh


```
**2. 运行结果**

### 实验结果
| 指标               | MySQL       | Pegasus     |
|--------------------|-------------|-------------|
| 插入总耗时（秒）   | 254.53s        | 35s         |
| 插入速率（QPS）    | 3928.81/s     | 28,571/s    |

