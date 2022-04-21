import './Card.css';

export default function Card(props) {
    return (
        <div className="card">
            <div className="card-title">
                <h2>{props.name}</h2>
            </div>
            <div className="card-img">
                <img src={props.imgURL} alt={props.name} />
            </div>
            <div className="card-desc">
                <p>{props.phone}</p>
                <p>{props.email}</p>
            </div>
        </div>
    );
}