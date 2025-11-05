Nhập vào 1 chuỗi kí tự có nội dung là tên người. Chuỗi kí tự tên người được gọi là chuẩn hoá khi nó thoả mãn các điều kiện sau:
(DK1) Chuỗi chỉ bao gồm các chữ cái và khoảng trắng
(DK2) Khoảng trắng ko đứng đầu hoặc đứng cuối chuỗi. Giữa các từ trong chuỗi, chỉ được tối đa 1 khoảng trắng
(DK3) Chữ cái đầu mỗi từ phải viết hoa, chữ còn lại phải viết thường.
Viết các function sau với input là chuỗi kí tự vừa nhập, có thể chọn char array hoặc std::string tuỳ ý.
1 - program_1(...) kiểm tra tính chuẩn hoá của họ tên vừa nhập
Output: true/1 (nếu họ tên đã được chuẩn hoá) hoặc false/0 (nếu họ tên chưa được chuẩn hoá)
2 - program_2(...)
Output: Chuỗi chuẩn hoá từ chuỗi input nhập vào. Cách thức xử lý cho các điều kiện ko thoả mãn như sau:
(a) Xoá các kí tự đặc biệt (ko phải là chữ cái và khoảng trắng)
(b) Xoá các kí tự trắng thừa ở đầu hoặc cuối chuỗi hoặc giữa chuỗi
(c) Viết hoa chữ cái đầu của mỗi từ trong chuỗi, chữ cái còn lại phải viết thường.
3 - program_3(std::string s)
Output: email id được tạo tự động từ tên người (đã được chuẩn hoá).
Quy tắc đặt email id = lastname + các chữ cái đầu của phần họ và tên đệm. Ko có chữ cái nào viết hoa. Tên miền của email là @gmail.com
Ví dụ:
Nguyen Nhat Sang => sangnn@gmail.com
Vu Hoang Dieu => dieuvh@gmail.com
Trinh Tran Phuong Tuan => tuanttp@gmail.com