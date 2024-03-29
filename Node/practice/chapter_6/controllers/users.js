import fs from 'fs';

//fetching data from the database
const data = JSON.parse(fs.readFileSync('data.json', 'utf8'));
const users = data.users;

const createUser = (req, res) => {
    const new_user = req.body; // req.body will be meaningful only if express.json() middleware is used otherwise undefined
    users.push(new_user);
    res.status(201).json({message: 'created successfully!'})
}

const getAllUsers = (req, res) => {
    console.log('fetching all users');
    res.status(200).json(users); // if data to be sent is more than one than it should be sent as an array; users will be an array
}

const getUser = (req, res) => {   
    const id = +req.params.id;    // req.params.id will be string by default; preadding + will make it int
    console.log("fetching single user");
    const user = users.find( p => p.id === id);
    res.status(200).json(user);
}

const updateUser = (req, res) => {
    const id = +req.params.id;
    const userIndex = users.findIndex(p => p.id === id);
    const user = users[userIndex];
    users.splice(userIndex, 1, { ... user, ...req.body}); // left spread opeator will overwrite right one
    res.status(200).json(users[userIndex]);
}

const replaceUser = (req, res) => {
    const id = +req.params.id;
    const userIndex = users.findIndex(p => p.id === id);
    const user = users[userIndex];
    users.splice(userIndex, 1, { id, ...req.body});
    res.status(200).json(users[userIndex]);
}

const deleteUser = (req, res) => {
    const id = +req.params.id;
    const userIndex = users.findIndex(p => p.id === id);
    const user = users[userIndex];
    users.splice(userIndex, 1);
    res.status(200).json(user);
}

export { createUser, getAllUsers, getUser, updateUser, replaceUser, deleteUser};