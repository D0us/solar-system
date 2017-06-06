#ifndef VISITOR_H
#define VISITOR_H

// Predeclaring Classes
class UniverseComposite;
class UniverseComponent;

class Visitable;


class Visitor
{
public:
    Visitor();

        virtual ~Visitor();

        //visist functions for each visitable
        virtual void visit(UniverseComposite* composite) = 0;

        virtual void visit(UniverseComponent* component) = 0;

        virtual void visit(Visitable* body) = 0;

protected:

};

#endif // VISITOR_H
