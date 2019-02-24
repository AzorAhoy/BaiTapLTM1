# BaiTapLTM1
Welcome to the BaiTapLTM1 wiki!

1. Viết chương trình TCPClient, kết nối đến một máy chủ xác định bởi tên miền hoặc địa chỉ IP. Sau đó nhận dữ liệu từ bàn phím và gửi đến server. Tham số được truyền vào từ dòng lệnh có dạng TCPClient.exe 

2. Viết chương trình TCPServer, đợi kết nối ở cổng xác định bởi tham số dòng lệnh. Mỗi khi có client kết nối đến, thì gửi xâu chào được chỉ ra trong một tệp tin xác định, sau đó ghi toàn bộ nội dung client gửi đến vào một tệp tin khác được chỉ ra trong tham số dòng lệnh TCPServer.exe VD: TCPServer.exe 8888 chao.txt client.txt

3. Viết chương trình clientinfo thực hiện kết nối đến một máy chủ xác định và gửi thông tin về tên máy, danh sách các ổ đĩa có trong máy, kích thước các ổ đĩa. Địa chỉ (tên miền) và cổng nhận vào từ tham số dòng lệnh. VD: clientinfo.exe localhost 1234 

4. Viết chương trình serverinfo đợi kết nối từ clientinfo và thu nhận thông tin từ client, hiện ra màn hình. Tham số dòng lệnh truyền vào là cổng mà serverinfo sẽ đợi kết nối VD: serverinfo.exe 1234
