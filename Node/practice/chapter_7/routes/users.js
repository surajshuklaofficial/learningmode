import express from 'express';

import { createUser, getAllUsers, getUser, updateUser, replaceUser, deleteUser} from '../controllers/users.js';

const router = express.Router();

// chaining of server object is possible
router.post('/', createUser)
    .get('/', getAllUsers)
    .get('/:id', getUser)
    .patch('/id', updateUser)
    .put('/:id', replaceUser)
    .delete('/:id', deleteUser);

export default router;