import { useAddAccountMutation, useDeleteAccountMutation, useGetAccountsQuery, useUpdateAccountMutation } from "../api/adminSlice";

function Admin() {

  const {data, error, isLoading} = useGetAccountsQuery();
  const [addAccount, response ] = useAddAccountMutation();
  const [deleteAccount, res] = useDeleteAccountMutation();
  const [updateAccount] = useUpdateAccountMutation();

  return (
    <div className="card">
      <div className="container">
        <h4>
          <b>admin Component</b>
        </h4>
        {
          data && data.map(account => 
            <p key={account.id}>
              {account.id} : {account.amount}
              <button onClick={() => deleteAccount(account.id)}>Delete Account</button>
              <button onClick={() => updateAccount({id: account.id, amount: 7787})}>Update Account</button>
            </p>)
        }
        <button onClick={() => addAccount(101, data.length + 1)}>Add Account</button>
      </div>
    </div>
  );
}

export default Admin;
