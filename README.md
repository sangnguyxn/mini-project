# 🌟 Chương Trình Chuẩn Hóa và Tạo Email (Program 1, 2, 3)

Đây là dự án giải quyết các yêu cầu chuẩn hóa chuỗi và tạo email tự động sử dụng ngôn ngữ C++ và kỹ thuật Two-Pointer.

---

## 💡 Giới Thiệu Chung

Chương trình này bao gồm ba phần chính:

* **Program 1 & 2:** Chuẩn hóa chuỗi tên người dùng (Xóa ký tự lạ, Xóa khoảng trắng thừa).
* **Program 3:** Tự động tạo email theo quy tắc: `lastname + chữ cái đầu của họ/tên đệm + @gmail.com`.

---

## ✅ Yêu Cầu và Tính Năng

### 1. Program 1 & 2: Chuẩn Hóa Tên

1.  Loại bỏ tất cả các ký tự đặc biệt, chỉ giữ lại chữ cái và khoảng trắng.
2.  Loại bỏ khoảng trắng thừa (đầu, cuối, khoảng trắng kép).
3.  Chuẩn hóa chữ hoa/chữ thường (**Ví dụ**: *nGuYen vAn aNh* $\rightarrow$ *Nguyen Van Anh*).

### 2. Program 3: Tạo Email

* **Input:** Tên đã được chuẩn hóa.
* **Output:** Email theo định dạng: `ten + chữ_cái_đầu_họ + chữ_cái_đầu_đệm` + `@gmail.com`.
* **Ví dụ:** *Vu Hoang Dieu* $\rightarrow$ *dieuvh@gmail.com*

---

## 🚀 Hướng Dẫn Sử Dụng

1.  **Môi trường:** Đảm bảo bạn có trình biên dịch C++ (GCC/Clang) được cài đặt.
2.  **Biên dịch:** Sử dụng lệnh sau để biên dịch file `main.cpp`:
    ```bash
    g++ main.cpp -o program_name
    ```
3.  **Thực thi:** Chạy chương trình và nhập tên khi được yêu cầu:
    ```bash
    ./program_name
    ```

---

## 🔑 Kỹ Thuật Chính

Chương trình sử dụng **Kỹ thuật Hai Con trỏ (Two-Pointer)** để tối ưu hóa việc chuẩn hóa chuỗi, thực hiện ghi đè *tại chỗ* (in-place) mà không cần tạo chuỗi tạm thời mới.