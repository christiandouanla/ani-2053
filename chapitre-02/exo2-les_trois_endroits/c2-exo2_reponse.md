# Exercice 2 — Les trois endroits

Dans cet exercice, j'ai modifié un fichier et affiché `git status` après chaque étape afin d'observer les changements.

## 1. Après la modification

```
[DBG]: PS C:\Users\BEST-COMPUTER\Desktop\git-exo2>> git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
      modified:   fichier.txt

no changes added to commit (use "git add" and/or "git commit -a")
[DBG]: PS C:\Users\BEST-COMPUTER\Desktop\git-exo2>>
```

Le fichier `fichier.txt` est modifié, mais la modification n'est pas encore dans l'index. Elle se trouve donc dans le **Working Tree**.

## 2. Après `git add`

```
[DBG]: PS C:\Users\BEST-COMPUTER\Desktop\git-exo2>> git add fichier.txt
[DBG]: PS C:\Users\BEST-COMPUTER\Desktop\git-exo2>> git status
On branch master
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
      modified:   fichier.txt

[DBG]: PS C:\Users\BEST-COMPUTER\Desktop\git-exo2>>
```

Après `git add`, la modification passe dans **l'Index** et elle est prête à être commitée.

## 3. Après `git commit`

```
[DBG]: PS C:\Users\BEST-COMPUTER\Desktop\git-exo2>> git commit -m "Modifie le fichier"
[master e3d5c3e] Modifie le fichier
 1 file changed, 1 insertion(+), 1 deletion(-)
[DBG]: PS C:\Users\BEST-COMPUTER\Desktop\git-exo2>> git status
On branch master
nothing to commit, working tree clean
[DBG]: PS C:\Users\BEST-COMPUTER\Desktop\git-exo2>>
```

Après le `commit`, la modification est enregistrée dans le Repository
## Ce qui change entre les trois sorties

j'ai observer le passage de la modification entre les trois endroits de Git :

```
Working Tree - Index  - Repository
```

- Après la modification : le fichier est dans le **Working Tree**.
- Après `git add` : la modification est dans **l'Index**.
- Après `git commit` : la modification est enregistrée dans le **Repository**.
