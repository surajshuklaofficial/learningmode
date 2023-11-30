import * as CONSTANTS from '../constants';
import { produce } from 'immer';

export default function reducer(state = { amount: 0, pending: false }, action) {
    switch (action.type) {
      case CONSTANTS.INCREMENT:
        const newState = produce(state, draftState => {
            draftState.amount++;
        })
        return newState;
      case CONSTANTS.INCREMENTBYAMOUNT:
        return { ...state, amount: state.amount + action.payload };

      case CONSTANTS.DECREMENTBYAMOUNT:
        const newAmount = state.amount - action.payload;
        if (newAmount < 0) return {...state, error: "You have reached limit!", pending: false}
        else return { ...state, amount:  newAmount, pending: false};

      case CONSTANTS.DECREMENT:
        return { ...state, amount: state.amount - 1 };
      case CONSTANTS.GETUSERACCOUNTFULFILLED:
        return { ...state, amount: action.payload, pending: false };
      case CONSTANTS.GETUSERACCOUNTFULPENDING:
          return { ...state, pending: true};
      case CONSTANTS.GETUSERACCOUNTFULREJECTED:
          return {...state, error: action.error, pending: false}
      default:
        return state;
    }
  }