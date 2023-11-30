import express from 'express';
import fs from 'fs';
import morgan from 'morgan';

const data = fs.readFileSync('data.json', 'utf8');
const htmlFile = fs.readFileSync("C:/Users/surajshukla/Desktop/learningmode/Node/pratice/chapter_3/index.html", 'utf8');

// creating a server
const server = express();

// middleware: present at the mid of server logic and coming/going data from client side
// functions of middleware functions:
    // execute any code
    // make changes to the request and the response objects
    // End the request-response cycle: checking country region 
    // call the next middleware in the stack

// thirt-party middleware
server.use(morgan('default'));

//built-in middlewares
server.use(express.json()); // body-parser
// server.use(express.urlencoded());
server.use(express.static("public")); // use to serve static files

// application-level middleware; this is logger middleware 
server.use((req, res, next) => {
    console.log("Query:",req.query);
    console.log("Body:",req.body);
    console.log("Params:",req.params);
    // console.log(req.method, req.ip, req.hostname, new Date(), req.get('User-Agent')); // get is used to get any header
    next();
});

// router level middleware
const auth = (req, res, next) => {
    // const password = req.query.password;

    if (password == 123) {
        // res.send("Authentication successful")
        next();
    } else {
        res.send("Authentication failed");
    }
}

// API - Endpoint ( because endpoint of server - Route
server.get('/product/:id', (req, res) => {        // using params
    console.log("Params:",req.params); 
    res.json({type: 'GET'})
});
server.get('/', auth, (req, res) => {
    res.json({type: 'GET'})
});
server.post('/', (req, res) => {
    res.json({type: 'POST'})
});
server.patch('/', (req, res) => {
    res.json({type: 'PATCH'})
});
server.delete('/', (req, res) => {
    res.json({type: 'DELETE'})
});
server.put('/', (req, res) => {
    res.json({type: 'PUT'})
});

// ways to send data to client
server.get('/demo', (req, res) => 
    // res.sendStatus(500)
    // res.send("hello world!");
    // res.json(data)
    // res.sendFile("C:/Users/surajshukla/Desktop/learningmode/Node/pratice/chapter_3/index.html")
    res.status(505).json(data)
);
const port = 8080;
server.listen(port, () => {                  // this callback invokes while restarting the server (not while making a request)
    console.log('server started'); 
});