template <class T>
class shared_ptr
{
private:
    T *px;
    long *pn;

public:
    T &operator*() const
    {
        return *px;
    }

    T *operator->() const
    {
        return px;
    }

    shared_ptr(T *p) : px(p){};
};
