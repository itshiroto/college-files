import './questions.css'

export default function Main({ questions, state, handleAnswers }) {
  const Questions = ({ question, answer }) => {
    return (
      <div>
        <h3>{question}</h3>
        <div className="q-answerlist">
          {answer.list.map((item, index) => {
            return (
              <input type="button"
                name={index}
                value={item}
                key={index}
                className="q-answer-button"
                onClick={() => console.log(handleAnswers(item, answer.correct))}
              />
            )
          })}
        </div>
      </div>
    )
  }
  return (
    <div id="question-page">
      <Questions
        question={questions[state].question}
        answer={questions[state].answers}
      />
    </div>
  )
}

