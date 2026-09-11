// ============================================================
// CRUD Operations with localStorage for Portfolio
// Manages: Skills and Projects
// Pattern: Same as teacher's tutorial (array + localStorage)
// ============================================================


// ==================== DATA ARRAYS ====================

// Array to store skills (each skill is an object: { name, icon, color })
let skills = [];

// Array to store projects (each project is an object)
let projects = [];

// Tracks which item is being edited (null = creating new)
let editingSkillIndex = null;
let editingProjectIndex = null;


// ==================== DEFAULT DATA ====================
// Pre-seed data so the portfolio isn't empty on first visit

const DEFAULT_SKILLS = [
    { name: "HTML",         icon: "devicon-html5-plain",            color: "#E34F26" },
    { name: "CSS",          icon: "devicon-css3-plain",             color: "#1572B6" },
    { name: "Tailwind CSS", icon: "devicon-tailwindcss-original",   color: "#06B6D4" },
    { name: "JavaScript",   icon: "devicon-javascript-plain",       color: "#F7DF1E" },
    { name: "C",            icon: "devicon-c-plain",                color: "#00599C" },
    { name: "C++",          icon: "devicon-cplusplus-plain",        color: "#00599C" },
    { name: "Java",         icon: "devicon-java-plain",             color: "#00599C" },
    { name: "Node.js",      icon: "devicon-nodejs-plain",           color: "#339933" },
    { name: "Express.js",   icon: "devicon-express-original",       color: "#FFFFFF" },
    { name: "Spring Boot",  icon: "devicon-spring-original",        color: "#6DB33F" },
    { name: "Prisma",       icon: "devicon-prisma-original",        color: "#5A67D8" },
    { name: "PostgreSQL",   icon: "devicon-postgresql-plain",       color: "#4169E1" },
    { name: "MySQL",        icon: "devicon-mysql-plain",            color: "#00758F" },
    { name: "Git",          icon: "devicon-git-plain",              color: "#F05032" },
    { name: "GitHub",       icon: "devicon-github-plain",           color: "#FFFFFF" }
];

const DEFAULT_PROJECTS = [
    {
        title: "Tasmin Desserts - Web App",
        description: "A responsive web platform built to showcase handcrafted desserts and cakes. Features an interactive product menu, responsive layout, and clean UI/UX designed to streamline customer browsing and inquiries.",
        technologies: "HTML, CSS, JS",
        liveUrl: "https://tasmindesserts.github.io/TasminDesserts/",
        githubUrl: "https://github.com/TasminDesserts/TasminDesserts.git",
        image: "Pictures/web1st.png"
    },
    {
        title: "Med-Review - REST API",
        description: "A backend REST API powering a verified review platform for hospitals and doctors — patients must prove a visit before reviewing, ensuring authentic feedback. Secured with JWT authentication and role-based access for patients, doctors, and admins.",
        technologies: "Node.js, Express.js, Prisma, PostgreSQL",
        liveUrl: "",
        githubUrl: "https://github.com/Tofayel5152/CSE_study/tree/main/DBMS/Group_Project_Med-review",
        image: "Pictures/web2nd.png"
    }
];


// ==================== LOAD DATA (READ from localStorage) ====================

function loadSkills() {
    const savedSkills = localStorage.getItem("portfolioSkills");

    if (savedSkills) {
        // Data exists in localStorage — parse and use it
        skills = JSON.parse(savedSkills);
    } else {
        // First visit — seed with default data
        skills = [...DEFAULT_SKILLS];
        saveSkillsToLocalStorage();
    }

    displaySkills();
    displayAdminSkills();
}

function loadProjects() {
    const savedProjects = localStorage.getItem("portfolioProjects");

    if (savedProjects) {
        projects = JSON.parse(savedProjects);
    } else {
        projects = [...DEFAULT_PROJECTS];
        saveProjectsToLocalStorage();
    }

    displayProjects();
    displayAdminProjects();
}


// ==================== SAVE TO LOCALSTORAGE ====================

function saveSkillsToLocalStorage() {
    localStorage.setItem(
        "portfolioSkills",
        JSON.stringify(skills)
    );
}

function saveProjectsToLocalStorage() {
    localStorage.setItem(
        "portfolioProjects",
        JSON.stringify(projects)
    );
}


// ==================== SKILLS CRUD ====================

// CREATE or UPDATE a skill
function saveSkill() {

    const nameInput = document.getElementById("skillNameInput");
    const iconInput = document.getElementById("skillIconInput");
    const colorInput = document.getElementById("skillColorInput");

    const skillName = nameInput.value.trim();
    const skillIcon = iconInput.value.trim();
    const skillColor = colorInput.value.trim();

    // Validation
    if (skillName === "") {
        alert("Please enter a skill name!");
        return;
    }

    // Build the skill object
    const skillObj = {
        name: skillName,
        icon: skillIcon || "fas fa-code",       // default icon if empty
        color: skillColor || "#e2f24d"           // default color if empty
    };

    // UPDATE — if we are editing an existing skill
    if (editingSkillIndex !== null) {

        skills[editingSkillIndex] = skillObj;
        editingSkillIndex = null;

        // Reset button text back to "Add"
        document.getElementById("skillSaveBtn").textContent = "Add Skill";

    }
    // CREATE — push new skill to the array
    else {

        skills.push(skillObj);

    }

    // Save updated array to localStorage
    saveSkillsToLocalStorage();

    // Clear form inputs
    nameInput.value = "";
    iconInput.value = "";
    colorInput.value = "";

    // Re-render both views
    displaySkills();
    displayAdminSkills();
}


// READ / DISPLAY skills on the portfolio page
function displaySkills() {

    const skillsGrid = document.getElementById("skillsGrid");

    // Clear the container
    skillsGrid.innerHTML = "";

    // Loop through skills array and render each one
    for (let index = 0; index < skills.length; index++) {

        let skill = skills[index];

        skillsGrid.innerHTML += `
            <div class="bg-[#161615] rounded-xl p-6 flex flex-col items-center justify-center gap-4 border border-white/10 hover:border-blue-500 transition-colors shadow-sm">
                <i class="${skill.icon} text-5xl" style="color: ${skill.color}"></i>
                <span class="text-slate-200 font-medium">${skill.name}</span>
            </div>
        `;
    }
}


// READ / DISPLAY skills in the admin panel (with Edit & Delete buttons)
function displayAdminSkills() {

    const adminList = document.getElementById("adminSkillList");

    adminList.innerHTML = "";

    for (let index = 0; index < skills.length; index++) {

        let skill = skills[index];

        adminList.innerHTML += `
            <div class="flex items-center justify-between bg-[#161615] rounded-lg px-4 py-3 border border-white/10">
                <div class="flex items-center gap-3">
                    <i class="${skill.icon} text-xl" style="color: ${skill.color}"></i>
                    <span class="text-white text-sm">${skill.name}</span>
                </div>
                <div class="flex gap-2">
                    <button onclick="editSkill(${index})"
                        class="px-3 py-1 rounded bg-blue-500/20 text-blue-400 text-xs hover:bg-blue-500/30 transition-colors cursor-pointer">
                        Edit
                    </button>
                    <button onclick="deleteSkill(${index})"
                        class="px-3 py-1 rounded bg-red-500/20 text-red-400 text-xs hover:bg-red-500/30 transition-colors cursor-pointer">
                        Delete
                    </button>
                </div>
            </div>
        `;
    }
}


// UPDATE — load skill data into the form for editing
function editSkill(index) {

    document.getElementById("skillNameInput").value = skills[index].name;
    document.getElementById("skillIconInput").value = skills[index].icon;
    document.getElementById("skillColorInput").value = skills[index].color;

    // Set the editing index so saveSkill() knows to update
    editingSkillIndex = index;

    // Change button text to indicate editing mode
    document.getElementById("skillSaveBtn").textContent = "Update Skill";
}


// DELETE a skill
function deleteSkill(index) {

    // Remove 1 item at the given index
    skills.splice(index, 1);

    // Save updated array to localStorage
    saveSkillsToLocalStorage();

    // Re-render
    displaySkills();
    displayAdminSkills();
}


// ==================== PROJECTS CRUD ====================

// CREATE or UPDATE a project
function saveProject() {

    const titleInput = document.getElementById("projectTitleInput");
    const descInput = document.getElementById("projectDescInput");
    const techInput = document.getElementById("projectTechInput");
    const liveInput = document.getElementById("projectLiveInput");
    const githubInput = document.getElementById("projectGithubInput");
    const imageInput = document.getElementById("projectImageInput");

    const title = titleInput.value.trim();
    const description = descInput.value.trim();
    const technologies = techInput.value.trim();
    const liveUrl = liveInput.value.trim();
    const githubUrl = githubInput.value.trim();
    const image = imageInput.value.trim();

    // Validation
    if (title === "") {
        alert("Please enter a project title!");
        return;
    }

    if (description === "") {
        alert("Please enter a project description!");
        return;
    }

    // Build the project object
    const projectObj = {
        title: title,
        description: description,
        technologies: technologies,
        liveUrl: liveUrl,
        githubUrl: githubUrl,
        image: image
    };

    // UPDATE
    if (editingProjectIndex !== null) {

        projects[editingProjectIndex] = projectObj;
        editingProjectIndex = null;

        document.getElementById("projectSaveBtn").textContent = "Add Project";

    }
    // CREATE
    else {

        projects.push(projectObj);

    }

    // Save to localStorage
    saveProjectsToLocalStorage();

    // Clear form
    titleInput.value = "";
    descInput.value = "";
    techInput.value = "";
    liveInput.value = "";
    githubInput.value = "";
    imageInput.value = "";

    // Re-render
    displayProjects();
    displayAdminProjects();
}


// READ / DISPLAY projects on the portfolio page
function displayProjects() {

    const projectsList = document.getElementById("projectsList");

    projectsList.innerHTML = "";

    for (let index = 0; index < projects.length; index++) {

        let project = projects[index];

        // Build technology tags
        let techTags = "";
        if (project.technologies) {
            const techArray = project.technologies.split(",");
            for (let i = 0; i < techArray.length; i++) {
                techTags += `<span class="px-3 py-1 rounded-full bg-[#0b0e1a] text-xs font-mono text-[#e2f24d] border border-white/5">${techArray[i].trim()}</span>`;
            }
        }

        // Build live site button (only if URL exists)
        let liveButton = "";
        if (project.liveUrl) {
            liveButton = `
                <a href="${project.liveUrl}" target="_blank"
                    class="px-6 py-3 bg-[#161615] text-white rounded-full font-bold hover:scale-105 transition-transform">
                    View Live Site
                </a>`;
        }

        // Build image section
        let imageSection = "";
        if (project.image) {
            imageSection = `<img src="${project.image}" alt="${project.title}" class="w-full h-full object-cover" loading="lazy" />`;
        }

        // Build GitHub link
        let githubLink = "";
        if (project.githubUrl) {
            githubLink = `
                <a href="${project.githubUrl}" target="_blank"
                    class="text-white hover:text-[#e2f24d] transition-colors">
                    <i class="fab fa-github text-xl"></i> Source Code
                </a>`;
        }

        projectsList.innerHTML += `
            <div class="bg-[#161615] rounded-3xl overflow-hidden border border-white/10 group mb-8">
                <div class="grid md:grid-cols-2">
                    <div class="h-64 md:h-full bg-[#0b0e1a] relative rounded-3xl overflow-hidden">
                        ${imageSection}
                        <div class="absolute inset-0 flex items-center justify-center text-[#e2f24d]/20">
                            <i class="fas fa-image text-4xl sm:text-5xl md:text-6xl"></i>
                        </div>
                        ${liveButton ? `
                        <div class="absolute inset-0 bg-[#e2f24d]/90 opacity-0 group-hover:opacity-100 transition-opacity duration-300 flex items-center justify-center backdrop-blur-sm">
                            ${liveButton}
                        </div>` : ""}
                    </div>
                    <div class="p-8 md:p-12 flex flex-col justify-center gap-6">
                        <div class="flex flex-wrap gap-2">
                            ${techTags}
                        </div>
                        <h3 class="text-3xl font-bold">${project.title}</h3>
                        <p class="text-white/70 leading-relaxed">${project.description}</p>
                        <div class="flex items-center gap-4 pt-4">
                            ${githubLink}
                        </div>
                    </div>
                </div>
            </div>
        `;
    }
}


// READ / DISPLAY projects in the admin panel (with Edit & Delete buttons)
function displayAdminProjects() {

    const adminList = document.getElementById("adminProjectList");

    adminList.innerHTML = "";

    for (let index = 0; index < projects.length; index++) {

        let project = projects[index];

        adminList.innerHTML += `
            <div class="flex items-center justify-between bg-[#161615] rounded-lg px-4 py-3 border border-white/10">
                <div class="flex-1 min-w-0">
                    <span class="text-white text-sm font-medium truncate block">${project.title}</span>
                    <span class="text-white/40 text-xs truncate block">${project.technologies}</span>
                </div>
                <div class="flex gap-2 ml-3">
                    <button onclick="editProject(${index})"
                        class="px-3 py-1 rounded bg-blue-500/20 text-blue-400 text-xs hover:bg-blue-500/30 transition-colors cursor-pointer">
                        Edit
                    </button>
                    <button onclick="deleteProject(${index})"
                        class="px-3 py-1 rounded bg-red-500/20 text-red-400 text-xs hover:bg-red-500/30 transition-colors cursor-pointer">
                        Delete
                    </button>
                </div>
            </div>
        `;
    }
}


// UPDATE — load project data into the form for editing
function editProject(index) {

    document.getElementById("projectTitleInput").value = projects[index].title;
    document.getElementById("projectDescInput").value = projects[index].description;
    document.getElementById("projectTechInput").value = projects[index].technologies;
    document.getElementById("projectLiveInput").value = projects[index].liveUrl;
    document.getElementById("projectGithubInput").value = projects[index].githubUrl;
    document.getElementById("projectImageInput").value = projects[index].image;

    editingProjectIndex = index;

    document.getElementById("projectSaveBtn").textContent = "Update Project";
}


// DELETE a project
function deleteProject(index) {

    projects.splice(index, 1);

    saveProjectsToLocalStorage();

    displayProjects();
    displayAdminProjects();
}


// ==================== ADMIN PANEL TOGGLE ====================

function toggleAdminPanel() {

    const panel = document.getElementById("adminPanel");

    if (panel.classList.contains("hidden")) {
        panel.classList.remove("hidden");
    } else {
        panel.classList.add("hidden");

        // Reset editing states when closing
        editingSkillIndex = null;
        editingProjectIndex = null;
        document.getElementById("skillSaveBtn").textContent = "Add Skill";
        document.getElementById("projectSaveBtn").textContent = "Add Project";
    }
}


// ==================== START APPLICATION ====================
// Load all data when the page loads

loadSkills();
loadProjects();
