# Exercice 1 — Le dépôt d'essai

## Création du dépôt

J'ai commencé par créer un dépôt Git vide avec la commande :

```
git init
```

Le dépôt a ensuite été utilisé pour crée les différents fichiers avec Git.

## Les trois commits

J'ai créé trois fichiers et je les ai ajoutés dans trois commits différents.

### Premier commit

Le premier fichier a été ajouté et validé avec un premier commit :

```
563a7cd Ajoute le premier fichier
```

### Deuxième commit

J'ai ensuite créé le deuxième fichier et réalisé un deuxième commit :

```
2c2d871 Ajoute le deuxieme fichier
```

### Troisième commit

Enfin, j'ai créé le troisième fichier et réalisé le troisième commit :

```
fdc49e2 Ajoute le troisieme fichier
```

## Historique

Pour afficher les commits sur une seule ligne, j'ai utilisé :

```
git log --oneline
```

le résultat etait :

```
fdc49e2 (HEAD -> master) Ajoute le troisieme fichier
2c2d871 Ajoute le deuxieme fichier
563a7cd Ajoute le premier fichier
```

Cette commande permet de voir rapidement les trois commits et leur ordre.

## Graphe

Pour afficher le graphe des commits, j'ai utilisé :

```
git log --oneline --graph
```

le résultat etait :

```
* fdc49e2 (HEAD -> master) Ajoute le troisieme fichier
* 2c2d871 Ajoute le deuxieme fichier
* 563a7cd Ajoute le premier fichier
```

Le graphe montre que les trois commits se suivent dans une même branche.

## Conclusion

Cet exercice m'a permis crée un dépôt Git, d'ajouter des fichier avec `git add`, de créé des commit avec `git commit` et d'afficher l'historique avec `git log`.