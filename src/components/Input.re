let str = ReasonReact.string;
// define stateless component named Input
let component = ReasonReact.statelessComponent("Input");

let make = (~value, ~onInputText, ~submit, _children) => {
  ...component,
  render: _self =>
    <div className="input">
      <InputField
        value
        placeholder = "Enter item"
        onInputText
        type_ = "text"
      />
      <Button
        onClick = {_ => submit()}
        buttonText={str("Add")}
      />
    </div>,
};