# 🗂️ DevBoard — Task Management Dashboard

A task management dashboard where you can complete assigned tasks, track them in a live activity log, and read a short DOM question–answer blog. Built as a **JavaScript DOM assignment** inside the **CSE Study** repository.

[![Live Demo](https://img.shields.io/badge/Live-Demo-brightgreen?style=for-the-badge&logo=github)](https://tofayel5152.github.io/CSE_study/Tools_Technologies/Assignment/)

---

### 🌐 Live Preview
👉 **[https://tofayel5152.github.io/CSE_study/Tools_Technologies/Assignment/](https://tofayel5152.github.io/CSE_study/Tools_Technologies/Assignment/)**

---

## ✨ Features
- **Task Cards:** Six task cards with company name, title, description, and deadline. Clicking **Completed** disables the button and marks the task done.
- **Live Counters:** The assigned task count goes down and the total completed count goes up with every completed task.
- **Activity Log:** Each completed task is logged with its name and the exact time it was finished.
- **Clear History:** Empties the activity log only — completed tasks and counters stay as they are.
- **Random Background:** The colour button paints the page a new random background colour on every click.
- **Live Date:** The current weekday and date are generated with the `Date` object on page load.
- **Blogs Page:** A separate page answering five common DOM questions, reachable from the navbar or the Discover card.
- **Responsive Design:** Cards flow from one to three columns and the activity log stacks below the board on smaller screens.

## 🛠️ Tech Stack
- **HTML5** — Semantic page structure
- **Tailwind CSS** — Utility-first styling and responsiveness (browser CDN build)
- **JavaScript** — DOM selection, event handling, and dynamic element creation
- **Font Awesome & Devicon** — Icons

## 📁 Project Structure
```
Assignment/
├── index.html      # Dashboard page
├── blogs.html      # DOM question & answer page
├── script.js       # All interactivity
└── Pictures/       # Logo and icon images
```

## 🚀 How to Run Locally
1. **Clone the repository:**
   ```bash
   git clone https://github.com/Tofayel5152/CSE_study.git
   ```

2. **Navigate to the directory:**
   ```bash
   cd CSE_study/Tools_Technologies/Assignment
   ```

3. **Run the project:** <br>
   Open **index.html** directly in any web browser or use VS Code's Live Server extension.

> **Note:** Keep the `Pictures/` folder next to `index.html` and `blogs.html` — the image paths are relative and case-sensitive on GitHub Pages.