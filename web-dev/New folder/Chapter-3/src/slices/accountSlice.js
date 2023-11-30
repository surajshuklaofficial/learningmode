import { createAsyncThunk, createSlice } from '@reduxjs/toolkit'
import axios from 'axios';

const initialState = {
    amount: 100,
}

export const fetchUserAccount = createAsyncThunk(
  'account/getUser',
  async (id, thunkAPI) => {
    try {
      const {data} = await axios.get(`http://localhost:8080/account/${id}`);
      return data.amount;
    } catch (error) {
      return error.message;
    }
  }
)

export const accountSlice = createSlice({
  name: 'account',
  initialState,
  reducers: {
    increment: (state) => {
      state.amount += 1;
    },
    decrement: (state) => {
      state.amount -= 1;
    },
    incrementByAmount: (state, action) => {
      state.amount += action.payload;
    },
  },
  extraReducers: (builders) => {
    builders
      .addCase(fetchUserAccount.fulfilled, (state, action) => {
        state.amount = action.payload;
        console.log("fadfa");
        state.pending = false;
      })
      .addCase(fetchUserAccount.pending, (state) => {
        state.pending = true;
      })
      .addCase(fetchUserAccount.rejected, (state, action) => {
        console.log("running")
        state.pending = false;
        state.error = action.payload.error;
      })
  }
})

// Action creators are generated for each case reducer function
export const { increment, decrement, incrementByAmount } = accountSlice.actions;

export default accountSlice.reducer;