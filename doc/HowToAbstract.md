Bon comme je sais pas trop écrire de doc en .md, ce fichier sera là temporairement pour juste expliquer comment abstraire les fonctions prenant en type un void *.

## Exemple d'abstraction :
```c++
void CApp::createSprite(void *clutch, std::string filename)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename.c_str());

    _clutch = IMG_LoadTexture(_game->renderer, filename.c_str());
}

void CApp::displaySprite(void *thing)
{
    blit((SDL_Texture *) thing, 100, 100);
}

void CApp::blit(SDL_Texture *texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(_game->renderer, texture, NULL, &dest);
}
```
__CreateSprite__ et __DisplaySprite__	 sont des fonctions communes à l'API permettant de faire de l'abstraction.
La fonction blit peut etre remplacé en interne par n'importe quelle autre fonction permettant la mise en place de la fonctionnalité abstraite.

Ici, on passe des __void *__ aux fonctions car les différentes fonctions de libraries peuvent envoyer des pointeurs, le __void *__ étant le type le plus flexible aux casts, on privilégie l'utilisation de ceux-ci.

La raison pour laquelle le cast se fait à l'intérieur de la fonction est du au fait que l'on doit créer des cast implicites.

En gros :

```c++
void CApp::displaySprite(SDL_Texture *thing)
```

Si l'on met le type directement ici, il faudra cast dans le type voulu sur un niveau supérieure du code (dans le jeu par exemple), alors que ce n'est pas le but.

Puis vint le deuxième problème :
```c++
void CApp::displaySprite(void *thing, int x, int y) {
    SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture((SDL_Texture *)texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(_game->renderer, (SDL_Texture *)texture, NULL, &dest);
}
```
Si l'on passe un __void *__ en type de la fonction, et meme si l'on cast avant, le cast implicite ne se fait pas, et par conséquent, meme en castant
à l'intérieur de la fonction, le type n'est pas bon et le sprite ne s'affiche pas (je précise que j'ai réalisé tout mes tests en SDL2).

