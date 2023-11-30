import { exec } from 'child_process';
import os from 'os';
import fs from 'fs';

// 2 
console.log(process.argv);

// 3
console.log(os.arch());
console.log(os.cpus());
console.log(os.platform());
// console.log(os.version());

// 5
/* 
error:  will contain information about whether there was 
        an error running the command (if command runs successfully, error will be null).

stderr: will contain any error messages or diagnostic information produced by 
        the command. If everything goes smoothly, stderr will be empty. 

stdout: will contain the output of the command in string format
*/
exec("dir", (error, stdout, stderr) => {
    if (error) {
        console.log(`error: ${error.message}`);
        return;
    }
    if (stderr) {
        console.log(`stderr: ${stderr}`);
        return;
    }
    fs.writeFile("assign_2_3_5.txt", stdout, (err) => console.log(error));
});
