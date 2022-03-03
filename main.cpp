#include <iostream>
#include <string>
#include <fstream>

std::string& shifrator(std::string& str)
{
    for(int i{}; i < str.size(); ++i)
    {
        if(str[i] == 'x' || str[i] == 'X'){str[i] -= 26;}
        if(str[i] == 'y' || str[i] == 'Y'){str[i] -= 26;}
        if(str[i] == 'z' || str[i] == 'Z'){str[i] -= 26;}
        if(str[i] == ' ' || str[i] == ' '){str[i] -= 3;}
        str[i] = str[i] + 3;
    }
    return str;
}

std::string& de_shifrator(std::string& str)
{
    for(int i{}; i < str.size(); ++i)
    {
        if(str[i] == 'a' || str[i] == 'A'){str[i] += 26;}
        if(str[i] == 'b' || str[i] == 'B'){str[i] += 26;}
        if(str[i] == 'c' || str[i] == 'C'){str[i] += 26;}
        if(str[i] == ' ' || str[i] == ' '){str[i] += 3;}
        str[i] = str[i] - 3;
    }
    return str;
}


int main()
{

    std::string normal_path = "normaltext.txt";
    std::string shrift_path = "shrifttext.txt";
    std::fstream fs_normal_path;
    std::fstream fs_shrift_path;

    fs_normal_path.open(normal_path,std::fstream::in | std::fstream::app | std::fstream::out);
    fs_shrift_path.open(shrift_path,std::fstream::in | std::fstream::app | std::fstream::out);

    if(!fs_normal_path.is_open())
    {
        std::cout << "file don't open" << std::endl;
    }
    else
    {
        std::string msg;
        int value{};
        std::cout << "file is open!" << std::endl;
        std::cout << "for write your normal message please enter 1" << std::endl;
        std::cout << "for write your shrift message please enter 3" << std::endl;
        std::cout << "for read your normal message please enter 2" << std::endl;
        std::cout << "for read your normal message please enter 4" << std::endl;
        std::cin >> value;
        std::cin.get();
        if(value == 1)
        {
            std::cout << "PLease write your normal message" << std::endl;
            getline(std::cin, msg);
            fs_normal_path << msg;
            std::string str = shifrator(msg);
            fs_shrift_path << str;
        }

        if(value == 2)
        {
            std::cout << "your normal message: "<<  std::endl;
           while(!fs_normal_path.eof())
           {
               msg = "";
               getline(fs_normal_path, msg);
               std::cout << msg << std::endl;
           }
        }

        if(value == 3)
        {
            std::cout << "PLease write your shrift message" << std::endl;
            getline(std::cin, msg);
            fs_shrift_path << msg;
            std::string str = de_shifrator(msg);
            fs_normal_path << str;
        }

        if(value == 4)
        {
            std::cout << "your shrift message: " << std::endl;
           while(!fs_shrift_path.eof())
           {
               msg = "";
               getline(fs_shrift_path, msg);
               std::cout << msg << std::endl;
           }
        }
    }
    return 0;
}