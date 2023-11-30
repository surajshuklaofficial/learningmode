import { exec } from 'child_process';
import os from 'os';

console.log(process.argv);

console.log(os.arch());
console.log(os.cpus());
console.log(os.platform());
console.log(os.version());

exec("dir", (error, stdout, stderr) => {
    if (error) {
        console.log(`error: ${error.message}`);
        return;
    }
    if (stderr) {
        console.log(`stderr: ${stderr}`);
        return;
    }
    console.log(`stdout: ${stdout}`);
});
