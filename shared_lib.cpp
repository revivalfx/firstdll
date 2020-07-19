#include "shared_lib.h"

void pipcommand(string strCmd)
{
    std::array<char, 80> buffer;

    FILE *pipe = popen(strCmd.c_str(), "r");

    if (pipe == NULL)
    {
        std::cerr << "cannot open pipe for reading" << std::endl;
        return;
    }

    int c=0;

    while(fgets(buffer.data(), 80, pipe) != NULL)
    {
        c++;
        std::cout << c << "\t" << buffer.data();
    }

    pclose(pipe);
}

void SaySomething(string str)
{
    std::cout << "I typed:" << str << endl;
}