// fetch API

// fetch('data.json').then((response) => {
//     console.log("Promise resolved", response);
//     return response.json(); // resonponse.json() also returns a promise
// }).then((data) => {
//     console.log(data);
// }).catch((err) => {
//     console.log(err, response);
// });

// async await
let getTodos = async () => {
    let response = await fetch('data.json');

    // custom error 
    if (response.status !== 200) {
        throw new Error('Custom error thrown: ' + response.status);
    }

    let data = await response.json();
    console.log(data, response); // json promise is printable while console.log

    let response2 = await fetch('data.json')
    let data2 = await response2.json();
    console.log(data2, response2);

    console.log(data, data2);
    return data;
}

// by default async function always returns a promise
getTodos().then((data) => {
    console.log(data);
}).catch((err) => {
    console.log(err);
})

// use try-catch block instead then and catch event handlers
