#include "filters.h"
#include <fstream>
#include <regex>
#include <cstdlib>

using namespace std;

namespace filter
{

class FileEmiterCantReadException: public exception
{
    const char *what() const noexcept override
    {
        return "FileEmiter isn't ready";
    }
};

class FileEmiterCantCreateException
{
    const char *what() const noexcept override
    {
        return "FileEmiter can't create";
    }
};

class FileEmiter::FileEmiterImplementation
{
public:
    // Great VI
    FileEmiterImplementation(const char *filename):
        fin(filename),
        value(0.0),
        ready(false)
    {
        //TODO if can't open throw
    }

    FileEmiterImplementation(const FileEmiterImplementation &other) = delete;
    FileEmiterImplementation &operator=(const FileEmiterImplementation &other) = delete;
    FileEmiterImplementation(FileEmiterImplementation &&other) = delete;
    FileEmiterImplementation &operator=(FileEmiterImplementation && other) = delete;
    ~FileEmiterImplementation()
    {
        fin.close();
    }
    // /Great VI

    double transmit()const
    {
        if(!ready)
            throw FileEmiterCantReadException();
        ready = false;
        return value;
    }

    bool mayBroadcast()const
    {
        if(!ready)
        {
            char str[256];
            fin.getline(str, 256);
            if(regex_match(str, regex("[-+]?([1-9]\\d*|0)(\\.\\d+)?([eE][-+]?\\d+)?")))
            {
                value = strtod(str, nullptr);
                ready = true;
            }
        }
        return ready;
    }
private:
    ifstream fin;
    double value;
    bool ready;
};

FileEmiter::FileEmiter(const char *filename):
    pimpl(nullptr)
{
    pimpl = new FileEmiterImplementation(filename);
}

FileEmiter::~FileEmiter()
{
    delete pimpl;
    pimpl = nullptr;
}

void FileEmiter::recive(double input)
{}

double FileEmiter::transmit() const
{
    return pimpl->transmit();
}

bool FileEmiter::mayBroadcast() const
{
    return pimpl->mayBroadcast();
}


}
