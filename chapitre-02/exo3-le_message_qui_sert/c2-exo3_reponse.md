# Exercice 3 — Le message qui sert

j’ai pris trois commits du dépôt Nkentseu avec la commande : ``git log --oneline -3``  le resultat etait: 
```` 
PS C:\Users\BEST-COMPUTER\Desktop\nkentseu\Nkentseu> git log --oneline -3
6fb634fc (HEAD -> sorcier, origin/main, origin/HEAD, main) NKCode : le web sort du polissage et devient la phase 14, avec une echeance reelle
860e9d7f Refonte NK3DModeler : a jour avec main, et NKCode signe sur certificat (#85)
c1c815ff CI : les huit epinglages de Jenga passent par JENGA_VERSION (#87)
````

### 1. premier commit: `6fb634fc`
**Message :** `NKCode : le web sort du polissage et devient la phase 14, avec une echeance reelle`

- Dit-il ce qu’il fait ? **Oui.**
- Dit-il pourquoi ? **d'une part** Il parle d’une échéance réelle, mais ne donne pas vraiment la raison.
- Porte-t-il un seul sujet ? **Oui.**

### 2. deuxieme commit: `860e9d7f`
**Message :** `Refonte NK3DModeler : a jour avec main, et NKCode signe sur certificat (#85)`

- Dit-il ce qu’il fait ? **Oui.**
- Dit-il pourquoi ? **Non.**
- Porte-t-il un seul sujet ? **Non.** Il parle à la fois de NK3DModeler et de NKCode.


### 3. troisieme commit: `c1c815ff`
**Message :** `CI : les huit epinglages de Jenga passent par JENGA_VERSION (#87)`

- Dit-il ce qu’il fait ? **Oui.**
- Dit-il pourquoi ? **Non.**
- Porte-t-il un seul sujet ? **Oui.**

## celui qui me parait le plus faible: 
il s'agit du deuxieme commit car il melange deux sujets differents.

**Réécriture :**

`NK3DModeler a jour avec main`

Le sujet concernant NKCode doit être placé dans un autre commit avec son propre message.