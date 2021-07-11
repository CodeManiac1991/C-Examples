#include <iostream>
using std::cout;

class Base
{
public:
    Base(){
        cout<<"\nConstructor Base\n";
    };
    ~Base(){
        cout<<"Destructor Base\n\n";
    };
    void PUB_Method(){
        cout<<"PUB_Method\n";
    };

    int m_PUBvalue = 0;
private:
    void PRV_Method(){
        cout<<"PRV_Method\n";
    };

    int m_PRVvalue = 1;
protected:
    void PRT_Method(){
        cout<<"PRT_Method\n";
    };

    int m_PRTvalue = 2;
};


class Inhetitor_public : public Base
{
public:
    Inhetitor_public(){
        cout<<"\tConstructor Inhetitor public\n";
    };
    ~Inhetitor_public(){
        cout<<"\tDestructor Inhetitor public\n";
    };
};

class Inhetitor_protected : protected Base
{
public:
    Inhetitor_protected(){
        cout<<"\tConstructor Inhetitor protected\n";
    };
    ~Inhetitor_protected(){
        cout<<"\tDestructor Inhetitor protected\n";
    };
    void getPublic(){
        PUB_Method();
    }
    void getProtected(){
        PRT_Method();
    }

};

class Inhetitor_private : private Base
{
public:
    Inhetitor_private(){
        cout<<"\tConstructor Inhetitor private\n";
    };
    ~Inhetitor_private(){
        cout<<"\tDestructor Inhetitor private\n";
    };
    void getPublic(){
        m_PUBvalue = 2;
        PUB_Method(); // почему все ок????!!! Он же из Base и стал уже приватным??
    }
    void getProtected(){
        m_PRTvalue = 3;
        PRT_Method();
    }
};

class GrandSon_protected: public Inhetitor_protected{
public:
    GrandSon_protected(){
        cout<<"\t\tConstructor GrandSon private\n";
        PUB_Method();
        PRT_Method();
    }
    ~GrandSon_protected(){
        cout<<"\t\tDestructor GrandSon private\n";
    }
};

class GrandSon_private: public Inhetitor_private{
public:
    GrandSon_private(){
        cout<<"\t\tConstructor GrandSon private\n";
        //PUB_Method(); // Не получается вызвать приватные методы уже inherior_private
        //PRT_Method(); // Не получается вызвать приватные методы уже inherior_private
    }
    ~GrandSon_private(){
        cout<<"\t\tDestructor GrandSon private\n";
    }
};


class Incest: public GrandSon_protected, public GrandSon_private
{
public:
    Incest(){
        cout<<"\t\t\t\t\tConstructor Incest\n";

        //Здесь мы получили так называемую "алмазную проблему"
        /*
            Исправить ее можно если наследования от Base до Inhetitor_protected
            и от Base до Inhetitor_private будут помечены как virtual
            (например, class Inhetitor_2: virtual public Base
                     и class Inhetitor_2: virtual public Base),
            C++ создаст только один объект Base, и использование его членов будет работать правильно.
            Но мы не будем этого делать, чтобы не запутывать ранее продемострированные проблемы
        */
        //PUB_Method();
        //PRT_Method();
    }
    ~Incest(){
        cout<<"\t\t\t\t\tDestructor Incest\n";
    }
};
