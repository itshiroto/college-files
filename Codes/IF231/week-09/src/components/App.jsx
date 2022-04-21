import Contacts from "../contact";
import Card from "./Card";
import './App.css'

function App() {
  return (
    <div id="App">
      <h1>My Contacts</h1>
      <div id="cards">
        {Contacts.map(val => <Card {...val} />)}
      </div>
    </div>
  );
}

export default App;
