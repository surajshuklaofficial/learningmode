import { createStore, applyMiddleware, combineReducers } from "redux";
import logger from "redux-logger";
import axios from "axios";
import thunk from "redux-thunk";

const history = [];

// action name constants
const INCREMENT = "ACCOUNT/INCREMENT";
const DECREMENT = "ACCOUNT/DECREMENT";
const INCREMENTBYAMOUNT = "ACCOUNT/INCREMENTBYAMOUNT";
// const INIT = "ACCOUNT/INIT";
const  GETUSERACCOUNTFULFILLED = 'GETUSERACCOUNTFULFILLED';
const  GETUSERACCOUNTFULPENDING = 'GETUSERACCOUNTFULPENDING';
const  GETUSERACCOUNTFULREJECTED = 'GETUSERACCOUNTFULREJECTED';
const INCREMENTBONUS = "BONUS/INCREMENT";

// store

const store = createStore(
  combineReducers({
    account: accountReducer,
    bonus: bonusReducer,
  }),
  applyMiddleware(logger.default, thunk.default)
);

// Note:
// 1. As soon as the store is created => the reducers will run once even though the middleware it will be one but when combineReducers are used then it running 3 times while creating

// reducer - a simple function that always returns a state
// function reducer (state={amount: 1}, action){
//     if (action.type === INCREMENT) {
//         // immutability: state should be immutable
//         // create a copy of state for each return
//         // do not change the previous state rather return a new Object

//         // do this
//         return {amount: state.amount + 1};

//         // not this
//         // state.amount = state.amount + 1;
//         // return state;
//     } else if (action.type === DECREMENT) {
//         return {amount: state.amount - 1};
//     } else if (action.type === INCREMENTBYAMOUNT) {
//         return {amount: state.amount + action.payload};
//     }

//     return state;
// }

function accountReducer(state = { amount: 0, pending: false }, action) {
  console.log("hi", state);
  switch (action.type) {
    case INCREMENT:
      return { amount: state.amount + 1 };
    case INCREMENTBYAMOUNT:
      return { amount: state.amount + action.payload };
    case DECREMENT:
      return { amount: state.amount - 1 };
    case GETUSERACCOUNTFULFILLED:
      return { ...state, amount: action.payload, pending: false };
    case GETUSERACCOUNTFULPENDING:
        return { ...state, pending: true};
    case GETUSERACCOUNTFULREJECTED:
        return {...state, error: action.error, pending: false}
    default:
      return state;
  }
}

function bonusReducer(state = { points: 0 }, action) {
  switch (action.type) {
    case INCREMENTBYAMOUNT:
      if (action.payload > 100) return { points: state.points + 1 };
    // break;
    case INCREMENTBONUS:
      return { points: state.points + 1 };
    default:
      return state;
  }
}
// global state
// console.log(store.getState());

// runs after the return of new state by reducer
// store.subscribe(() => {
//     history.push(store.getState());
//     console.log(history);
// })

//Action creators

// async function init(user) {
//     const {data} = await axios.get(`http://localhost:3000/accounts/${1}`)
//     // console.log(data);
//     return {type: INIT, payload: data.amount};
// }

function getUser(id) {
  return async (dispatch, getState) => {
    dispatch(getUserAccountPending());
    try {
        const { data } = await axios.get(`http://localhost:3000/accounts/${id}`);
        dispatch(getUserAccountFulfilled(data.amount));

    } catch(error) {
        dispatch(getUserAccountRejected(error.message));
    }
  };
}
// function getUser(id) {
//   return async (dispatch, getState) => {
//     const { data } = await axios.get(`http://localhost:3000/accounts/${id}`);
//     dispatch(init(data.amount));
//   };
// }

function getUserAccountFulfilled(amount) {
  return { type: GETUSERACCOUNTFULFILLED, payload: amount };
}
function getUserAccountRejected(error) {
  return { type: GETUSERACCOUNTFULREJECTED, error: error};
}
function getUserAccountPending() {
  return { type: GETUSERACCOUNTFULPENDING};
}

function increment() {
  return { type: INCREMENT };
}

function decrement() {
  return { type: DECREMENT };
}

function incrementByAmount(value) {
  return { type: INCREMENTBYAMOUNT, payload: value };
}

function incrementBonus() {
  return { type: INCREMENTBONUS };
}
setTimeout(() => {
  store.dispatch(getUser(2));
  // store.dispatch(incrementByAmount(200));
  // store.dispatch(init(1));
  // store.dispatch(incrementBonus());
}, 2000);
