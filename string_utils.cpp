#include <iostream>
#include <string>
/*
2 - program_2(...)
Output: Chuỗi chuẩn hoá từ chuỗi input nhập vào. Cách thức xử lý cho các điều kiện ko thoả mãn như sau:
Dk1: Xoá các kí tự đặc biệt (ko phải là chữ cái và khoảng trắng)
Dk2: Xoá các kí tự trắng thừa ở đầu hoặc cuối chuỗi hoặc giữa chuỗi
DK3: Viết hoa chữ cái đầu của mỗi từ trong chuỗi, chữ cái còn lại phải viết thường.
*/
const int ASCII = 32;
std::string special_character_advanced(std::string& name) {
    int index_first = name.length(); 
    bool check_ki_tu_hop_le = true;
    int j = 0;
    for(int i = 0; i < name.length(); i++) {
        check_ki_tu_hop_le = (name[i] >= 'a' && name[i] <= 'z' ||
                            name[i] >= 'A' && name[i] <= 'Z' ||
                            name[i] == ' ');
        if(check_ki_tu_hop_le == true) {
            name[j] = name[i];
            j++;
        }
    }
    name.resize(j);
    return name;
}
std::string delete_space_odd(std::string& name) {
    // Vu@12  H@29oa2ng  D@i%eu
    int index_first = name.length();
    bool check_double_space = true;
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
                check_double_space = true;
            }
        }
    }
    if(j > 0 && name[j - 1] == ' ') {
        j--;
    }
    name.resize(j);

    return name;
}
bool is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}
bool is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}
char to_convert_lowupper(char c) { // chuyển thành chữ thường
    if(is_upper(c)) {
        return c + ASCII;
    }
    return c;
}
char to_convert_isupper(char c) { // chuyển thành chữ hoa
    if(is_lower(c)) {
        return c - ASCII;
    }
    return c;
}
std::string to_low_all_chac(std::string& name) {
    for(int i = 0; i < name.length(); i++) {
        name[i] = to_convert_lowupper(name[i]);
    }
    return name;
}
std::string is_upper_chac_first(std::string& name) {

    name[0] = to_convert_isupper(name[0]); // mặc định 0 luôn luôn là hoa
    for(int i = 1; i < name.length(); i++) {
        
        if(name[i - 1] == ' ') {
            name[i] = to_convert_isupper(name[i]);
        }
    }
    return name;
}
int main() {
    std::string name = "";
    std::cout << "Vui Long Input Name: "; std::getline(std::cin, name);

    std::cout << "Enter: "; 
    // special_character_advanced(name);
    // delete_space_odd(name);
    to_low_all_chac(name);
    is_upper_chac_first(name);
    for(int i = 0; i < name.length(); i++) {
        std::cout << name[i]; 
    }
    std::cout << "\n";
}