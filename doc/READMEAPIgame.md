# API des bibliothèques de jeux à créer, spécifications.

## Interface/classe abstraite commune aux jeux et aux libs:

```C++
class IGameApi
{
    virtual int example() = 0;
};
```

### Pour chaque lib contient une classe qui hérite de IGameApi:

```C++
class $(GAME)Api : public IGameApi
{
    virtual int example();
};
```

## Méthodes API Jeu:

```C++
void initGraphApi(IGraphApi *api)
```

    - Initialise l'api graphique pour l'instance du jeux
    - Throw en cas d'erreur

```C++
void launchGame()
```

    - Lance une instance du jeu, ou la relance avec une autre librairie graphique
    - Set un status de fin de jeu à la fin de la loop
    - Throw en cas d'erreur (exemple: si il n'y a pas d'api graphique)

```C++
virtual bindings endGame()
```
    - Return le status de fin du jeu, qui est l'évènement qui a mis fin au jeu
    - Throw en cas d'erreur

---

### Status du fin du jeu:

> Différents types d'evènements de fin possibles pour le jeu, en fonction de ce que doit faire l'arcade après sa fin:

>    - "O" prev graph
>    - "P" next graph
>    - "L" prev game
>    - "M" next game
>    - "R" reset actual game
>    - "EXITALL" quit arcade
>    - "DEL" retour menu