import './Card.css'

export default function Card({ emoji, name, meaning }) {
  return (
    <div className="card">
      <h2 className="card-emoji">{emoji}</h2>
      <h3 className="card-name">{name}</h3>
      <p className="card-meaning">{meaning}</p>
    </div>
  )
}