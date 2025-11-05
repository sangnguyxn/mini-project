#include <iostream>
#include <string>
/*
Điều kiện để tên là chuẩn hoá
Dk1 : tên chỉ bao gồm chữ cái và khoảng trắng
Dk2 : khoảng trắng không đứng đầu hoặc đứng cuối, giữa các chuỗi chỉ có tối đa 1 khoảng trắng
Dk2 : Chũ cái đầu của mỗi chuỗi phải là chữ cái viết hoa
*/
bool ki_tu_thuong(char c) {
    if(!(c >= 'a' && c <= 'z')) {
        return false;
    }
    return true;
} 
bool ki_tu_hoa(char c) {
    if(!(c >= 'A' && c <= 'Z')) {
        return false;
    }
    return true;
} 

bool dieu_kien_1(std::string name) {

    char name_check;

    for(int i = 0; i < name.length(); i++) {
        name_check = name[i];
        if(!((name_check >= 'a' && name_check <= 'z') || 
            (name_check >= 'A' && name_check <= 'Z') || 
            (name_check == ' '))) 
        {
            return false;
        } 
    }
    return true;
}
bool dieu_kien_2(std::string name) {
   
    if(name[0] == ' ') {
        return false;
    }
    if(name[name.length() - 1] == ' ') {
        return false;
    }
    for(int i = 1; i < name.length(); i++) {
        if(name[i] == ' ' && name[i-1] == ' ') {
            return false;
        }
    }
    return true;
}
bool dieu_kien_3(std::string name) {
    // Nguyen Nhat Sang
    bool ki_tu_dau = true;
    char c;
    for(int i = 0; i < name.length(); i++) {
        c = name[i];
        if(ki_tu_thuong(c) || ki_tu_hoa(c)) { // phải kí tự không bỏ qua ' '

            if(ki_tu_dau) {
                if(ki_tu_thuong(c)) {
                    return false;
                }
                ki_tu_dau = false;
            } else {
                if(ki_tu_hoa(c)) {
                    return false;
                }
            }

            ki_tu_dau = false;

        } else if(c == ' ') {
            ki_tu_dau = true;
        }
         
    }
    return true;
}
bool program_1(std::string name) {
    if( !dieu_kien_1(name) || !dieu_kien_2(name) || !dieu_kien_3(name) ) {
        return false;
    }
    return true;
}

int main() {
    std::string name = "";
    std::cout << "Vui Long Input Name: ";
    std::getline(std::cin, name);
    // Program_1 kiem tra chuan hoa ten
    
    std::cout << "ket Qua kiem tra: " << (dieu_kien_3(name) ? "TRUE" : "FALSE"); 
    

    //(program_1(name) ? "TRUE" : "FALSE")
    
}