# Simulation-Particles

Simulation N-corps de particules en C++17 (gravitation, intégration de Störmer-Verlet), développée au fil des labs du cours.

## Commandes rapides

```bash
cmake --workflow --preset debug     # configurer en Debug + compiler (pour déboguer)
cmake --workflow --preset release   # configurer en Release + compiler (optimisé, pour les démos)
cmake --build build                 # recompiler après une modification
ctest --preset debug                # lancer tous les tests (ou --preset release)
./build/demo/demo_solar_system      # démo système solaire
./build/demo/demo_univers           # démo 2^8 particules
cmake --build build --target clean  # nettoyer les binaires
```

## Prérequis

| Outil | Version minimale | Remarque |
|-------|------------------|----------|
| Compilateur C++ | supportant C++17 (g++ ≥ 7, clang ≥ 5) | testé avec g++ 13.3 |
| CMake | 3.16.3 (3.25 pour les presets) | testé avec 3.28.3 |
| make (ou Ninja) | — | générateur utilisé par CMake |
| git | — | requis par `FetchContent` pour télécharger Catch2 |
| gdb | — | uniquement pour le débogage |
| Accès réseau | — | uniquement au premier `cmake` (téléchargement de Catch2 v3.8.1) |

Installation sous Ubuntu / Debian / WSL :

```bash
sudo apt update
sudo apt install build-essential cmake git gdb
```

## Compilation

Le build se fait toujours dans `build/`. Le mode (Debug ou Release) est choisi **à la configuration** : il faut reconfigurer pour en changer, ce qui recompile tout.

### Avec les presets (`CMakePresets.json`, CMake ≥ 3.25)

| Preset | Flags | Usage |
|--------|-------|-------|
| `debug` | `-g`, sans optimisation | débogage avec gdb / VSCode |
| `release` | `-O3 -DNDEBUG` (les `assert` sont désactivés) | démos, mesures de performance |

```bash
cmake --workflow --preset debug   # configure + compile en une commande
cmake --preset debug              # configure seulement
cmake --build --preset debug      # compile seulement
```

### Sans les presets (CMake < 3.25)

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug   # ou Release ; sans option : ni -g ni optimisation
cmake --build build -j$(nproc)
```

### Recompiler après une modification

Une fois configuré, il suffit de recompiler ; le mode Debug/Release reste celui choisi à la configuration :

```bash
cmake --build build                         # tout compiler
cmake --build build --target demo_univers   # une seule cible
cmake --build build --target help           # liste des cibles disponibles
```

### Nettoyage

```bash
cmake --build build --target clean   # supprime les binaires compilés
cmake --build build --clean-first    # nettoie puis recompile
rm -rf build                         # nettoyage complet (configuration + Catch2 téléchargé)
```

Après un `clean`, un simple `cmake --build build` suffit. Après un `rm -rf build`, il faut reconfigurer (`cmake --preset debug`), ce qui télécharge de nouveau Catch2.

## Tests

Les tests utilisent [Catch2](https://github.com/catchorg/Catch2) ; chaque fichier de `test/test_vecteur/` produit un exécutable et un test CTest du même nom.

```bash
ctest --preset debug                              # tous les tests, sortie affichée en cas d'échec
ctest --test-dir build --output-on-failure        # idem sans preset
ctest --test-dir build -R test_vecteur_addition   # un seul test (filtre par nom)
./build/test/test_vecteur_addition                # lancer directement un exécutable de test
./build/test/test_vecteur_addition --break        # s'arrête dans le débogueur au premier échec
```

Ajouter un test : créer un fichier `.cxx` dans `test/test_vecteur/` ; il est détecté automatiquement à la prochaine compilation.

## Démos

```bash
./build/demo/demo_solar_system   # Soleil, Terre, Jupiter et comète de Halley (Störmer-Verlet)
./build/demo/demo_univers        # 2^8 particules aléatoires dans un cube unité
```

La sortie peut être volumineuse ; pour la sauvegarder : `./build/demo/demo_solar_system > solar.txt`.

## Débogage (VSCode)

Prérequis : `gdb`, et les extensions **C/C++** (`ms-vscode.cpptools`) et **CMake Tools** (`ms-vscode.cmake-tools`).

1. Choisir le preset **Debug** dans la barre d'état de CMake Tools (ou `cmake --preset debug`).
2. `Ctrl+Shift+P` → **CMake: Set Launch/Debug Target** → par exemple `demo_univers` ou un test.
3. Poser un point d'arrêt (F9) puis lancer avec **F5** (configuration « Debug target CMake »).

Le dossier `.vscode/` n'est pas versionné ; configuration conseillée :

- `.vscode/tasks.json` : une tâche `cmake debug` qui lance `cmake --workflow --preset debug` ;
- `.vscode/launch.json` : `"program": "${command:cmake.launchTargetPath}"`, `"MIMode": "gdb"`, `"preLaunchTask": "cmake debug"` et la commande gdb `-enable-pretty-printing` (affichage lisible des `std::vector`).

**Ne pas utiliser** le bouton ▷ « Debug C/C++ File » de l'éditeur : il compile uniquement le fichier ouvert, sans `src/` ni la bibliothèque `particules`, d'où des erreurs `undefined reference to Universe::...`.

## Structure du projet

```
.
├── CMakeLists.txt     # configuration principale (C++17, -Wall, Catch2)
├── CMakePresets.json  # presets debug / release
├── include/           # en-têtes (.hxx) : Vecteur, Particle, Universe
├── src/               # implémentations (.cxx) -> bibliothèque statique « particules »
├── test/              # tests unitaires Catch2
│   └── test_vecteur/
├── demo/              # programmes de démonstration
└── spec/              # énoncés des labs (PDF)
```

- **`Vecteur`** : vecteur 3D (`+`, `-`, `+=`, `-=`, multiplication par un scalaire `lambda * v`, `<<`).
- **`Particle`** : position, vitesse, force, masse, identifiant et type.
- **`Universe`** : ensemble de particules ; `stromerVerlet(forces_old, forces_new, dt)` avance d'un pas de temps en calculant les forces gravitationnelles (G = 1) par paires.

Tout nouveau fichier source doit être ajouté dans `src/CMakeLists.txt`, et toute nouvelle démo dans `demo/CMakeLists.txt`.
