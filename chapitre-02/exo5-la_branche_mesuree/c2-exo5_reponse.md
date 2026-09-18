# Exercice 5 — La branche mesurée

## Création de la branche

j’ai créé une branche appelée `mesure` :

```
git branch mesure
git switch mesure
```

sortie obtenue :

```
Switched to branch 'mesure'
```

## Première mesure

avant de faire les trois commits, j’ai mesuré la taille du dépôt :

```
(Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum
```

sortie obtenue :

```
28179
```

la taille de départ est donc de **28 179 octets**.

## Premier commit

j’ai ajouté la première modification puis créé le premier commit :

```
git add fichier.txt
git commit -m "ajoutons la premiere modification"
```

sortie obtenue :

```
[mesure 7ebcab6] ajoutons la premiere modification
 1 file changed, 1 insertion(+)
```

## Deuxième commit

j’ai ajouté la deuxième modification puis créé le deuxième commit :

```
git add fichier.txt
git commit -m "ajoutons la deuxieme modification"
```

sortie obtenue :

```
[mesure e21b0b1] ajoutons la deuxieme modification
 1 file changed, 1 insertion(+)
```

## Troisième commit

j’ai ajouté la troisième modification puis créé le troisième commit :

```
git add fichier.txt
git commit -m "ajoutons la troisieme modification"
```

sortie obtenue :

```
[mesure 97bfa79] ajoutons la troisieme modification
 1 file changed, 1 insertion(+)
```

## Deuxième mesure

après les trois commits, j’ai mesuré à nouveau la taille du dépôt avec la même commande :

```
(Get-ChildItem .git -Recurse -File | Measure-Object Length -Sum).Sum
```

Sortie obtenue :

```
30530
```

La taille finale est donc de **30 530 octets**.

La différence est :

```
30530 - 28179 = 2351 octets
```

Le dépôt a donc gagné **2 351 octets** sur le disque.

## Historique

J’ai vérifié l’historique avec :

```
git log --oneline --graph
```

Sortie obtenue :

```
* 97bfa79 (HEAD -> mesure) ajoutons la troisieme modification
* e21b0b1 ajoutons la deuxieme modification
* 7ebcab6 ajoutons la premiere modification
* 7a62b74 (master) ajoutons le fichier de travail
```

## Explication

La branche `mesure` contient les trois nouveaux commits.

La taille du dépôt augmente après les commits, car Git doit enregistrer les informations necessaires pour les differentes modifications du fichier


La taille du dossier `.git` est passée de **28 179 octets à 30 530 octets**, soit une augmentation de **2 351 octets**.