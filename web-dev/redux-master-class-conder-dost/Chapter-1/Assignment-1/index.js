import { createStore, applyMiddleware, combineReducers } from "redux";
import axios from "axios";
import logger from 'redux-logger';
import thunk from "redux-thunk";
import {produce} from "immer";

// constants
const FETCH_POST = 'FETCH_POST';
const FETCH_POSTS = 'FETCH_POSTS';
const DELETE_POST = 'DELETE_POST';
const ADD_POST = 'ADD_POST';
const REQUEST_REJECTED = 'REQUEST_REJECTED';
const REQUEST_PENDING = 'REQUEST_PENDING';

// creating a store
const store = createStore(combineReducers({post: postReducer}), applyMiddleware(logger.default, thunk.default))

function postReducer(state={pending: false, posts: []}, action) {
    switch(action.type) {
        case FETCH_POST:
            // var posts = [...state.posts];
            // posts.push(action.payload);
            // return {...state, posts, pending: false};
            const nextState = produce(state, draftState => {
                draftState.posts.push(action.payload);
            })

            return nextState;
        case FETCH_POSTS:
            var posts = [...state?.posts, ...action?.payload].sort((a, b) => a.title.localeCompare(b.title));
            return {...state, posts, pending: true};
        case DELETE_POST:
            return {...state, posts: state?.posts?.filter(post => post.id != action.payload)};

        case REQUEST_PENDING:
            return {...state, pending: true};
        
        case REQUEST_REJECTED: 
            return {...state, error: action.error, pending: false};
        default:
            return state;
    }
}

// action creator
function fetchPostById(id) {
    return async (dispatch, getState) => {
        dispatch({type: REQUEST_PENDING});
        try {
            const {data} = await axios.get(`https://jsonplaceholder.typicode.com/posts/${id}`)
            dispatch({type: FETCH_POST, payload: data});
        } catch (error) {
            dispatch({type: REQUEST_REJECTED, error: error.message});
        }
    }
}

async function fetchPosts(dispatch, getState) {
    dispatch({type: REQUEST_PENDING});
    try {
        const {data} = await axios.get(`https://jsonplaceholder.typicode.com/posts`)
        dispatch({type: FETCH_POSTS, payload: data?.slice(0, 5)});
    } catch (error) {
        dispatch({type: REQUEST_REJECTED, error: error.message});
    }
}

function deletePost(id) {
    return {type: DELETE_POST, payload: id};
}
setTimeout(() => {
    store.dispatch(fetchPostById(5));
    store.dispatch(fetchPosts);
}, 1000)

setTimeout(() => {
    store.dispatch(deletePost(5));
}, 2000)

setTimeout(() => {

    console.log("................................");
    console.log(store.getState()?.post?.posts);
    console.log(".............");
}, 5000)