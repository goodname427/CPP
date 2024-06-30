#include <string>
#include <map>
#include <iostream>

class Font
{
private:
    std::string key;

public:
    Font(const std::string& key) : key(key) {}
};

class FontFactory
{
private:
    std::map<std::string, Font*> fonts;

public    :
    Font* Get(std::string key)
    {
        auto it = fonts.find(key);

        if (it != fonts.end())
        {
            return it->second;
        }
        else
        {
            Font* font = new Font(key);
            fonts.insert({key, font});
            return font;
        }
    }

};

int main()
{
    FontFactory factory;
    std::cout << factory.Get("Fuck") << std::endl;
    std::cout << factory.Get("Fuck") << std::endl;
    std::cout << factory.Get("Black") << std::endl;
    std::cout << factory.Get("Black") << std::endl;
    return 0;
}

