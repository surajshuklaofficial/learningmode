import http from 'http';
import fs from 'fs';
import { Console } from 'console';

const htmlText = fs.readFileSync("index.html", "utf8");
const data = JSON.parse(fs.readFileSync("data.json", "utf8"));

// server callback will only execute when client make a request otherwise it will remain shut even if I make any changes in the code
const server1 = http.createServer((req, res) => {
    console.log("first server is running!");
    let url = req.url.split("/");
    console.log(req.url, req.method);
    console.log(url);

    if ( (req.url.startsWith('/product'))) 
    if ( url[1] === 'products' && url.length > 2) {
        res.setHeader("Content-Type", "text/html"); // without this chrome doesn't support able to understand it as HTML document
        let modified_htmlText = htmlText.replace("**title**",data.products[url[2]].title)
                                        .replace("**price**",data.products[url[2]].price)
                                        .replace("**rating**",data.products[url[2]].rating)
                                        .replace("**url**",data.products[url[2]].thumbnail);
        res.end(modified_htmlText);
        return ;
    }

    switch (req.url) {
        case '/':
            res.end('Welcome to my first server!');
            break;

        case '/data':
            res.end(JSON.stringify(data));
            break;

        // case '/products':
        //     res.end(htmlText);
        //     break;

        default:
            res.end("Take a chill pill! ");
            break;
    }
    
})

const server2 = http.createServer((req, res) => {
    console.log(req.url);
    console.log("Second server is runing!")
    res.end("Welcome to second server!");

});

const port1 = "8080";
const port2 = "8081";
server1.listen(port1);
server2.listen(port2);