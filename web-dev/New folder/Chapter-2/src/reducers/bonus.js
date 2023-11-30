import * as CONSTANTS from '../constants';

export default function reducer(state = { points: 0 }, action) {
    switch (action.type) {
      case CONSTANTS.INCREMENTBYAMOUNT:
        if (action.payload > 100) return { points: state.points + 1 };
      // break;
      case CONSTANTS.INCREMENTBONUS:
        return { points: state.points + 1 };
      default:
        return state;
    }
  }