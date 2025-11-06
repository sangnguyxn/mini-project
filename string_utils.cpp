#include <iostream>
#include <string>
const int ASCII = 32;
const std::string gmail = "@gmail.com";
char to_is_lower(char c) { // chuyển thành chữ thường
    if(c >= 'A' && c <= 'Z') {
        return c + ASCII;
    }
    return c;
}
std::string program_3(std::string& name) {
   
    // Vu Hoang Dieu
    int last_index = name.length();
    for(int i = name.length() - 1; i >= 0; i--) { // duyệt ngược lấy index cuối
        if(name[i] == ' ') {
            last_index = i + 1; // lấy index tên cuối
            break;
        }
    } // last_index = 9
    std::string id_email = ""; // tạo chuõi mới
    for(int i = last_index; i < name.length(); i++) {
        id_email += to_is_lower(name[i]);
    } // chuyển chuỗi index vừa lấy thành chữ thường
    for(int i = 0; i < last_index; i++) { // duyện từ 0 -> index lấy được
        if( i == 0 || name[i - 1] == ' ') { // lấy tại i == 0 và i - 1 == ' ' 
            id_email += to_is_lower(name[i]);
        }
    }
    return id_email + gmail;
}

int main() {
    std::string name = "";
    std::cout << "Vui Long Input name: "; getline(std::cin, name);

    // for(int i = 0; i < name.length(); i++) {
    //     std::cout << name[i];
    // }
    std::cout << "Enter: " << program_3(name);
    std::cout << "\n";
}