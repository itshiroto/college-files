import './App.css';
import { useState, useEffect } from "react";

import Header from './components/header';
import Questions from './components/questions.jsx'

import qlist from "./components/questions.json"

function App() {
  const [score, setScore] = useState(0);
  const [currQuestion, setCurrQuestion] = useState(0)
  const [countdown, setCountdown] = useState(150)
  const handleAnswers = (answers, correct) => {
    // TODO - handle the answer supaya berkaitan ke perhitungan poin
    const nextQuestion = currQuestion + 1;
    if (nextQuestion <= qlist.length) setCurrQuestion(nextQuestion);
    if (answers === correct) setScore(score + 1);
  }

  useEffect(() => {
    if (countdown === 0) return
    const timer = setInterval(() => {
      setCountdown(countdown - 1)
    }, 1000)

    return () => clearInterval(timer)
  }, [countdown])

  const FinalPage = ({ score, onClick }) => {
    return (
      <div className="finalpage">
        <div className="finalpage__title">
          <h1>Kuis telah selesai!</h1>
        </div>
        <div className="finalpage__content">
          <p>Skor: {score}</p>
        </div>
        <div className="finalpage__button">
          <button onClick={onClick}>Main lagi!</button>
        </div>
      </div>
    );
  }

  return (
    <div className="App">
      <Header countdown={countdown} setCountdown={setCountdown} />
      {countdown === 0 || currQuestion >= qlist.length ?

        <FinalPage
          score={score}
          onClick={() => { console.log("clicked"); setCountdown(10); setCurrQuestion(0); setScore(0) }}
        /> :

        <Questions
          questions={qlist}
          state={currQuestion}
          handleAnswers={handleAnswers}
        />
      }
    </div>
  );

}

export default App;
