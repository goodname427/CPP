#include <iostream>

using namespace std;

class CLS
{
private:
    int *data;

public:
    CLS()
    {
        data = new int[6];
        for (int i = 0; i < 6; i++)
        {
            data[i] = i + 1;
        }
    }

    ~CLS()
    {
        delete[] data;
    }

    int &operator[](string index)
    {
        if (index == "1st")
            return data[0];
        if (index == "2nd")
            return data[1];
        if (index == "3rd")
            return data[2];
        if (index == "4th")
            return data[3];
        if (index == "5th")
            return data[4];
        if (index == "6th")
            return data[5];
        throw exception();
    }
};

int main()
{
    CLS cls;
    try
    {

        cout << cls["1st"] << endl;
        cout << cls["3rd"] << endl;
        cout << cls["6th"] << endl;
        cout << cls["5th"] << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}