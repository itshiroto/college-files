import Card from './components/Card'
import emojipedia from './data/emoji'
import './App.css'

const Header = () => {
  return (
    <header>
      <h1 className="header-title">emojipedia</h1>
    </header>
  )
}

function App() {
  return (
    <div className="App">
      <Header />
      <div className="card-container">
        {emojipedia.map(emoji => {
          return (
            <Card key={emoji.id}
              emoji={emoji.emoji}
              name={emoji.name}
              meaning={emoji.meaning}
            />
          )
        })}
      </div>

    </div>
  )
}

export default App
