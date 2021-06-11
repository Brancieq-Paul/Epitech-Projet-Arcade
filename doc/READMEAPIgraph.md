# API des bibliothèques graphiques à créer, spécifications.

## Interface/classe abstraite commune aux jeux et aux libs:

```C++
class IGraphApi
{
    virtual int example() = 0;
};
```

Pour chaque lib contient une classe qui hérite de **IGraphApi**:

```C++
class $(LIB)Api : public IGraphApi
{
    virtual int example();
};
```

**IMPORTANT:**

>Toutes les valeurs de taille auront pour unité de mesure le pixel, même pour le ncurse

## Méthodes API Graphique:

---

### Window

---
```C++
myWindow_t *initWindow(int height, int width, std::string name)
```

    - Remplis une structure myWindow_t avec les les informations d'une fenêtre et la return
    - Throw une erreur en cas de problème

---

```C++
void destroyWindow(myWindow_t *window)
```

    - Clear et refresh l'affichage de la fenêtre
    - Throw une erreur en cas de problème

---

```C++
void destroyWindow(myWindow_t *window)
```
    - Détruit la window
    - Throw en cas d'erreur

---

### Sprite

---

```C++
void *createSprite(std::string file, myWindow_t *window)
```

    - Crée un sprite affichable associé à un nom
        (Ex: pour file = src/test, deux sources seront présentes: src/test.jpg et src/test**.txt**)
    - Return un void * qui doit être placé dans une structure mySprite du jeu
    - Throw en cas d'erreur (ex: si le sprite n'existe pas)

---

```C++
void displaySprite(mySprite *entity, myWindow_t *window)
```

    - Display le sprite donné, en prenant les coodonnées contenues dans entity
    - Throw en cas d'erreur critique (ex: si le sprite n'existe pas)

---

```C++
void destroySprite(mySprite *entity)
```

    - Détruit un sprite donné (mais pas l'entité qui le contient)
    - Throw en cas d'erreur critique (ex: si le sprite n'existe pas)

---

### Audio

---

```C++
void *createAudio(std::string file)
```

    - Crée un son et le return en void *
    - Throw en cas d'erreur critique (ex: si le son existe déjà)
---

```C++
void playAudio(void *audio)
```

    - Joue un son
    - Throw en cas d'erreur critique (ex: si le son n'existe pas)

---

```C++
void stopAudio(void *audio)
```

    - Stop un son
    - Throw en cas d'erreur critique (ex: si le son n'existe pas)

---

```C++
void destroyAudio(void *audio)
```

    - Détruis un son
    - Throw en cas d'erreur critique (ex: si le son n'existe pas)

---

### Events

---

>Les valeurs possibles pour les évènements sont les suivantes:

```C++
enum bindings {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    EXIT_ALL,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    DEL,
    SPACE,
    UNKNOWN
};
```

---

```C++
bindings pollEvents(myWindow_t *win)
```

    - Retourne l'évènement en cours. UNKNOWN si aucun évènement est en cours
    - Throw en cas d'erreur

---
### Liste des évènements à gérer:
---
1. Switchs arcade:
>    - "o" prec graph
>    - "p" next graph
>    - "l" prev game
>    - "m" next game
>    - "echap" quit arcade
>    - "back" retour menu


2. Gameplay:
>    - Flèches directionelles:
>        * "right"
>        * "left"
>        * "down"
>        * "up"
>    - Entrer: "enter"
>    - Espace: "space"

### Fenêtre:
    - Fermeture: "Closed"

### Format des sprites:

>Les sprites doivent être fournis sous au moins deux formats: format image (**jpg** ou **png**) et format texte (**.txt**).

>Le format du fichier **.txt** doit être comme suit:

- Le premier caractère en première ligne est le caractère représentant le fond vide.
- La deuxième ligné décrit les dimensions du sprite en caractère


**Exemple.txt**

.

92x7

....................U...........................UUUUUUUUUU......U........................................
....................U...........................U.....................U......U........................................
....................U...........................U.....................U......U........................................
....................U...........................U.....................U......U........................................
....................U...........................U.....................U......U........................................
....................U...........................U.....................U......U........................................
....................UUUUUUUUU......UUUUUUUUUU......UUUUUUUUUU.................