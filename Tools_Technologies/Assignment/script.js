// Random background color
document.getElementById('bg-btn').addEventListener('click', () => {
    const color = '#' + Math.floor(Math.random() * 0xffffff).toString(16).padStart(6, '0');
    document.getElementById('bg-color').style.backgroundColor = color;
});

// Clear the activity log only
document.getElementById('clearActivity').addEventListener('click', () => {
    document.getElementById('activity').innerHTML = '';
});

// Live date: weekday on top, short date below
const today = new Date();
document.getElementById('date').innerHTML = `
    <span class="block text-sm text-slate-500">${today.toLocaleDateString('en-US', { weekday: 'short' })}</span>
    ${today.toLocaleDateString('en-US', { month: 'short', day: 'numeric', year: 'numeric' })}`;

// Task completion — the task name is read from the card's own <h3>
document.querySelectorAll('.task-btn').forEach(btn => {
    btn.addEventListener('click', () => {
        btn.disabled = true;

        const taskCount = document.getElementById('task-count');
        const totalTask = document.getElementById('total-task');
        taskCount.textContent = String(Number(taskCount.textContent) - 1).padStart(2, '0');
        totalTask.textContent = Number(totalTask.textContent) + 1;

        alert('Board updated Successfully');

        const name = btn.closest('.task-card').querySelector('h3').textContent.trim();
        const entry = document.createElement('p');
        entry.textContent = `You have completed the task ${name} at ${new Date().toLocaleTimeString()}.`;
        entry.className = 'bg-[#eef2ff] rounded-xl p-3 text-sm leading-relaxed break-words';
        document.getElementById('activity').appendChild(entry);
    });
});