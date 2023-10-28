#include <iostream>
#include <ifaddrs.h>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
void save(std::string filename,std::string content){
    // std::string content = "This is the new content of the file.";
    // std::string filename = "example.txt"; // 替换为您要写入的文件路径

    std::ofstream file(filename, std::ios::out | std::ios::trunc);

    if (!file) {
        std::cerr << "Failed to open the file." << std::endl;
        // return 1;
        return;
    }

    file << content;

    file.close();

    // cwd
    std::cout << "Saved to macs.txt under current working directory." << std::endl;
    std::cout << "CWD: " << std::endl;
    system("pwd");
}
/**
* 获取到当前的全部mac地址，并组装为一个可被授权的样式
* zsh2401
*/
int main(int argc, char** argv)
{
    struct ifaddrs *addrs;
    getifaddrs(&addrs);
    std::string resultStr = "";
    for (struct ifaddrs *addr = addrs; addr != nullptr; addr = addr->ifa_next) {
        if (addr->ifa_addr && addr->ifa_addr->sa_family == AF_PACKET) {
                std::string interfaceName = addr->ifa_name;
                std::cout << "Interface Name: " << interfaceName << std::endl;
                std::ifstream file("/sys/class/net/" + interfaceName + "/address");

                if (!file) {
                    std::cerr << "Failed to open the file." << std::endl;
                    return 1;
                }

                std::string content((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
                auto s = content;
               
                // content.erase(std::remove(content.begin(), content.end(), '\n'), content.cend());
                if (!s.empty() && s[s.length()-1] == '\n') {
                    s.erase(s.length()-1);
                }
                std::cout << "Mac Address: " << s << std::endl;
                resultStr += (s + ";");
        }
    }

    // std::cout << argv[1] << std::endl;

    resultStr.erase(resultStr.length() - 1);
    freeifaddrs(addrs);

    std::cout << "Final Result " << std::endl << resultStr << std::endl;

    save("./macs.txt",resultStr);


    return 0;
}
