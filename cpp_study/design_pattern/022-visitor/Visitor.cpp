class Element
{
public:    
    virtual void Accept(Visitor* visitor) = 0;
};

class ElementA : public Element
{
public:
    virtual void Accept(Visitor* visitor) override
    {
        visitor->VisitElementA(this);
    }
};

class ElementB : public Element
{
public:
    virtual void Accept(Visitor* visitor) override
    {
        visitor->VisitElementB(this);
    }
};

class Visitor
{
public:
    virtual void VisitElementA(ElementA* elementA) = 0;
    virtual void VisitElementB(ElementB* elementB) = 0;
};

class Visitor1 : public Visitor
{
    virtual void VisitElementA(ElementA* elementA) 
    {
        // func1
    }

    virtual void VisitElementB(ElementB* elementB)
    {
        // func1
    }
};

// ====
class Visitor2 : public Visitor
{
    virtual void VisitElementA(ElementA* elementA) 
    {
        // func2
    }

    virtual void VisitElementB(ElementB* elementB)
    {
        // func2
    }
};

int main()
{
    ElementA ea;
    ElementB eb;

    Visitor1 v1;
    Visitor2 v2;

    ea.Accept(&v1);
    ea.Accept(&v2);
    eb.Accept(&v1);
    eb.Accept(&v2);

    return 0;
}