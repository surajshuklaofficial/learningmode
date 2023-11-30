// Promise
// let getSomething = () => {
//     return new Promise((resolve, reject) => {
//         resolve("some data")
//         reject("some error")
//     })
// }

// getSomething().then((data) => console.log(data)).catch((error) => console.log(error))

// making HTTP request

let todos = (resource) => {
    return new Promise((resolve, reject) => {
        let request = new XMLHttpRequest();

        // console.log(request);
        request.addEventListener('readystatechange', () => {
            // console.log(request, request.readyState);   
            if (request.readyState === 4  && request.status === 200){
                // console.log(JSON.parse(request.responseText)); 
                // callback(undefined, JSON.parse(request.responseText));
                resolve(JSON.parse(request.responseText));
            } else if (request.readyState === 4){
                // console.log("Data could not be fetched")
                // callback('Data could not be fetched', undefined)
                reject('Error in fetching')

            }
        })
    
        // set up the request
        request.open('Get', resource); 
    
        // sending the request
        request.send();
    });
}

todos('data.json').then((data) => console.log(data)).catch((err) => console.log(err));

// chaining of Promises
todos('data.json').then((data) => {
    console.log(data)
todos('data1.json').then((data) => {
    console.log(data)
todos('data2.json').then((data) => {
    console.log(data)
})})}).catch((err) => console.log(err));
