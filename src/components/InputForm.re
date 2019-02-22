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
      <InputField
        value={email}
        placeholder="Enter your email"
        onInputText={onEmailInputText}
        type_ = "text"
      />
      <InputField
        value={password}
        placeholder="Enter password"
        type_ = "password"
        onInputText={onPasswordInputText}
      />
      <Button
        onClick={_ => onSubmit()}
        buttonText={str(buttonText)}
      />
      <p className="registrationTitle">{str(registrationTitle)}</p>
      <Button
        onClick={_ => onNavigation()}
        buttonText={str(navigationButtonText)}
      />
    </div>,
};