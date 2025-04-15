# Minitalk

## 📡 Objectif du projet

Le projet Minitalk consiste à créer un système de communication **entre deux processus UNIX** (un serveur et un client) en utilisant uniquement les **signaux UNIX** (`SIGUSR1` et `SIGUSR2`).  
L’objectif est d’envoyer des messages d’un client vers un serveur, **bit par bit**, sans utiliser de sockets ni de pipes.

Ce projet permet de mieux comprendre :
- La gestion des signaux.
- La communication interprocessus (IPC).
- La manipulation binaire.

---

## 🧩 Étapes du projet (Partie Mandatory)

### 1. **Création du serveur**
- Le serveur doit :
  - Afficher son PID au lancement.
  - Recevoir des signaux (`SIGUSR1` et `SIGUSR2`) du client.
  - Reconstituer les bits reçus pour former des caractères.
  - Afficher le message reçu dans le terminal.

### 2. **Création du client**
- Le client doit :
  - Prendre en paramètre le PID du serveur et un message à envoyer.
  - Envoyer chaque caractère du message **bit à bit** au serveur :
    - `SIGUSR1` pour un bit à 0.
    - `SIGUSR2` pour un bit à 1.
  - Terminer le message avec un caractère nul (`'\0'`) pour signaler la fin.

### 3. **Gestion des signaux**
- Utiliser `sigaction()` pour gérer proprement les signaux.
- Assurer une réception stable et fiable, même si les signaux sont envoyés rapidement.

---

## 🛠️ Compilation

```bash
make
