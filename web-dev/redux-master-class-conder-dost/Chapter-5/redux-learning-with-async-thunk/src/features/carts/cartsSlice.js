import { createAsyncThunk, createSlice } from '@reduxjs/toolkit';
import { fetchItems, addItem, updateItem, deleteItem } from './cartsAPI';

const initialState = {
  items: [],
  status: 'idle',
};

export const fetchAsync = createAsyncThunk(
  'carts/fetchItems',
  async () => {
    const response = await fetchItems();
    return response.data;
  }
);

export const addAsync = createAsyncThunk(
  'carts/addItem',
  async (item) => {
    const response = await addItem(item);
    return response.data;
  }
);

export const deleteAsync = createAsyncThunk(
  'carts/deleteItem',
  async (id) => {
    await deleteItem(id);
    return id;
  }
);

export const updateAsync = createAsyncThunk(
  'carts/updateItem',
  async ({id, change: quantity}) => {
    const {data} = await updateItem(id, {quantity});
    return data;
  }
)

export const cartsSlice = createSlice({
  name: 'carts',
  initialState,
  reducers: {
  
  },
 
  extraReducers: (builder) => {
    builder
      .addCase(fetchAsync.pending, (state) => {
        state.status = 'loading';
      })
      .addCase(fetchAsync.fulfilled, (state, action) => {
        state.items = action.payload;
        state.status = 'idle';
      })
      .addCase(addAsync.fulfilled, (state, action) => {
        state.items.push(action.payload);
        state.status = 'idle';
      })
      .addCase(deleteAsync.fulfilled, (state, action) => {
        const index = state.items.find(item => item.id === action.payload);
        state.items.splice(index);
        state.status = 'idle';
      })
      .addCase(updateAsync.fulfilled, (state, action) => {
        state.status = 'idle';
      })
  },
});

export const {  } = cartsSlice.actions;
export default cartsSlice.reducer;
