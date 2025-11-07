#include <iostream>
#include <string>
#include <limits> // Cần cho std::cin.ignore()

// Khai báo hằng số toàn cục
const int ASCII = 32;
const std::string GMAIL_DOMAIN = "@gmail.com"; // Đổi tên biến cho rõ ràng hơn

// --- CÁC HÀM KIỂM TRA & CHUYỂN ĐỔI THỦ CÔNG ---
bool is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}
bool is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}
char to_convert_lowupper(char c) { // chuyển thành chữ thường (Đã sửa logic)
    if(is_upper(c)) {
        return c + ASCII; // Sửa: Chữ hoa -> Chữ thường là CỘNG 32
    }
    return c;
}
char to_convert_isupper(char c) { // chuyển thành chữ hoa (Đã sửa logic)
    if(is_lower(c)) {
        return c - ASCII; // Sửa: Chữ thường -> Chữ hoa là TRỪ 32
    }
    return c;
}

// --- PROGRAM 2A: XÓA KÝ TỰ LẠ (DK1) ---
std::string special_character_advanced(std::string& name) {
    int index_first = name.length(); 
    bool check_ki_tu_hop_le = true;
    int j = 0;
    for(int i = 0; i < name.length(); i++) {
        // Chỉ giữ lại chữ cái và khoảng trắng
        check_ki_tu_hop_le = (is_lower(name[i]) || is_upper(name[i]) || name[i] == ' '); 
        if(check_ki_tu_hop_le == true) {
            name[j] = name[i];
            j++;
        }
    }
    name.resize(j);
    return name;
}

// --- PROGRAM 2B: XÓA KHOẢNG TRẮNG THỪA (DK2) ---
std::string delete_space_odd(std::string& name) {
    // Vu@12  H@29oa2ng  D@i%eu
    int index_first = name.length();
    bool check_double_space = true; // Bắt đầu TRUE để loại bỏ khoảng trắng đầu
    int j = 0;
    for(int i = 0; i < index_first; i++) {
        if(name[i] != ' ') {
            name[j] = name[i];
            j++;
            check_double_space = false;
        } else {
            if(!check_double_space) {
                name[j] = ' ';
                j++;
                check_double_space = true; // Sửa lỗi: Phải là TRUE sau khi ghi space
            }
        }
    }
    if(j > 0 && name[j - 1] == ' ') {
        j--; // Xử lý khoảng trắng cuối
    }
    name.resize(j);

    return name;
}

// --- PROGRAM 2C: CHUẨN HÓA VIẾT HOA/THƯỜNG (DK3) ---
std::string to_low_all_chac(std::string& name) { // Hạ cấp tất cả
    for(int i = 0; i < name.length(); i++) {
        // Sửa lỗi: PHẢI GÁN KẾT QUẢ TRẢ VỀ
        name[i] = to_convert_lowupper(name[i]); 
    }
    return name;
}
std::string is_upper_chac_first(std::string& name) { // Viết hoa chữ cái đầu
    if (name.length() > 0) {
        // Sửa lỗi: PHẢI GÁN KẾT QUẢ TRẢ VỀ
        name[0] = to_convert_isupper(name[0]); // mặc định 0 luôn luôn là hoa
    }

    for(int i = 1; i < name.length(); i++) {
        if(name[i - 1] == ' ') {
            // Sửa lỗi: PHẢI GÁN KẾT QUẢ TRẢ VỀ
            name[i] = to_convert_isupper(name[i]);
        }
    }
    return name;
}

/*
3 - program_3(std::string s)
Output: email id được tạo tự động từ tên người (đã được chuẩn hoá).
Quy tắc đặt email id = lastname + các chữ cái đầu của phần họ và tên đệm. Ko có chữ cái nào viết hoa. Tên miền của email là @gmail.com
Ví dụ:
Nguyen Nhat Sang => sangnn@gmail.com
Vu Hoang Dieu => dieuvh@gmail.com
Trinh Tran Phuong Tuan => tuanttp@gmail.com
*/
// --- PROGRAM 3: TẠO EMAIL ---
std::string program_3(std::string& name) {
   
    // Vu Hoang Dieu
    // 1. Tìm vị trí Bắt đầu của Tên Cuối
    int last_index = 0; 
    for(int i = name.length() - 1; i >= 0; i--) { // duyệt ngược lấy index cuối
        if(name[i] == ' ') {
            last_index = i + 1; // lấy index tên cuối
            break;
        }
    } 
    
    // 2. Lấy Tên Cuối (chữ thường)
    std::string id_email = ""; // tạo chuỗi mới
    for(int i = last_index; i < name.length(); i++) {
        id_email += to_convert_lowupper(name[i]); // chuyển chuỗi index vừa lấy thành chữ thường
    } 
    
    // 3. Lấy chữ cái đầu của các từ còn lại (họ và tên đệm)
    for(int i = 0; i < last_index; i++) { // duyện từ 0 -> index lấy được
        if( i == 0 || name[i - 1] == ' ') { // lấy tại i == 0 và i - 1 == ' ' 
            id_email += to_convert_lowupper(name[i]);
        }
    }
    
    return id_email + GMAIL_DOMAIN;
}

// --- HÀM MAIN (HỢP NHẤT) ---
int main() {
    std::string name = "";
    std::cout << "Vui Long Input name: "; 
    
    // Khắc phục lỗi input buffer nếu có lệnh cin >> trước đó
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    // BƯỚC 1: Xóa ký tự lạ (DK1)
    special_character_advanced(name);

    // BƯỚC 2: Xóa khoảng trắng thừa (DK2)
    delete_space_odd(name);

    // BƯỚC 3: Chuẩn hóa viết hoa/thường (DK3)
    to_low_all_chac(name);
    is_upper_chac_first(name);

    std::cout << "\n--- Chuẩn hóa: ";
    for(int i = 0; i < name.length(); i++) {
        std::cout << name[i];
    }
    std::cout << "\n";
    
    // BƯỚC 4: Tạo Email (Program 3)
    std::string email = program_3(name);
    
    std::cout << "--- Email ID: " << email;
    std::cout << "\n";
    
    return 0;
}