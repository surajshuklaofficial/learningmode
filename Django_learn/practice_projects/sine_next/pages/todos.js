import axios from 'axios';

function Todos({ todos }) {
  return (
    <ul>
      {todos.map(todo => (
        <li key={todo.id}>{todo.title}</li>
      ))}
    </ul>
  );
}

export async function getServerSideProps() {
  const res = await axios.get('http://localhost:8000/api/todos/');
  const todos = res.data;
  return { props: { todos } };
}

export default Todos;
