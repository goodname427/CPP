class Stream
{
public:
    virtual char Read(int num) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;
};

class FileStream : public Stream
{
public:
    virtual char Read(int num) override
    {
        // operation...
        return 0;
    }

    virtual void Seek(int position) override
    {
        // operation...
    }

    virtual void Write(char data) override
    {
        // operation...
    }
};

class MemoryStream : public Stream
{
public:
    virtual char Read(int num) override
    {
        // operation...
        return 0;
    }

    virtual void Seek(int position) override
    {
        // operation...
    }

    virtual void Write(char data) override
    {
        // operation...
    }
};

class DecoratorStream : public Stream
{
protected:
    Stream *decoratedStream;

public:
    DecoratorStream(Stream* stream) : decoratedStream(stream) {}
};

class EncryptStream : public DecoratorStream
{
public:
    EncryptStream(Stream *stream) : DecoratorStream(stream) {}

    virtual char Read(int num) override
    {
        // Encrypt operation...
        return decoratedStream->Read(num);
    }

    virtual void Seek(int position) override
    {
        // Encrypt operation...
        decoratedStream->Seek(position);
    }

    virtual void Write(char data) override
    {
        // Encrypt operation...
        decoratedStream->Write(data);
    }
};

class BufferedStream : public DecoratorStream
{
public:
    BufferedStream(Stream *stream) : DecoratorStream(stream) {}

    virtual char Read(int num) override
    {
        // Buffered operation...
        return decoratedStream->Read(num);
    }

    virtual void Seek(int position) override
    {
        // Buffered operation...
        decoratedStream->Seek(position);
    }

    virtual void Write(char data) override
    {
        // Buffered operation...
        decoratedStream->Write(data);
    }
};

int main()
{
    // 文件流
    FileStream *fs = new FileStream();

    // 加密文件流
    EncryptStream *efs = new EncryptStream(fs);
    
    // 缓冲文件流
    BufferedStream *bs = new BufferedStream(fs);
    
    // 缓冲加密文件流
    BufferedStream *befs = new BufferedStream(efs);

    // ...
    return 0;
}
