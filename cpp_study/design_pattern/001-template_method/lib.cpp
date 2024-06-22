class Library
{
public:
    virtual ~Library() {}

    void Run()
    {
        Init();

        while (1)
        {
            int time = GetTime();

            Tick(time);

            if (!ShouldContinue(time))
                break;
        }

        Exit();
    }

protected:
    void Init() {
        // do init
    };
    void Exit()
    {
        // do exit
    }

    int GetTime()
    {
        return 1;
    }

    virtual void Tick(int time) = 0;
    virtual bool ShouldContinue(int time) = 0;
};