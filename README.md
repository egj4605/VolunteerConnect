# VolunteerConnect 🤝

![VolunteerConnect Logo](./assets/logo.png)

**VolunteerConnect** is a C-based command-line volunteer management system designed to bridge the gap between community volunteers and hosting organizations. It matches volunteer skills and interest areas with active organizational postings and issues targeted notifications.

---

## ✨ Key Features

* **Volunteer Registration & Profiling:** Collects and stores user details, skills, interest areas, and locations using structured C types (`struct`).
* **Event Management:** Enables organizations to register community events with required skill criteria and location parameters.
* **Automated Skill Matching & Notifications:** Cross-references volunteer profiles against active events using `strcmp()` logic to notify users of matching opportunities.
* **Persistent Disk Storage:** Uses C File I/O (`fopen`, `fprintf`, `fscanf`) to save and load data across application restarts (`volunteers.txt`, `events.txt`).

---

## 🛠️ Programming Concepts Used

* **Structures (`struct`):** Organizes entity data for volunteers and events.
* **File Handling:** Implements data persistence to read and write records to disk.
* **Control Flow:** Menu interface built using interactive `switch` control logic and continuous execution loops.
* **String Manipulation:** Utilizes string handling functions (`strcmp`) to evaluate matching conditions.

---

## 🚀 How to Build and Run

1. **Compile the source code using GCC:**
   ```bash
   gcc VolunteerConnect.c -o VolunteerConnect

## 👥 Contributors (CSE 1320 Group Project) <!-- CONTRIBUTORS GO NEAR THE BOTTOM -->
* **Evan Jorge-Munoz** – Initial application architecture, event/volunteer view functions, core CLI interaction.
* **Alaya Bolinski** – File I/O persistence functions, documentation review.
* **Leonardo Quinonez** – Project tracking, testing, and documentation lead.
* **Jonathan Aliwarga** – Struct data design, skill matching logic, team coordination.
