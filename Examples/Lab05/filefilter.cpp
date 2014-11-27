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

class FileEmiterCantCreateException: public exception
{
    const char *what() const noexcept override
    {
        return "FileEmiter can't create";
    }
};

class FileReciverCantReadException: public exception
{
    const char *what() const noexcept override
    {
        return "FileReciver can't never read";
    }
};

class FileReciverCantCreateException: public exception
{
    const char *what() const noexcept override
    {
        return "FileReciver can't create";
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
        if(!fin.is_open())
            throw FileEmiterCantCreateException();
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

    double transmit()
    {
        if(!ready)
            throw FileEmiterCantReadException();
        ready = false;
        return value;
    }

    bool mayBroadcast()
    {
        if(!ready)
        {
            char str[256];
            fin.getline(str, 256);
            if(!fin.eof() && regex_match(str, regex("[-+]?([1-9]\\d*|0)(\\.\\d+)?([eE][-+]?\\d+)?")))
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

void FileEmiter::recive(double )
{}

double FileEmiter::transmit() const
{
    return pimpl->transmit();
}

bool FileEmiter::mayBroadcast() const
{
    return pimpl->mayBroadcast();
}

class FileReciver::FileReciverImplementation
{
public:
    // Great VI
    FileReciverImplementation(const char *filename):
        fout(filename)
    {
        if(!fout.is_open())
            throw FileReciverCantCreateException();
    }

    FileReciverImplementation(const FileReciverImplementation &other) = delete;
    FileReciverImplementation &operator=(const FileReciverImplementation &other) = delete;
    FileReciverImplementation(FileReciverImplementation &&other) = delete;
    FileReciverImplementation &operator=(FileReciverImplementation && other) = delete;

    ~FileReciverImplementation()
    {
        fout.close();
    }

    // /Great VI

    void recive(double input)
    {
        fout.precision(15);
        fout << input << endl;
    }

private:
    ofstream fout;
};

FileReciver::FileReciver(const char *filename):
    pimpl(nullptr)
{
    pimpl = new FileReciverImplementation(filename);
}

FileReciver::~FileReciver()
{
    delete pimpl;
    pimpl = nullptr;
}

void FileReciver::recive(double input)
{
    pimpl->recive(input);
}

double FileReciver::transmit() const
{
    throw FileReciverCantReadException();
}

}
