#include <iostream>
#include "pch.h"

std::fstream logFile; //handler for log file

void openLog(std::string fileName)
{
    logFile.open(fileName.c_str(), std::ios_base::app);
    if (!logFile.good() == true)
    {
        std::cout << "Cannot open log file " << "log.txt" << std::endl;
    }
    saveLog("Log file opened");
}

void closeLog(void)
{
    saveLog("Log file closed");
    logFile.close();
}

void saveLog(std::string msg)
{
    std::string ss;
    time_t currentTime = time(NULL);
    std::string txttime = (std::string)asctime(localtime(&currentTime));
    txttime = txttime.substr(0, txttime.length() - 1);
    ss = (std::string)"T: " + txttime + " M: " + msg + "\n";
    logFile << ss.c_str();
    logFile.flush();
    std::cout << ss.c_str();
    std::cout.flush();
}
struct berResults
{
    double tot; //total number of bits
    double err; //error bits (different bits)
    float ber;  //ber calc result
    clock_t t1; //calc start time
    clock_t t2; //calc stop time
};

std::fstream logFile;
uint8_t hammingDistance(uint8_t n1, uint8_t n2);
void createFile1(const std::string name, const int count, const char value);
berResults calculateBer(std::string fpath1, std::string fpath2);
void printResult(berResults results);

int main(int argc, char * argv[])
{
        return 0;
}
uint8_t hammingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2;
    uint8_t setBits = 0;
    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }
    return setBits;
}

void createFile1(const std::string name, const int count, const char value)
{
    std::fstream f;
    f.open(name.c_str(), std::ios::binary | std::ios::out);
    for (int i = 0; i < count; i++)
    {
        f.write((char*)&value,1);
    }
    f.close();
}
