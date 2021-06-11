# Arcade classe d'erreurs communes

Chacune de librairies devraient throw des erreurs. Les throw sortant de la librairie devraient toujours être une instance de la classe suivante, ou l'instance d'une classe héritant d'elle:

## IArcadeError.hpp:

```C++
#include <exception>
#include <iostream>

namespace arcade
{
    class ArcadeError : virtual public std::exception
    {
    public:
        inline ArcadeError(std::string what, std::string where) : _what(what), _where(where){};
        inline ArcadeError(ArcadeError prevError, std::string where) : _what(prevError.what()), _where(prevError.where() + " in " + where) {};
        virtual ~ArcadeError() throw() {};

        inline std::string where() { return _where; };
        inline std::string what() { return _what; };

    protected:
        std::string _what;
        std::string _where;
    };
}
```

## Fonctionnement:

Deux constructeurs sont disponibles:

### Throw original:

```C++
ArcadeError(std::string what, std::string where);
```

Ce constructeur sera utilisé pour throw à l'origine de l'erreur. Exemple:

```C++
try {
    throw ArcadeError("Erreur simple", "Erreur origine");
}
catch (const ArcadeError &e) {
    std::cout << e.where() << ": " << e.what(); 
}
```

affichera:

>**Erreur origine**: **Erreur simple**

### Throw reconduit:

```C++
ArcadeError(ArcadeError prevError, std::string where);
```

Ce constructeur sera utilisé pour reconduire une erreur déjà existante et préciser sa localisation. Exemple:

```C++
try {
    try {
        throw ArcadeError("Erreur simple", "Erreur origine");
    }
    catch (const ArcadeError &e) {
        std::cout << e.where() << ": " << e.what();
    }
}
catch (const ArcadeError &e) {
    throw ArcadeError(e, "report");
}
```

affichera:

>**Erreur origine** in **report**: **Erreur simple**