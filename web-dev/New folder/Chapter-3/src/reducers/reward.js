import { createAction, createReducer } from '@reduxjs/toolkit'

export const increment = createAction('reward/increment')
export const decrement = createAction('reward/decrement')
export const incrementByAmount = createAction('reward/incrementByAmount')

const initialState = { points: 0 }

const rewardReducer = createReducer(initialState, (builder) => {
  builder
    .addCase(increment, (state) => {
      state.points++
    })
    .addCase(incrementByAmount, (state, action) => {
      state.points += action.payload;
    })
})

export default rewardReducer;