template<typename T, 
        template <typename U> 
            class container
        >
class Type
{
private:
    container<T> c;
public:
    Type(){}
};
