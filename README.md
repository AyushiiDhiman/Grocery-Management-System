# 🛒 Grocery Management System (GMS)

A modular, console-based C project that simulates a departmental store’s inventory and billing system. Built using fundamental concepts of **file handling**, **modular programming**, and **string manipulation**, this project is a perfect demonstration of logic-building and C programming in action.

---

## 📌 Features

- 🔐 **User Authentication** – Secure login with credential validation (`users.txt`)
- 📦 **Inventory Management**
  - Add, display, search, update, and delete grocery items
  - Stock stored using file handling (`items.txt`)
- 🧾 **Billing System**
  - Generate and save itemized bills (`bill.txt`)
  - Real-time total calculation with formatted output
- 📊 **Sales/Stock Reports**
  - Maintain historical purchase & stock update logs
- 📁 **File-based Data Storage**
  - All data persists through file I/O operations

---

## 🧠 Learning Objectives

- Practice **file I/O** in C (fopen, fprintf, fscanf, etc.)
- Work with **structures** and **arrays**
- Understand **function modularity** and separation of concerns
- Build CLI-based applications with real-world use cases

---

## 🛠️ Technologies Used

- **Language**: C (C99 Standard)
- **Platform**: Code::Blocks 
- **Concepts**: File Handling, Functions, Arrays, String Functions

---

## 🗂️ Project Structure
GroceryManagementSystem/
├── main.c # Program entry point and main menu
├── bill.c # Billing logic and invoice generation
├── items.c # Item record handling
├── update.c # Update item records
├── delete.c # Delete items
├── display.c # Display all records
├── search.c # Search items by ID or name
├── menu.c # User interface menus
├── users.txt # Stores login credentials
└── items.txt # Stores item records



