# 1-la commande utilisée
## ici J’ai lancer `NKMath` avec la commande :

``` jenga build --project NKMath ```

Le build s’est terminé 

# 2-l'ordre de conrtruction
## L’ordre  affiché par Jenga était :

1. NKPlatform
2. NKCore
3. NKMemory
4. NKContainers
5. NKMath

# 3-Arbre de dependance

### j'ai alors obtenu l'arbre de dependance suivant:
```
                                                                  _________________
                                                                 |                 |
                                                                /|      NKMath     |\
                                                              /  |_________________|  \   
                                                            /       |            |      \
                                                          /         |            |        \
                                                    depend de    depend de    depend de   depend de 
                                                     /              |            |           \
                                            ____________        ________       ______       __________
                                           |            |      |        |     |      |     |          |
                                          /|NKContainers|      |NKMemory|     |NKcore|     |NKPlatform|
                                        /  |____________|\     |________|     |______|     |__________|
                                      /         |          \
                                    /           |            \
                              depend de     depend de      depend de
                                /               |               \
                           ________          ______           __________
                          |        |        |      |         |          |
                          |NKMemory|        |NKCore|         |NKPlatform|
                          |________|        |______|         |__________|
                          /        \
                     depend de   depend de 
                       /              \
                    ______          __________
                   |      |        |          |
                   |NKCore|        |NKPlatform|
                   |______|        |__________|
                       |
                    depend de
                       |
                   __________
                  |          |
                  |NKPlatform| 
                  |__________|
```
# 4-la sortie complete de jenga
Loading workspace...
[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.

Configuration: Debug
Target:        Windows x86_64
Toolchain:     clang-mingw

Build Order (5 projects):
  1. NKPlatform [STATIC_LIB] →
  2. NKCore [STATIC_LIB] (depends: NKPlatform) →
  3. NKMemory [STATIC_LIB] (depends: NKCore, NKPlatform) →
  4. NKContainers [STATIC_LIB] (depends: NKCore, NKMemory, NKPlatform) →
  5. NKMath [STATIC_LIB] (depends: NKContainers, NKCore, NKMemory, NKPlatform)


╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKPlatform                                                       Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 7 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.07s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKCore                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 5 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.09s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMemory                                                         Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 14 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.20s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKContainers                                                     Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 43 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.85s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: NKMath                                                           Kind: STATIC_LIB  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 12 source file(s)
✓ All files up to date

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.34s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED
════════════════════════════════════════════════════════════════════════════════
Projects Built:  5/5
Time:           1.56s
Status:         ✓ SUCCESS
# 5 - Observation

Le module qui a pris le plus de temps à construire est **NKContainers**, avec **0,85 s**.

Je n'aurais pas forcément deviné que ce serait lui, car la commande demandait de construire `NKMath`. Cela montre qu'un projet demandé en dernier n'est pas forcément celui qui prend le plus de temps à construire.


