import { combineReducers } from 'redux';

import accountReducer from './account';
import bonusReducer from './bonus';

export default combineReducers({account: accountReducer, bonus: bonusReducer});
