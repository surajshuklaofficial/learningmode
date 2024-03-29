import http from 'http';

console.log("hello");

// this server will run everytime a request is made from client URL ( but whole code will run when any changes is made in the server code)
const server = http.createServer((req, res) => {
    console.log("server started!");
})

const port = "8080";
server.listen(port);