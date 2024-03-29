import { GETUSERACCOUNTFULFILLED, GETUSERACCOUNTFULREJECTED, GETUSERACCOUNTFULPENDING, INCREMENT, DECREMENT, INCREMENTBYAMOUNT, INCREMENTBONUS } from "../constants";


//Action creators
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