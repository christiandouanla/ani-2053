# exercice 4 — le commit partiel

## 1. création du dépôt

j’ai créé un dépôt Git avec un fichier de travail.

le premier commit est :

```
[master (root-commit) 8d9ead9] ajoutons le fichier de travail
 1 file changed, 7 insertions(+)
 create mode 100644 fichier.txt
```

## 2. séparation des modifications avec `git add -p`

j’ai lancé :

```
git add -p
```

git a d’abord proposé un seul hunk. j’ai utilisé `s` pour le séparer :

```
(1/1) Stage this hunk [y,n,q,a,d,s,e,p,P,?]? s
Split into 3 hunks.
```

le premier hunk contenait la première modification :

```
+premiere modification
```

j’ai donc choisi `y` :

```t
(1/3) Stage this hunk [...]? y
```

le deuxième hunk contenait les lignes entre les deux modifications. je ne l’ai pas ajouté :

```
(2/3) Stage this hunk [...]? n
```

le troisième hunk contenait la deuxième modification. je ne l’ai pas ajouté pour le moment :

```
(3/3) Stage this hunk [...]? n
```

## 3. premier commit

après avoir ajouté seulement la première modification, `git status` affichait :

```
On branch master
Changes to be committed:
      modified:   fichier.txt

Changes not staged for commit:
      modified:   fichier.txt
```

j’ai ensuite créé le premier commit :

```
git commit -m "ajoutons la premiere modification"
```

résultat :

```
[master f609023] ajoutons la premiere modification
 1 file changed, 1 insertion(+)
```

## 4. deuxième commit

j’ai ensuite ajouté la deuxième modification avec :

```
git add -p
```

puis j’ai choisi `y` pour l’ajouter.

`git status` indiquait :

```
On branch master
Changes to be committed:
      modified:   fichier.txt
```

j’ai créé le deuxième commit :

```
git commit -m "ajoutons la deuxieme modification"
```

résultat :

```
[master 76dd8a4] ajoutons la deuxieme modification
 1 file changed, 13 insertions(+), 1 deletion(-)
```

## 5. vérification de l’historique

j’ai utilisé :

```
git log --oneline --graph
```

résultat :

```
* 76dd8a4 (HEAD -> master) ajoutons la deuxieme modification
* f609023 ajoutons la premiere modification
* 8d9ead9 ajoutons le fichier de travail
```

## conclusion

les deux modifications du même fichier ont été séparées en deux commits avec `git add -p`.

le premier commit contient la première modification et le deuxième contient la deuxième modification. cela permet de mieux séparer les changements dans l’historique.