import { createSlice } from '@reduxjs/toolkit'

const initialState = {
  points: 0,
}

export const bonusSlice = createSlice({
  name: 'bonus',
  initialState,
  reducers: {
    increment: (state) => {
      state.points += 1 //immer
    },
    decrement: (state) => {
      state.points -= 1
    },
  },
  extraReducers: (builders) => {
    builders
      .addCase('account/incrementByAmount', (state, action) => {
        if (action.payload >= 100) state.points++;
      })
  }
})

// Action creators are generated for each case reducer function
export const { increment, decrement } = bonusSlice.actions;

export default bonusSlice.reducer;