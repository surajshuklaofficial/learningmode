// AJAX : Asynchronous Javascript

// value state Description
// 0 UNSENT -> Client has been created . open() not called yet
// 1 OPENED -> open() has been called
// 2 HEADERS_RECEIVED -> send() has been called, along with headers
// 3 LOADING -> Downloading; responseText holds partial data.
// 4 DONE -> The operation has completed

// HTTP response status codes
// Informational responses : 100-199
// Successful responses : 200-299
// Redirection messages : 300-399
// Client error responses : 400-499
// Server error responses : 500-599

// making HTTP request

let todos = (resource, callback) => {
    let request = new XMLHttpRequest();

    // console.log(request);
    request.addEventListener('readystatechange', () => {
        // console.log(request, request.readyState);   
        if (request.readyState === 4  && request.status === 200){
            // console.log(JSON.parse(request.responseText)); 
            callback(undefined, JSON.parse(request.responseText));
        } else if (request.readyState === 4){
            // console.log("Data could not be fetched")
            callback('Data could not be fetched', undefined)
        }
    })

    // set up the request
    // request.open('GET', 'https://jsonplaceholder.typicode.com/todos');
    // request.open('Get', 'data.json');
    request.open('Get', resource); 

    // sending the request
    request.send();
}

// 
todos('data1.json', (error, data) =>{
    if (error) {
        console.log(error)
    } else {
        console.log(data)
    }
})

// chain of todos function (callback) => callback hell also pyramid of doom
todos('data.json', (error, data) =>{
    if (error) {
        console.log(error)
    } else {
        console.log(data)
    }
    todos('data1.json', (error, data) =>{
        if (error) {
            console.log(error)
        } else {
            console.log(data)
        }
        todos('data2.json', (error, data) =>{
            if (error) {
                console.log(error)
            } else {
                console.log(data)
            }
        })
    })
})