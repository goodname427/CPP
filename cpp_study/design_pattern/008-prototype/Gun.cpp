#include "string"
#include "iostream"
using namespace std;

class Projectile
{
public:
    virtual Projectile* Clone() = 0;
    virtual void Shoot() = 0;
};

class Projectile1 : public Projectile
{
    virtual Projectile* Clone() override
    {
        return new Projectile1(*this);
    }

    virtual void Shoot() override
    {
        cout << "Shoot Projectile1" << endl;
    }
};

class Projectile2 : public Projectile
{
    virtual Projectile* Clone() override
    {
        return new Projectile2(*this);
    }

    virtual void Shoot() override
    {
        cout << "Shoot Projectile2" << endl;
    }
};

class Gun
{
public:
    Projectile* UsingProjectile;

    void Shoot()
    {
        Projectile* projectile = UsingProjectile->Clone();
        projectile->Shoot();
        delete projectile;
    }
};

int main()
{
    Gun gun;
    Projectile* projectile1 = new Projectile1();
    Projectile* projectile2 = new Projectile2();

    // 设置子弹1
    gun.UsingProjectile = projectile1;
    gun.Shoot();

    // 切换子弹2
    gun.UsingProjectile = projectile2;
    gun.Shoot();

    delete projectile1;
    delete projectile2;
    return 0;
}
