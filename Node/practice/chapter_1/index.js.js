import fs from 'fs';

const t1 = performance.now(); // use to get current time
const txt = fs.readFileSync("index.txt", "utf8"); // to read a file synchronously ( it is never preffered as we don't want to block server for any seconds)
console.log(txt);

// fs.readFile("index.txt", 'utf-8', (err, data) => {
//     console.log(data);
// });

const t2 = performance.now();

console.log(Date.now())
console.log("t1: ", t1);
console.log("t2: ", t2);
console.log("total time taken: " + (t2 - t1));