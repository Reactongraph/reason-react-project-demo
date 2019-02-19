let str = ReasonReact.string;
// define stateless component named Input
let component = ReasonReact.statelessComponent("InputForm");

let make = (
  ~email,
  ~password,
  ~onEmailInputText,
  ~onPasswordInputText,
  ~onSubmit,
  ~buttonText,
  ~navigationButtonText,
  ~onNavigation,
  ~registrationTitle,
  _children
  ) => {
  ...component,
  render: _self =>
    <div className="input">
      <input
        value={email}
        placeholder="Enter your email"
        onChange={event =>
          onEmailInputText(
            ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value,
          )
        }
      />
      <input
        value={password}
        placeholder="Enter password"
        type_ = "password"
        onChange={event =>
          onPasswordInputText(
            ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value,
          )
        }
      />
      <button onClick={_ => onSubmit()}> {str(buttonText)} </button>
      <p className="registrationTitle">{str(registrationTitle)}</p>
      <button onClick={_ => onNavigation()}> {str(navigationButtonText)} </button>
    </div>,
};