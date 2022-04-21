import "./header.css"

export default function Header({ countdown, setCountdown }) {
  const timeLeft = (seconds) => {
    const minutes = Math.floor(seconds / 60)
    const secs = seconds % 60
    return `${minutes}:${secs < 10 ? '0' : ''}${secs}`
  }

  const Countdown = () => {
    return (
      <div className="countdown">
        <p>{countdown > 0 ? timeLeft(countdown) : 'Time is up!'}</p>
      </div>
    )
  }

  return (
    <header id="header">
      {/* LOGO HERE */}

      <Countdown />

    </header>
  );
}