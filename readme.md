# 🚀 Contrôle d’un moteur DC avec encodeur via Arduino & Simulink

## 📌 Description

Ce projet illustre le **pilotage d’un moteur à courant continu (DC)** équipé d’un **encodeur incrémental**, en utilisant une carte **Arduino** et un **driver L298N**.  
La commande est développée sous **MATLAB/Simulink**, avec génération automatique du code vers l’Arduino.  

Le système permet :  
- De définir le **sens de rotation** (horaire/anti-horaire).  
- De contrôler la **vitesse du moteur** via un signal PWM.  
- D’acquérir les signaux de l’encodeur afin de mesurer la vitesse et la position.  

---

## 🛠️ Matériel utilisé
- Moteur DC avec réducteur et encodeur incrémental (2 canaux A/B).  
- Driver **L298N**.  
- Carte **Arduino Uno / R4**.  
- Alimentation externe (≈ 12V).  
- Câbles de connexion.  

---

## ⚙️ Fonctionnalités implémentées
- **Commande en boucle ouverte** :  
  - Génération d’un PWM (0–255) appliqué sur la borne **ENA** du L298N.  
  - Sélection du sens de rotation (IN1/IN2).  

- **Acquisition de l’encodeur** :  
  - Lecture des canaux A et B via les interruptions matérielles de l’Arduino (pins 2 et 3).  
  - Possibilité de calculer vitesse et position.  

- **Intégration Simulink** :  
  - Bloc PWM pour piloter la vitesse.  
  - Bloc logique pour le sens de rotation.  
  - Bloc d’acquisition pour l’encodeur.  

---

## 📂 Structure du projet
- `src/` : Codes Arduino générés.  
- `simulink/` : Modèles de simulation et schéma de contrôle.  
- `docs/` : Documentation et schémas.  
- `README.md` : description du projet.  

---

## 🔌 Schéma Simulink
![Schéma Simulink](docs/simulink_model.png)  

### Explication :
1. **Détermination du sens**  
   - `IN1 = 1, IN2 = 0` → rotation horaire (CW).  
   - `IN1 = 0, IN2 = 1` → rotation anti-horaire (CCW).  

2. **Commande de vitesse (PWM)**  
   - Curseur (0–255) → générateur PWM.  
   - Sortie sur la pin **5** de l’Arduino → ENA du L298N.  

3. **Acquisition encodeur**  
   - Pin 2 = canal A.  
   - Pin 3 = canal B.  
   - Mesure vitesse et position.  

---

## 🔧 Câblage Arduino ↔ L298N
- **Pin 9** → IN1  
- **Pin 4** → IN2  
- **Pin 5 (PWM)** → ENA  
- **Pin 2** → Encodeur canal A  
- **Pin 3** → Encodeur canal B  

---

## 🚀 Perspectives
- Implémenter un **PID** en boucle fermée pour réguler la vitesse.  
- Développer un contrôle de **position angulaire**.  
- Comparer les performances entre **boucle ouverte** et **boucle fermée**.  
- Étendre à des lois de commande avancées (commande par retour d’état, adaptative, etc.).  

---

📅 Projet : Contrôle moteur DC via Arduino et Simulink  
