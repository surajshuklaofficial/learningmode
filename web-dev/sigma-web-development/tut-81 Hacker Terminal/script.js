document.body.style.backgroundColor = "green";

const root = document.getElementById("root");

let process = ["Intializing Hacking", "Reading your Files", "Password files detected", "Sending all passwords and personal files", "Cleaning Up", "✓"]
let processIndex = 0;

let c;
let a = setInterval(() => {
    clearInterval(c);
    if(root.lastChild.lastChild) root.lastChild.lastChild.innerHTML = " ✓"
    root.innerHTML = root.innerHTML + `<p>${process[processIndex]}<span></span></p>`
    c = setInterval(() => {
        let b = root.lastChild.lastChild;
        if (b.innerHTML === "...") b.innerHTML = "";
        b.innerHTML += ".";
    }, 500)
    processIndex = processIndex + 1;
    if (processIndex === process.length) {clearInterval(a); clearInterval(c)};
}, 2000);